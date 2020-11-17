#include <iostream>
#include "time.h"
using namespace std;

int main(){
Time t;
cout << "Current hour: " << t.get_hour() << ":" << t.get_minute() << ":" << t.get_second() << endl;
Time t2(555550);
cout << "For 555550 -> hour: " << t2.get_hour() << ":" << t2.get_minute() << ":" << t2.get_second() << endl;

return 0;
}