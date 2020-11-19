#include <iostream>
#include <string>

class Entity
{
private:
  int x;/* data */
public:
  void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
private:
  /* data */
  Entity* m_Obj;
public:
  ScopedPtr(Entity* entity)
    : m_Obj(entity)
    {
    }
  ~ScopedPtr()
  {
    delete m_Obj;
  }
  Entity* operator->(){  //overloading arrow -> operator
    return m_Obj;
  }
};


int main()
{
  Entity e;
  e.Print();

  Entity* ptr = &e;
  ptr->Print();
  
  ScopedPtr entity = new Entity();
  entity->Print();


  return 0;
}
