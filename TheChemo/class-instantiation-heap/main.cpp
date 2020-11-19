#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
  String m_Name;
public:
  Entity(): m_Name("Unknown"){};
  Entity(const String& name): m_Name(name){};

  const String& Getname() const { return m_Name; };

};


int main()
{
  Entity entity; //allocation in stack frame
  std:: cout << entity.Getname() << std::endl;
  Entity e("Cherno");//allocation in stack frame
  std:: cout << e.Getname() << std::endl;
  Entity *eh = new Entity("Cherno in HEAP");
  std:: cout << eh->Getname() << std::endl;
 //std:: cout << (*eh).Getname() << std::endl;
 /*
  It is possible either dereference the pointer and use dot notation (*eh).Getname() or using arrow operator that do it for us eh->Getname().
 */
  delete eh;
  return 0;
}

