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
bool c_matches(colour c1, colour c2){
  if (c1 == colour::black || c2 == colour::black){
    return true;
  }
  if (c1 == c2){
    return true;
  }
  switch (c1)
  {
  case colour::blue: {
      if (c2 == colour::red || c2 == colour::pink){
        return true;
      }
      return false;
  }
    break;
  
  case colour::red: {
    if (c2 != colour::pink){
      return true;
    }
    return false;
    
  }
    break;
  case colour::yellow: {
    if (c2 != colour::blue){
      return true;
    }
    return false;
  }
    break;

  case colour::green: {
    if (c2 != colour::blue || c2 != colour::pink){
      return true;
    }
    return false;
  }
    break;
  case colour::pink:{
    if (c2 != colour::red || c2 != colour::green){
      return true;
    }
    return false;
  }
    break;
  default:
    return false;
  }

}

/* put q4 here */

struct clothing
{
 colour c;
 pattern p;
};
 
class outfit {
	/* fill in for q5 */
  clothing shirt;
  clothing pants;
public:
  outfit(clothing shirt, clothing pants) 
  :shirt(shirt), pants(pants)
  {
  }
	/* fill in for q5 */
	bool matches() const{
    if (c_matches(shirt.c, pants.c)){
      if((shirt.p == pants.p) || (shirt.p == pattern::solid) || (pants.p == pattern::solid)){
        return true;
      }
    }
    return false;
  };	// write this for q6

	void swap_shirt_with(outfit & other){
    clothing tmp;
    tmp = this->shirt;
    this->shirt = other.shirt;
    other.shirt = tmp;
  };	// write this for q7
	  friend std::ostream &operator<<(std::ostream &out, outfit const &o){
      if (o.shirt.c == o.pants.c ){
        if (o.shirt.p == o.pants.p){
          out << "shirt and pants have same colour and same pattern";
        } else {
          out << "shirt and pants have same colour and different pattern";
        }
      } else if(o.shirt.p == o.pants.p){
         out << "shirt and pants have different colour and same pattern";
      } else {
        out << "shirt and pants have different colour and different pattern";
      }
      return out;
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