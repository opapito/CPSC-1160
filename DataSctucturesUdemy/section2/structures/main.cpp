struct Rectangle
{
  int length;
  int breath;
};

struct Complex
{
  int real;
  int img;
};

struct Student
{
  int roll;
  char name[253];
  char dept[10];
  char address [50];
};

struct Card
{
  int face;
  int shape;
  int color;
};


int main(){
  Rectangle x;
  Student s;
  Card c;
  Card c2 = {1,  0, 0};

  Card deck[52] = {{1,0,0}, {2,0,0}}; //array of structures of type Card

  x.length = 5;
  x.breath = 10;

  s.roll = 10;
  s.name = "John";

  c.face = 1;
  c.shape = 0;
  c.color = 0;

}
