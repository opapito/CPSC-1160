/*
Example 4
Description: A guessing game where the player guesses the secret number.

You can create a random number generator in C++ by using the rand() and srand() functions that come with the standard library of C++. Such a generator can have the starting number (THE SEED) and the maximum value. (https://www.bitdegree.org/learn/random-number-generator-cpp#where-are-random-numbers-used)

*************************************************************
Making the random numbers different after every execution (https://www.bitdegree.org/learn/random-number-generator-cpp#making-the-random-numbers-different-after-every-execution)
*************************************************************
It is not enough to only use the rand() function to make the C++ generate random numbers.

If you do not use the srand method together with rand, you will get the same sequence every time code runs.

To avoid the repetitive sequence, you must set the SEED as an argument to the srand() method. However, setting a fixed value for the srand() is also not a good option as the output remains the same.

A very useful tip to make C++ generate random numbers is to use the time() method. By seeding the generator with the same number, you are more likely to get the same random number each time.

Therefore, if you use the C++ srand() with the current time, the generated random number will always be different.

TIP: you need to call the C++ srand() function only once at the beginning of code (before calling rand()). Multiple calls can influence the generation of random numbers negatively.


*/
#include <iostream>
#include <ctime>
#include <climits>


using namespace std;

int main(){

int nSecret{0}, nGuess{0};

// Initialize random seed.
srand (time(NULL));

// Generate random number between 1 and 100
nSecret = (rand() % 100) + 1;

do {
cout << "\nGuess the secret number (" << nSecret<< "): " << endl;
cin >> nGuess;
  if (!cin){
    cout << "\nInvalid input!\nPlease, enter a valid integer between 0 and 100!" << endl;
    cin.clear();
    cin.ignore(SSIZE_MAX, '\n');
  } else{
    if (nGuess == nSecret){
      cout << "\nCorrect answer!"<< endl;
    } else{
      if (nGuess > nSecret){
        cout << "\nOopps...that's too HIGH. Try a lower number!"<< endl;
      } else {
        cout << "\nOopps...that's too LOW. Try a higher number!"<< endl;
      } 
    }
    
  }

} while (nGuess != nSecret);

return 0;
}