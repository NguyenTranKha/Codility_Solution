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

    //Find Leader Element
    vector<int> B(LengthArrayA);
    B = A;
    sort(B.begin(), B.end());
    int ValueMidArray = B[LengthArrayA / 2];
    for( int Number : B){
        if(Number == ValueMidArray) Counter++;
        if(Counter > LengthArrayA / 2) Leader = ValueMidArray;
    }

    int CounterLeft = 0;
    int CounterLesson = 0;

    for(int i = 0; i < LengthArrayA-1; i++){
        if(A[i] == Leader){
            Counter--;
            CounterLeft++;
        }

        if(CounterLeft > (i+1)/2 && Counter > (LengthArrayA - (i + 1))/2) 
        {
            CounterLesson++;
        }
    }
    return CounterLesson;
}