#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define LOG_TRIGGER_TIME (5)

// EXAMPLE
/*
time_t my_time;
struct tm * timeinfo; 
time (&my_time);
timeinfo = localtime (&my_time);
CCLog("year->%d",timeinfo->tm_year+1900);
CCLog("month->%d",timeinfo->tm_mon+1);
CCLog("date->%d",timeinfo->tm_mday);
CCLog("hour->%d",timeinfo->tm_hour);
CCLog("minutes->%d",timeinfo->tm_min);
CCLog("seconds->%d",timeinfo->tm_sec);
*/

static time_t startTime;
static int first = 1;
static int startTimeSec = 0;
// time(&startTime);
// struct tm *startInfo;
// static const int startTotalSec = startInfo->tm_hour * 60 * 60;

void func(void)
{
	printf("coco\n");
}

int main()
{
	if (first == 1)
	{
		first = 0;
		time(&startTime);
		struct tm *start_timeinfo = localtime(&startTime);
		// printf("Starter local time and date: %s", asctime(start_timeinfo));
		// int start_hour = start_timeinfo->tm_hour;
		// startTimeSec = start_hour * 60 * 60;
		startTimeSec = start_timeinfo->tm_sec;
		printf("Starter time in seconds : %d\n", startTimeSec);
	}

	time_t rawtime;
	struct tm *timeinfo;
	int currentTimeSec = 0;

	while (1)
	{
		// recuperation heure en cours
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		// printf("CURRENT local time and date: %s", asctime(timeinfo));
		currentTimeSec = timeinfo->tm_sec;

		if (!first)
		{
			sleep(LOG_TRIGGER_TIME);
		}
		printf("Starter time in seconds : %d\n", startTimeSec);
		printf("Current time in seconds : %d\n", currentTimeSec);
	}

	return 0;
}