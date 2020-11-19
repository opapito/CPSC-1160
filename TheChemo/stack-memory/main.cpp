#include <iostream>
#include <string>

struct Vector3
{
  float x, y, z;

  Vector3()
    : x(10), y(11), z(12){}
};


int main()
{
  // stack
  int value = 5; 
  int arr [5];
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;
  arr[3] = 4;
  arr[4] = 5;
  std::cout << arr[0] << value << std::endl;
  Vector3 vector;

  //heap
  int* hvalue = new int;
  *hvalue = 5;
  int* harray = new int[5];
  harray[0] = 1;
  harray[1] = 2;
  harray[2] = 3;
  harray[3] = 4;
  harray[4] = 5;
  
  Vector3* hvector = new Vector3;

  delete hvalue;
  delete hvector;
  delete harray;


  return 0;
}
