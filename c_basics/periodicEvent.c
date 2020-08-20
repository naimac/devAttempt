#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define LOG_TRIGGER_TIME (5)

static const time_t startTime;
static int first = 0;
// time(&startTime);
// struct tm *startInfo;
// static const int startTotalSec = startInfo->tm_hour * 60 * 60;

void func(void)
{
	printf("coco\n");
}

int main()
{
	time_t rawtime;

	struct tm *timeinfo;
	int currentTimeSec = 0;

	if (first == 0)
	{
		first = 1;
		struct tm *start_timeinfo = localtime(&startTime);
		int start_hour = start_timeinfo->tm_hour;
		int start_TotalSec = start_timeinfo->tm_hour * 60 * 60;
	}

	while (1)
	{
		time(&rawtime);

		timeinfo = localtime(&rawtime);

		currentTimeSec = timeinfo->tm_hour * 60 * 60;

		timeinfo = localtime(&rawtime);

		sleep(LOG_TRIGGER_TIME);
		printf("Starter local time and date: %s", asctime(timeinfo));
		printf("Current local time and date: %s", asctime(timeinfo));
	}

	return 0;
}