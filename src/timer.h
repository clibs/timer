/** @file timer.h
 *	Defines stuff related to the timer.
 *
 *	Basically, it starts a timer and can return a delta from that
 *	point on.
 *
 *	You can also pause the timer and unpause it anytime.
 *
 *	How-to-use:
 *
 *	timer_s timer;
 *	start_timer(&timer);
 *	...
 *	unsigned int delta = timer_delta_us(&timer);
 *	...
 *	pause_timer(&timer);
 *	delta = timer_delta_s(&timer);
 *	unpause_timer(&timer);
 *	...
 *
 *	This module uses gettimeofday().
 *	It is Unix, GNU/Linux and Mac OS X system-specific.
 *	The only portable function is time.h's clock(), but it isn't very precise.
 *	See: http://www.songho.ca/misc/timer/timer.html
 */

#ifndef TIMER_H_DEFINED
#define TIMER_H_DEFINED

#include <stdio.h>
#include <sys/time.h>
#include <stdbool.h>

/** The timer structure */
typedef struct timer_s
{
	suseconds_t start_mark; /**< The timer start point */
	suseconds_t pause_mark; /**< In case we pause the timer */
	bool running;
	bool paused;
} timer_s;

/** Starts the timer.
 *	@note If called multiple times, restarts the timer.
 */
void timer_start(timer_s* t);

/** Pauses the timer.
 *	@note If called multiple times, it does nothing.
 */
void timer_pause(timer_s* t);

/** Unpauses the timer.
 *	@note If the timer's not paused or this is called multiple times,
 *	it does nothing.
 */
void timer_unpause(timer_s* t);

/** Returns the time difference in microseconds (1/1000000 seconds). */
long timer_delta_us(timer_s* t);

 /** Returns the time difference in mili (1/1000 seconds). */
long timer_delta_ms(timer_s* t);

/** Returns the time difference in seconds. */
long timer_delta_s(timer_s* t);

/** Returns the time difference in minutes (60 seconds). */
long timer_delta_m(timer_s* t);

/** Returns the time difference in hours (3600 seconds). */
long timer_delta_h(timer_s* t);

#endif

