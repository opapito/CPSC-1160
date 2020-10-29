/*
Write a C++ program that displays a Letter Pyramid from a user-provided std::string.

Prompt the user to enter a std::string and then from that string display a Letter Pyramid as follows:

It's much easier to understand the Letter Pyramid given examples.

If the user enters the string "ABC", then your program should display:

  A                                                                                                                    
 ABA                                                                                                                   
ABCBA 


If the user enters the string, "12345", then your program should display:

 

    1                                                                                                                  
   121                                                                                                                 
  12321                                                                                                                
 1234321                                                                                                               
123454321
 

If the user enters 'ABCDEFG', then your program should display:

 

      A                                                                                                                
     ABA                                                                                                               
    ABCBA                                                                                                              
   ABCDCBA                                                                                                             
  ABCDEDCBA                                                                                                            
 ABCDEFEDCBA                                                                                                           
ABCDEFGFEDCBA

If the user enters 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', then your program should display:

                         A
                        ABA
                       ABCBA
                      ABCDCBA
                     ABCDEDCBA
                    ABCDEFEDCBA
                   ABCDEFGFEDCBA
                  ABCDEFGHGFEDCBA
                 ABCDEFGHIHGFEDCBA
                ABCDEFGHIJIHGFEDCBA
               ABCDEFGHIJKJIHGFEDCBA
              ABCDEFGHIJKLKJIHGFEDCBA
             ABCDEFGHIJKLMLKJIHGFEDCBA
            ABCDEFGHIJKLMNMLKJIHGFEDCBA
           ABCDEFGHIJKLMNONMLKJIHGFEDCBA
          ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA
         ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA
        ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA
       ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA
      ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA
     ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA
    ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA
   ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA
  ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA
 ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA

If the user enters "C++isFun!", then your program should display:

 

        C                                                                                                              
       C+C                                                                                                             
      C+++C                                                                                                            
     C++i++C                                                                                                           
    C++isi++C                                                                                                          
   C++isFsi++C                                                                                                         
  C++isFuFsi++C                                                                                                        
 C++isFunuFsi++C                                                                                                       
C++isFun!nuFsi++C


Think about the problem before you begin and break it down into steps.

This can be a very challenging problem to solve!

*****  Don't forget to paste your code solution when you submit.******

Have fun!
  
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string letters{};
    cout << "Enter a string for pyramid: ";
    getline(cin, letters);
    
    
    for (size_t i{0}; i < letters.length(); i++) {  //rows = length of the input string
        string line{};
        size_t nrOfCol{letters.length() + (letters.length()/2)*2};
        size_t low{((nrOfCol/2) - i > nrOfCol/2) ? 0 : (nrOfCol/2) - i};
        size_t high{(nrOfCol/2) + i > nrOfCol ? nrOfCol : (nrOfCol/2) + i };
        int n{0};
        bool countDown{false};
    
        for (size_t j{0}; j < nrOfCol; j++){ //columns = length of the input string + (length of the input string / 2) * 2
                
            if (j >= low && j <= high){
                
                line += letters.at(n);

                if (n + 1 >= (int) letters.length()){
                    countDown = true;
                }

                if (n < 1){
                    countDown = false;
                }

                if (countDown){
                    (n < 1 ? 0 : n--);
                } else {
                    (n + 1 >= (int) letters.length() ? letters.length() - 1 : n++);
                }
                                
            }else{
                line+="-";
            }
        }
        cout << line << endl;
    }
    
    
	return 0;
}
