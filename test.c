#include <stdio.h>
#include <unistd.h>				/* usleep */
#include "src/timer.h"

int main()
{
	timer_t timer;
	printf("Timer started\n");

	timer_start(&timer);
	usleep(1e6);
	timer_pause(&timer);

	printf("Delta (us): %ld\n", timer_delta_us(&timer));
	printf("Delta (ms): %ld\n", timer_delta_ms(&timer));
	printf("That should be around 1 second\n\n");

	timer_unpause(&timer);
	usleep(5e5);
	timer_pause(&timer);

	printf("Delta (us): %ld\n", timer_delta_us(&timer));
	printf("Delta (ms): %ld\n", timer_delta_ms(&timer));
	printf("And that should add to 1.5 seconds\n\n");

	return 0;
}

