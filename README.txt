timer README
============

A module that implements a simple timer in C using clock_gettime().
It was made as a wrap-up that could easily be edited to suit every
project's needs.
Has precision up to nanoseconds, going through micro, mili and seconds.

You can test it by doing 'make run' or exploring the test/test.c file.

What it does
------------

It marks the current time at different parts of the program and then calculates
the difference between them - the delta.
You can use it to mark how much time has passed between calls, or to wait for
a specified time ammount and then do something.


How to Use
----------

1) Copy timer.c and timer.h to your project source folder.

2) Include timer.h on your program, create a timer_s' and call
   the functions described in timer.c on it.

3) Remember to link your project with '-lrt' (to link real-time libraries).

4) ???

5) PROFIT!!


Example
-------

// In this example, i'll use the timer to check the precision of the
// usleep() function.
// I'll start a timer, use usleep() and then stop the timer.

    #include <stdio.h>
    #include <unistd.h>
    #include "timer.h"

    int main ()
    {
      timer_s timer; // Declaring the timer

      timer_start(&timer);
      printf("Timer started\n");

      usleep (1e6);        // Sleeping for 10^6 microseconds (1 second)

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


About
-----

This was written by Alexandre Dantas <alex.dantas92@gmail.com>.
Any questions, requests, bugs, messages, etc. e-mail me.

These files are not licensed in any way, so you can do whatever you
want with them. Consider them public domain.

If you ever use them, it wouldn't hurt to send me any comments :)

Oh, and check my other projects!
Visit me at: http://www.alexdantas.net/projects/

