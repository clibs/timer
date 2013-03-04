/** @file timer.h
 *  Declaration of the timer structure and functions.
 *
 *  Start the timer by calling timer_start() and set its delay
 *  by giving it to timer_set_delay().
 *  The main use of this module is to compare the timer (through timer_delta())
 *  with the delay (returned by timer_get_delay()). Remember to call
 *  timer_stop() often!
 *
 *  gettimeofday() is Unix, GNU/Linux and Mac OS X system-specific.
 *  The only portable function is time.h's clock(), but it isn't very precise.
 *  <a href="http://www.songho.ca/misc/timer/timer.html"> Here's the source </a>.
 */

#ifndef TIMER_H_DEFINED
#define TIMER_H_DEFINED

#include <time.h>


/* For more info, check 'man clock_gettime'
 *
 * The 'struct timespec' is defined like this:
 *
 *  struct timespec {
 *      time_t tv_sec;      <- seconds
 *      long   tv_nsec;     <- nanoseconds
 *  };
 *
 */

/** The timer structure */
typedef struct timer_s
{
  struct timespec start; /**< The timer start point */
  struct timespec end;   /**< The timer stop point */
} timer_s;

int  timer_start(timer_s* t);
int  timer_stop(timer_s* t);
long timer_delta_nseconds(timer_s* t);
long timer_delta_useconds(timer_s* t);
long timer_delta_mseconds(timer_s* t);
long timer_delta_seconds(timer_s* t);

#endif

