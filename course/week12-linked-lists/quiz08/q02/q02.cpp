/*
Question 2 (1 point) 
class ArrayFun {
    int *x;
    int *y;
    int *z;
public:
    ArrayFun(int *a, int n) : x(a), y(new int[n]), z(new int) {}
    ~ArrayFun();
};

Which of the following is an acceptable destructor for ArrayFun which will allow no memory leaks or invalid memory accesses?

Question 2 options:

delete [] x; delete z;


delete [] x; delete [] y;


delete [] x; delete [] y; delete [] z;


delete [] y; delete z;  <- this is the answer

*/


class ArrayFun {
    int *x;
    int *y;
    int *z;
public:
    ArrayFun(int *a, int n) : x(a), y(new int[n]), z(new int) {}
    ~ArrayFun();
};