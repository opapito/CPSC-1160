/*
9.5 (The Time class) Design a class named Time. The class contains:

Data fields hour, minute, and second that represent a time.

A no-arg constructor that creates a Time object for the current time.

A constructor that constructs a Time object with a specified elapse time since the middle of night, Jan 1, 1970, in seconds.

A constructor that constructs a Time object with the specified hour, minute, and second.

Three getter functions for the data fields hour, minute, and second.

A function named setTime(int elapseTime) that sets a new time for the object using the elapsed time.

Draw the UML diagram for the class. Implement the class. Write a test program that creates two Time objects, one using a no-arg constructor and the other using Time(555550), and display their hour, minute, and second.

(Hint: The first two constructors will extract hour, minute, and second from the elapse time. For example, if the elapse time is 555550 seconds, the hour is 10, the minute is 19, and the second is 10. For the no-arg constructor, the current time can be obtained using time(0), as shown in Listing 2.9, ShowCurrentTime.cpp.)
*/

#include <ctime>
#include "time.h"

void Time::setTime(int elapsedTime){
   // Compute the current second in the minute in the hour
   int currentSecond = elapsedTime % 60;
 
   // Obtain the total minutes
   int totalMinutes = elapsedTime / 60;
 
   // Compute the current minute in the hour
   int currentMinute = totalMinutes % 60;
 
   // Obtain the total hours
   int totalHours = totalMinutes / 60;
 
   // Compute the current hour
   int currentHour = totalHours % 24;

   hour = currentHour;
   minute = currentMinute;
   second = currentSecond;
}

Time::Time(){
  setTime(time(0));
}

Time::Time(int elapseTime){
  setTime(elapseTime);
}

Time::Time(int h, int m, int s){

   hour = h;
   minute = m;
   second = s;
}

int Time::get_second(){
  return second;
}

int Time::get_minute(){
  return minute;
}

int Time::get_hour(){
  return hour;
}
