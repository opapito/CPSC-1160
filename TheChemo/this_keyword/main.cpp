#include <iostream>
#include <string>
using namespace std;

void PrintEntity(Entity* e);

/*

The keyword "this" in C++ is only accessible to us through a member function (a function that belongs to a class)
Inside a method we can reference "this" and what "this" is is a pointer to the current object instance that the method belongs to.

*/
class Entity {
  public:
    int x, y;
    Entity(int x, int y)
      //: x(x), y(y)  //initialize list is an way to initialize variable within the constructor. Another way to assign initial variables is using "this" keyword
    {
      this->x = x;  //The "this" keyword is a pointer to the current instance of the object
      this->y = y; // It is also possible to use arrow notation -> instead dot . notation as the "this" keyword is a pointer
      //(*this).x = x;
      //(*this).y = y;

      PrintEntity(this); //Passing a current instance of this class to the print function

    }
    int GetX() const {
      return x;
    }
};

void PrintEntity(Entity *e){
  //cout << "The current entity has x->" << e->x << " and y->" << e->y;
}

int main(){
  Entity e(2, 5);
  //PrintEntity();
  cout << "x->" << e.GetX() << endl;
  return 0;
}