/** timer.h
 *  Microsecond timer in C, using `gettimeofday()`.
 *
 *  Note: `gettimeofday()` is Unix, GNU/Linux and
 *        Mac OS X system-specific.
 *
 *        The only portable function is time.h's `clock()`,
 *        but it isn't very precise.
 *
 *        See: http://www.songho.ca/misc/timer/timer.html
 *
 *  Copyright (c) 2011,2013 Alexandre Dantas <eu@alexdantas.net>
 */

#ifndef TIMER_H_DEFINED
#define TIMER_H_DEFINED

#include <stdio.h>
#include <sys/time.h>			/* gettimeofday() */
#include <stdbool.h>			/* bool */

typedef struct timer_t
{
	suseconds_t start_mark; 	/* Timer start point */
	suseconds_t pause_mark; 	/* In case we pause the timer */
	bool running;				/* Is it running? */
	bool paused;				/* Is it paused? */

} timer_t;

/** Starts the timer.
 *
 *  @note If called multiple times, restarts the timer.
 */
void timer_start(timer_t* t);

/** Pauses the timer.
 *
 *  @note If called multiple times, it does nothing.
 */
void timer_pause(timer_t* t);

/** Unpauses the timer.
 *
 *  @note If the timer's not paused or this is called
 *        multiple times, it does nothing.
 */
void timer_unpause(timer_t* t);

/** Returns the time difference in microseconds
 *
 * @note (1/1000000 seconds)
 */
suseconds_t timer_delta_us(timer_t* t);

/** Returns the time difference in miliseconds.
 *
 * @note (1/1000 seconds)
 */
long timer_delta_ms(timer_t* t);

/** Returns the time difference in seconds. */
long timer_delta_s(timer_t* t);

/** Returns the time difference in minutes (60 seconds). */
long timer_delta_m(timer_t* t);

/** Returns the time difference in hours (3600 seconds). */
long timer_delta_h(timer_t* t);

#endif

