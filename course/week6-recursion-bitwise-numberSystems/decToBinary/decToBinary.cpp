#include <iostream>
using namespace std;

int main (){
int dec{0};
bool valid{false};

while (!valid){
cout << "Enter a decimal to be converted to binary:";
cin >> dec;
  if (!cin){
    cin.clear();
    cin.ignore(10000,'\n');
    cout << "Please, provide a valid number" << endl;
  } else {
    valid = true;
    size_t counter{1};
  /*   for (size_t i = 1; i < 10000; i*=10){
      if (dec/i != 0){
        counter++;
        break;     
      }
    }
    cout << "The number " << dec << " has " << counter << " positions" << endl;
  */
    int quotient{dec};

    while (quotient / 2 != 0) {
      counter++;
      cout << quotient % 2 << endl;
      quotient/=2;
    };
  
    cout << "The number " << dec << " in decimal has " << counter << " positions" << endl;

    int *binaryDec = new int[counter];

    quotient = dec;

    for (int i=counter - 1; i >= 0 ; i--){
      binaryDec[i] = quotient % 2; //(1) Modulus operator yields the remainder after integer division.
      quotient/=2;
    }
       
    for (size_t i=0; i < counter ; i++){
      cout << binaryDec[i];
    }
  
    
    cout << endl;
    delete [] binaryDec; // as you have allocated memory for an array, you should free the memory using delete
                        //https://stackoverflow.com/questions/11379433/c-forbids-variable-size-array/11379441#11379441
  }
}

  return 0;
}