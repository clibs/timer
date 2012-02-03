
#include <stdio.h>
#include <unistd.h>
#include "../timer.h"

int main ()
{
	struct timert timer;
	
	timer_start (&timer);

	usleep (1e6);
	
	timer_stop (&timer);
	
	printf ("Delta: %f\n", timer_delta (&timer));
	
	return 0;
}
