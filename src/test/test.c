
#include <stdio.h>
#include <unistd.h>
#include "../timer.h"

int main ()
{
  timer_s timer;

  timer_start(&timer);
  printf("Timer started\n");

  usleep(1e6);

  timer_pause(&timer);
  printf("Timer stopped\n");

  printf("Delta:\n"
		 "microsseconds...%ld\n"
		 "seconds.........%ld\n"
		 "minutes.........%ld\n"
		 "hours...........%ld\n", timer_delta_ms(&timer),
								timer_delta_s(&timer),
								timer_delta_m(&timer),
								timer_delta_h(&timer));

  return 0;
}
