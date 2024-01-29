// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// distinct: riêng biệt

int solution(vector<int> &A) {
    // Implement your solution here
    int LengthArrayA = A.size();
    int NumberDistinctArrayA = 0;
    sort(A.begin(), A.end());
    
    if(LengthArrayA == 0) {
        return 0;
        } else {
            NumberDistinctArrayA = 1;
        };

    //tìm số khác biệt giữa các phần từ đã được sắp xếp
    for (int i = 0; i < LengthArrayA-1; i++){
        if(A[i] != A[i+1]) NumberDistinctArrayA++; 
    }
    return NumberDistinctArrayA;
}