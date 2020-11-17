#ifndef TIME_H
#define TIME_H
  class Time{
    int hour, minute, second;
    public:
      Time();
      Time(int);
      Time(int, int, int);
      int get_hour();
      int get_minute();
      int get_second();
      void setTime(int elapseTime);
  };
#endif