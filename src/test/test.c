
#include <stdio.h>
#include <unistd.h>
#include "../timer.h"

int main ()
{
  timer_s timer;

  timer_start(&timer);
  printf("Timer started\n");

  usleep(1e6);

  timer_stop(&timer);
  printf("Timer stopped\n");

  printf("Delta:\n"
		 "nanoseconds:  %ld\n"
		 "microseconds: %ld\n"
		 "miliseconds:  %ld\n"
		 "seconds:      %ld\n", timer_delta_nseconds(&timer),
		                        timer_delta_useconds(&timer),
		                        timer_delta_mseconds(&timer),
		                        timer_delta_seconds(&timer));

  return 0;
}
