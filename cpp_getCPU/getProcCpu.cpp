#include <stdio.h> // printf
#include <unistd.h> // fork, execve
#include <sys/resource.h>
#include <thread>
#include <iostream>
#include <chrono>
#include <cstdlib> // std::atoi

// #include <crt_externs.h>

extern char** environ;

//Last modified: 18/11/12 19:13:35(CET) by Fabian Holler
#include <stdlib.h> 
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct pstat {
    long unsigned int utime_ticks;
    long int cutime_ticks;
    long unsigned int stime_ticks;
    long int cstime_ticks;
    long unsigned int vsize; // virtual memory size in bytes
    long unsigned int rss; //Resident  Set  Size in bytes

    long unsigned int cpu_total_time;
};

/*
 * read /proc data into the passed struct pstat
 * returns 0 on success, -1 on error
*/
int get_usage(const pid_t pid, struct pstat* result) {
    //convert  pid to string
    char pid_s[20];
    snprintf(pid_s, sizeof(pid_s), "%d", pid);
    char stat_filepath[30] = "/proc/"; strncat(stat_filepath, pid_s,
            sizeof(stat_filepath) - strlen(stat_filepath) -1);
    strncat(stat_filepath, "/stat", sizeof(stat_filepath) -
            strlen(stat_filepath) -1);

    FILE *fpstat = fopen(stat_filepath, "r");
    if (fpstat == NULL) {
        perror("FOPEN ERROR ");
        return -1;
    }

    FILE *fstat = fopen("/proc/stat", "r");
    if (fstat == NULL) {
        perror("FOPEN ERROR ");
        fclose(fstat);
        return -1;
    }

    //read values from /proc/pid/stat
    bzero(result, sizeof(struct pstat));
    long int rss;
    if (fscanf(fpstat, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %lu"
                "%lu %ld %ld %*d %*d %*d %*d %*u %lu %ld",
                &result->utime_ticks, &result->stime_ticks,
                &result->cutime_ticks, &result->cstime_ticks, &result->vsize,
                &rss) == EOF) {
        fclose(fpstat);
        return -1;
    }
    fclose(fpstat);
    result->rss = rss * getpagesize();

    //read+calc cpu total time from /proc/stat
    long unsigned int cpu_time[10];
    bzero(cpu_time, sizeof(cpu_time));
    if (fscanf(fstat, "%*s %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
                &cpu_time[0], &cpu_time[1], &cpu_time[2], &cpu_time[3],
                &cpu_time[4], &cpu_time[5], &cpu_time[6], &cpu_time[7],
                &cpu_time[8], &cpu_time[9]) == EOF) {
        fclose(fstat);
        return -1;
    }

    fclose(fstat);

    for(int i=0; i < 10;i++)
        result->cpu_total_time += cpu_time[i];

    return 0;
}

/*
* calculates the elapsed CPU usage between 2 measuring points. in percent
*/
void calc_cpu_usage_pct(const struct pstat* cur_usage,
                        const struct pstat* last_usage,
                        double* ucpu_usage, double* scpu_usage)
{
    const long unsigned int total_time_diff = cur_usage->cpu_total_time -
                                              last_usage->cpu_total_time;

	int		l_core_count = sysconf(_SC_NPROCESSORS_CONF);

    std::cout << "l_core_count [" << l_core_count << "]" << std::endl;

    *ucpu_usage = l_core_count * 100 * (((cur_usage->utime_ticks + cur_usage->cutime_ticks)
                    - (last_usage->utime_ticks + last_usage->cutime_ticks))
                    / (double) total_time_diff);

    *scpu_usage = l_core_count * 100 * ((((cur_usage->stime_ticks + cur_usage->cstime_ticks)
                    - (last_usage->stime_ticks + last_usage->cstime_ticks))) /
                    (double) total_time_diff);
}

/*
* calculates the elapsed CPU usage between 2 measuring points in ticks
*/
void calc_cpu_usage(const struct pstat* cur_usage,
                    const struct pstat* last_usage,
                    long unsigned int* ucpu_usage,
                    long unsigned int* scpu_usage)
{

    *ucpu_usage = (cur_usage->utime_ticks + cur_usage->cutime_ticks) -
                  (last_usage->utime_ticks + last_usage->cutime_ticks);

    *scpu_usage = (cur_usage->stime_ticks + cur_usage->cstime_ticks) -
                  (last_usage->stime_ticks + last_usage->cstime_ticks);
}

int		main(int argc, char **argv)
{
	pid_t		l_pid;

	if (argc == 2)
	{
		l_pid = std::atoi(argv[1]);
	}
	else
	{
		l_pid = fork();

		if (l_pid == -1)
		{
			printf("fork fail\n");
			return 1;
		}
		else
		{
			if (l_pid == 0)
			{
				printf("child process ! \n");

				char *l_param[] = {"./a.out", "", NULL};
				int l_ret = execve(l_param[0], l_param, environ);

				if (l_ret == -1)
				{
					printf("exeve failed\n");
				}
			}
		}
	}

	struct pstat	l_last_usage;
	get_usage(l_pid, &l_last_usage);

	std::this_thread::sleep_for(std::chrono::seconds(1));

	struct pstat	l_current_usage;
	get_usage(l_pid, &l_current_usage);

	double	l_ucpu_usage;
	double	l_scpu_usage;

	calc_cpu_usage_pct(&l_current_usage, &l_last_usage, &l_ucpu_usage, &l_scpu_usage);

	std::cout << "ucpu_usage [" << l_ucpu_usage << "] | l_scpu_usage [" << l_scpu_usage  << "]" << std::endl;

	return 0;
}