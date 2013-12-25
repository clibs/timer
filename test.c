#include <stdio.h>
#include <unistd.h>				/* usleep */
#include "src/timer.h"

int main(int argc, char* argv[])
{
	timer_t timer;
	timer_start(&timer);

	printf("Timer started\n");

	usleep(1e6);
	timer_pause(&timer);

	printf("Delta (us): %ld\n", timer_delta_us(&timer));
	printf("Delta (ms): %ld\n", timer_delta_ms(&timer));
	timer_unpause(&timer);

	usleep(1e4);
	timer_pause(&timer);

	printf("Delta (us): %ld\n", timer_delta_us(&timer));
	printf("Delta (ms): %ld\n", timer_delta_ms(&timer));

	return 0;
}

