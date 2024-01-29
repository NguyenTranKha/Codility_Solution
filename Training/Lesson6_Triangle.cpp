// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    int LengthArrayA = A.size();
    sort(A.begin(), A.end());
    for(int i = 0; i < LengthArrayA - 2; i++){
        if((unsigned int)A[i]+(unsigned int)A[i+1] > A[i+2]) return 1;
    }
    return 0;
}