/*
Question 4 (3 points) 
Copy and paste complete C++ code for the following problem. Write a function which takes in an array of ints, plus a value to search for. If the value being searched for exists within the array, return the index CLOSEST TO THE MIDDLE. If the value does not exist, return -1. If there are two matching elements which are equidistant from the middle, return the lower-numbered index. You may write the function either using loops (iteratively) or recursively, whichever you prefer.

For example:

int x[] = { 7, -4, 2, 7, 4, 9, 14, 7 };
cout << index_closest_to_middle(x, sizeof x / sizeof x[0], 7) << endl;

The above should output 3, as the 7 at index 3 is the one which is closest to the middle of the array.

Include a main function which will test the function. You only need one test. You may hardcore the values for the test (reading input from the user is not required).

*/

#include <iostream>

using namespace std;

int index_closest_to_middle(int const *arr, size_t aSize, int s) {
    size_t middle{(aSize/2) - 1};
    int arrOcc[aSize]{0};
    bool found{false};

    for (size_t i = 0; i < aSize; i++){
      if (arr[i] == s){
        if (i == middle){
          return i; // if the value matches with the one in the middle it is the closest and lower-numbered one and should be returned immediately
        }  
        arrOcc[i] = s;
        found = true;
      }
    }

    if (!found){ 
      return -1; // if the value was not found, -1 is returned
    }

    /*
    ***************** WARNING ****************************************************************************************************    
      It is not possible to use size_t in a countdow for loop as it is an UNSIGNED type. The conditions >= 0 OR > 0 won't work HERE
      https://stackoverflow.com/a/1951579 
    
    ****************** UPDATE 1 ***************************************************************************************************
    There is a way to make a countdown for loop work with size_t
        for (size_t i = 5; i-- > 0; )
        if (wantBurrito(i))
            break;

    https://flak.tedunangst.com/post/counting-up-vs-counting-down 
    "I don’t usually see loops like this, so it took me a little extra effort to verify this is correct, but it is. The index looks to be too large, but it’s decremented before use, and we will hit zero inside the loop body."
    
    ****************** UPDATE 2 ***************************************************************************************************
    Here is another way to make it works

    size_t last = 5;
    for (size_t i = last-1; i < last; i--) {
      printf("%d\n", i); // prints 4, 3, 2, 1, 0
    }
    "Unsigned integer 0 - 1 becomes UINT_MAX. So instead of looking for -1, you watch for when your counter becomes bigger than its initial state."

    ****************** UPDATE 3 ***************************************************************************************************
    Another way to make it works
    
    int array[11];
    for (size_t i = 11; i-- > 0; ) {
        // Do something, f.ex. array[i] = i
    }

    "You must check for the condition before decrementing the index. Starting the enumeration with an initial value one more than the maximum valid index improves visual consistency and simplifies the test."
    https://stackoverflow.com/questions/41075881/infinite-loop-when-using-size-t-in-a-count-down-for-loop/41076051#41076051 

    */ 
    size_t middleUp  {middle + 1};
    for (int i = middle; i >= 0; i-- ){  // searching from middle to begining to find the lower index
      
      if (arrOcc[i]){                    // the lower index next to middle is returned first if equidistant   
        return i;                           
      }
      if (arrOcc[middleUp]){            // searching from middle to end to find the lower index            
        return middleUp;                // if the lower index next to middle did not return, the next upper will be the closest do the middle           
      }
      middleUp++;                       // middleUp needs to be increased in order to keep the simultaneously search
    }                                       
    

return 0;
}

int main(){
int arr[]{ 7, -4, 2, 7, 4, 9, 14, 7 };
int arr2[]{ 5, -4, 2, 6, 3, 4, 9, 14, 8 };
int arr3[]{ 7, -4, 2, 7, 4, 9, 14, 3 };
int arr4[]{ 3, 3, 3, 3, 3, 3, 3, 3 };
int arr5[]{ 7, -4, 2, 7, 4, 3, 14, 7 };
int arr6[]{ 7, -4, 3, 7, 4, 3, 14, 7 };
int arr7[]{ 7, 4, 3, 7, 4, 3, 14, 7 };

cout << index_closest_to_middle(arr, sizeof arr / sizeof arr[0], 7) << endl;    // should return 3
cout << index_closest_to_middle(arr2, sizeof arr2 / sizeof arr2[0], 6) << endl; // should return 3
cout << index_closest_to_middle(arr2, sizeof arr2 / sizeof arr2[0], 7) << endl; // should return -1
cout << index_closest_to_middle(arr3, sizeof arr3 / sizeof arr3[0], 3) << endl; // should return 7
cout << index_closest_to_middle(arr4, sizeof arr4 / sizeof arr4[0], 3) << endl; // should return 3
cout << index_closest_to_middle(arr5, sizeof arr5 / sizeof arr5[0], 3) << endl; // should return 5
cout << index_closest_to_middle(arr6, sizeof arr6 / sizeof arr6[0], 3) << endl; // should return 2
cout << index_closest_to_middle(arr7, sizeof arr7 / sizeof arr7[0], 4) << endl; // should return 4 


return 0;
}