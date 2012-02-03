
#include <stdio.h>
#include <unistd.h>
#include "../timer.h"

int main ()
{
  struct timert timer;

  timer_start (&timer);
  printf ("Timer started\n");

  usleep (1e6);

  timer_stop (&timer);
  printf ("Timer stopped\n");

  printf ("Delta: %f seconds\n", timer_delta (&timer));

  return 0;
}
