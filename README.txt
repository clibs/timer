================================================================================
                               arguments README
================================================================================

A module that implements a simple timer in C using clock_gettime().
It was made as a wrap-up that could easily be edited to suit every project's
needs.
You can test it by exploring the test/test.c file and then 'make run'.

--------------------------------------------------------------------------------
What it Does
--------------------------------------------------------------------------------

It marks the current time at different parts of the program and then calculates
the difference between them - the delta.
You can use it to mark how much time has passed between calls, or to wait for
a specified time ammount and then do something.

--------------------------------------------------------------------------------
How to Use
--------------------------------------------------------------------------------

1) Copy timer.c and timer.h to your project source folder.

2) Include arguments.h on your program, create a 'struct timert' and call
   the functions described in arguments.c on it.

3) Remember to link your project with '-lrt' (to link real-time libraries).

4) Master time and space.

--------------------------------------------------------------------------------
Example
--------------------------------------------------------------------------------

// In this example, i'll use the timer to check the precision of the
// usleep() function.
// I'll start a timer, use usleep() and then stop the timer.

    #include <stdio.h>
    #include <unistd.h>
    #include "../timer.h"

    int main ()
    {
      struct timert timer; // Declaring the timer

      timer_start (&timer);
      printf ("Timer started\n");

      usleep (1e6);        // Sleeping for 10^6 microseconds (1 second)

      timer_stop (&timer);
      printf ("Timer stopped\n");

      printf ("Delta: %f seconds\n", timer_delta (&timer));

      return 0;
    }

--------------------------------------------------------------------------------
About
--------------------------------------------------------------------------------

These modules were coded by Alexandre Dantas <alex.dantas92@gmail.com>.
Any questions, requests, bugs, messages, etc. e-mail me.

These files are not licensed in any way, so you can do whatever you
want with them.
But if you use it i appreciate any comments :)

Oh, and check my other projects!
Please visit my blog: alexdantasblog.wordpress.com

================================================================================
================================================================================
