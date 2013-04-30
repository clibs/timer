timer README
============

A module that implements a simple timer in C using gettimeofday().
It was made as a wrap-up that could easily be edited to suit every
project's needs.
Has precision up to microseconds, going through mili, seconds and up.

What it does
------------

It marks the current time at different parts of the program and then calculates
the difference between them - the delta.
You can use it to mark how much time has passed between calls, or to wait for
a specified time ammount and then do something.
Also, it supports pausing and unpausing, so you can take your time :)

How to Use
----------

1. Copy timer.c and timer.h to your project source folder.

2.	Include timer.h on your program
2.1 Create a 'timer_s'
2.2 Call the functions described in timer.h on it.

3. ???

4. PROFIT!!

Example
-------

You can test it by doing 'make run' or exploring the test/test.c file.

About
-----

This was written by Alexandre Dantas <alex.dantas92@gmail.com>.
Any questions, requests, bugs, messages, etc. e-mail me.

These files are not licensed in any way, so you can do whatever you
want with them. Consider them public domain.

If you ever use them, it wouldn't hurt to send me any comments :)

Oh, and check my other projects!
Visit me at: http://www.alexdantas.net/projects/

