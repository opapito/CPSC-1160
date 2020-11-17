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
