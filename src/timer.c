/** @file timer.c
 *
 *  Definition of the timer functions.
 */

#include <stdio.h>
#include <time.h>
#include "timer.h"

/** Uses clock_gettime() to mark the number of seconds and nanoseconds
 *  between the Epoch and now.
 *
 *  Local function
 */
static int get_time (struct timespec* tv)
{
  return clock_gettime(CLOCK_REALTIME, tv);
}

/** Records the current time as a start point.
 *
 *  Remember to call timer_stop() to record the diff.
 */
int timer_start (timer_s* t)
{
  return get_time(&(t->start));
}

/** Records the current time as a stop point.
 *
 *  Remember to call timer_delta() to retrieve the timer diff.
 */
int timer_stop (timer_s* t)
{
  return get_time(&(t->end));
}

/** Returns the delta between the start and end of the timer.
 *
 *  @note If timer_start() and timer_stop() doesn't get called
 *        before this, the results are unpredictable.
 */
long timer_delta_nseconds (timer_s* t)
{
  long delta_sec  = (t->end.tv_sec) - (t->start.tv_sec);
  long delta_nsec = (t->end.tv_nsec - t->start.tv_nsec);

  return (delta_sec * 1e9 + delta_nsec);
}

 /** Returns the time diff in microseconds (1/1000000 seconds) */
long timer_delta_useconds (timer_s* t)
{
	return timer_delta_nseconds(t) / 1e3;
}

 /** Returns the time diff in mili (1/1000 seconds) */
long timer_delta_mseconds(timer_s* t)
{
	return timer_delta_useconds(t) / 1e3;
}

 /** Returns the time diff in seconds */
long timer_delta_seconds(timer_s* t)
{
	return timer_delta_useconds(t) / 1e6;
}

