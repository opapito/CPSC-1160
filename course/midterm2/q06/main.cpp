#include <iostream>
#include <sstream>	// this is used for testing. Don't worry about it

/* put q1 here */
enum class colours {
black, blue, red, yellow, green, pink
};
/* put q2 here */
enum class patterns {
solid, stripes, floral, polka, dots
};
/* put q3 here */
bool matches(colours c1, colours c2){
  if (c1 === back || c2 == black){
    return true;
  }
  if (c1 == c2){
    return true;
  }
  switch (c1)
  {
  case blue {
      if (c2 == red || c2 == pink){
        return true;
      }
  }
    break;
  
  case red {
    if (c2 != pink){
      return true;
    }
  }
    break;
  case yellow {
    if (c2 != blue){
      return true;
    }
  }
    break;

  case green {
    if (c2 != blue || c2 != pink){
      return true;
    }
  }
    break;
  case pink {
    if (c2 != red || c2 != green){
      return true;
    }
  }
    break;
  default:
    return false;
    break;
  }

}

/* put q4 here */

struct clothing
{
 colours c;
 patterns p;
};

 
class outfit {
	/* fill in for q5 */
  clothing shirt;
  clothing pants;
  outfit(clothing shirt, clothing pants) :
  :shirt(shirt), pants(pants)
  {
  }
public:
	/* fill in for q5 */
	bool matches() const{
    return shirt.c == pants.c && shirt.p == pants.p || shirt.p == solid || pants.p == solid;
  };	// write this for q6

	void swap_shirt_with(outfit & other){
    clothing tmp;
    tmp = this->shirt;
    this->shirt = other.shirt;
    other.shirt = tmp;
  };	// write this for q7
	  friend std::ostream &operator<<(std::ostream &out, outfit const &o){
    return out << (shirt.c == pants.c && shirt.p == pants.p ? 
     "shirt and pants have same colour and same pattern":""; );
  };	// q8
};
 
int main() {
/* you do not need to change anything here */
	clothing c0 = { colour::black, pattern::solid },
		c1 = { colour::black, pattern::floral },
		c2 = { colour::red, pattern::solid },
		c3 = { colour::blue, pattern::polkadots },
		c4 = { colour::green, pattern::solid },
		c5 = { colour::pink, pattern::floral },
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
	M(o2, "shirt and pants have different colour and same pattern");
	M(o1, "shirt and pants have different colour and different pattern");
	M(o3, "shirt and pants have same colour and different pattern");
	M(oC, "shirt and pants have same colour and same pattern");
}