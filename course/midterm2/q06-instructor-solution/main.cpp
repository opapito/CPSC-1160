#include <iostream>
#include <sstream>	// this is used for testing. Don't worry about it

/* put q1 here */
enum class colour {
black, blue, red, yellow, green, pink
};
/* put q2 here */
enum class pattern {
solid, stripes, floral, polkadots
};
/* put q3 here */
static bool match(colour a, colour b){
  if (a > b)          return match (b, a);
  else if (a == b)   return true;
  switch (a)
  {
  case colour::pink:
  case colour::yellow:
  case colour::black: return true;
  case colour::blue:  return b == colour::red || b == colour:: pink;
  case colour::red:   return b == colour::yellow || b == colour:: green;
  case colour::green: return false;

  }
  return false; //just to shut up the compiler
}

/* put q4 here */

struct clothing
{
 colour c;
 pattern p;
};
 
class outfit {
	/* fill in for q5 */
  clothing shirt, pants;
public:
  outfit(clothing s, clothing p) 
  :shirt(s), pants(p)
  {
  }
	/* fill in for q5 */
	bool matches() const{
    return match(shirt.c, pants.c) && ((shirt.p == pants.p) || (shirt.p == pattern::solid) || (pants.p == pattern::solid));
  };	// write this for q6

	void swap_shirt_with(outfit & o){
    clothing temp = o.shirt;
    o.shirt = shirt;
    shirt = temp;
  };	// write this for q7
	  friend std::ostream &operator<<(std::ostream &out, outfit const &o){
      return out << "shirt and pants have " << (o.shirt.c == o.pants.c ? "same" : "different")
                 << " colour and " << (o.shirt.p == o.pants.p ? "same" : "different")
                 << " pattern";
     
  };	// q8
};
 
int main() {
/* you do not need to change anything here */
	clothing c0 = { colour::black, pattern::solid },
		c1 = { colour::black, pattern::floral },
		c2 = { colour::red, pattern::solid },//
		c3 = { colour::blue, pattern::polkadots },
		c4 = { colour::green, pattern::solid },
		c5 = { colour::pink, pattern::floral },//
		c6 = { colour::yellow, pattern::solid },
		c7 = { colour::blue, pattern::solid };
	outfit o1(c0, c3),
		o2(c7, c4),
		o3(c3, c7),
		o4(c1, c3),
		o5(c5, c7),
		o6(c6, c5),
		o7(c1, c4),
		o8(c4, c6),
		o9(c2, c5),
		oA(c2, c4),
		oB(c6, c3),
		oC(c0, c0);
#define C(o, e)	cout << "line " << __LINE__ << (o.matches() == e ? " passed" : " failed") << endl
	using namespace std;
	C(o1, true);
	C(o2, false);
	C(o3, true);
	C(o4, false);
	C(o5, true);
	C(o6, true);
	C(o7, true);
	C(o8, true); 
	C(o9, false); 
	C(oA, true); 
	C(oB, false); 
	C(oC, true);
	o6.swap_shirt_with(o9); 
	C(o6, false); 
	C(o9, true);
#define M(o, e)	{ stringstream ss; ss << o; cout << "line " << __LINE__ << (ss.str() == e ? " passed" : " failed") << endl; }
	M(o2, "shirt and pants have different colour and same pattern"); //failed, because it wasn't implemented
	M(o1, "shirt and pants have different colour and different pattern");//failed, because it wasn't implemented
	M(o3, "shirt and pants have same colour and different pattern");//failed, because it wasn't implemented
	M(oC, "shirt and pants have same colour and same pattern"); // was implemented
}