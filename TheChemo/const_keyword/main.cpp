#include <iostream>
#include <string>

class Entity {
  private:
    int m_X, m_Y;
    mutable int var;
  public:
    int GetX() const { // The keyword "const" after a method means that this method can not change the class attributes
      var = 2; // "mutable" variables are the only type that can be changed inside a method with the keyword "const"
      return m_X;
    }
    void SetX(int x) {
      m_X = x;
    }
};

void PrintEntity(const Entity& e) { 
/* 
* The keyword "const" here prevent us to reassign the Entity object. 
* Also, as we are passing by reference, it does not make a entire copy of the object content
* Note the it is just possible to call the e.GetX() method here because it was declared with a const keyword. If it wasn's declared with const, the compiler wouldn't allow us to call it here.
*/

  std::cout << e.GetX() << std::endl;
}

int main(){
Entity e;

}