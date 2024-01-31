// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    int Leader = -1;
    int Counter = 0;
    int LengthArrayA = A.size();
    if(LengthArrayA == 0) return -1;
    vector<int> B(LengthArrayA);
    B = A;
    
    sort(A.begin(), A.end());
    int ValueMidArray = A[LengthArrayA / 2];
    
    for( int Number : A){
        if(Number == ValueMidArray) Counter++;
        if(Counter > LengthArrayA / 2) Leader = ValueMidArray;
    }

    if(Leader == -1) return Leader;
    for( int i = 0; i < LengthArrayA; i++){
        if(B[i] == Leader) return i;
    }
}