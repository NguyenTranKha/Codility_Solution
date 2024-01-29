// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    int LengthArrayA = A.size();
    sort(A.begin(), A.end());
    int Multiplication1 = A[0]*A[1]*A[LengthArrayA-1];
    int Multiplication2 = A[LengthArrayA-3]*A[LengthArrayA-2]*A[LengthArrayA-1];

    if(Multiplication1 > Multiplication2){
        return Multiplication1;
    }else{
        return Multiplication2;
    }
}