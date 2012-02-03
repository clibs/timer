/** @file timer.c
 *
 *  Definition of the timer functions.
 */

#include <stdio.h>
#include <sys/time.h>
#include "timer.h"



/** Returns the delta between the start and end of the timer.
 *
 *  @note If timer_start() and timer_stop() doesn't get called
 *        before this, the results are unpredictable.
 */


/** Returns the difference between the start and the end points of 't'.
 */
float timer_delta (struct timert* t)
{
	float delta = (((float)t->end.tv_sec + (float)(t->end.tv_usec/1000000)) - ((float)t->start.tv_sec + ((float)t->start.tv_usec/10000000)));

	return delta;
}


/** Records the current time as a start point.
 *
 *  Remember to call timer_stop() to record the diff.
 */
int timer_start (struct timert* t)
{
	return gettimeofday (&(t->start), NULL);
}



/** Records the current time as a stop point.
 *
 *  Remember to call timer_delta() to retrieve the timer diff.
 */
int timer_stop (struct timert* t)
{
	return gettimeofday (&(t->end), NULL);
}


