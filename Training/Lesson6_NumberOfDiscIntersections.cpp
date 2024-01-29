// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// Điểm bắt đầu lớn hơn điểm kết thúc thì không tồn tại giao điểm của 2 đường tròn

int solution(vector<int> &A) {
    // Implement your solution here
    int LengthArrayA = A.size();
    vector<long long> Lower(LengthArrayA);
    vector<long long> Upper(LengthArrayA);
    int count = 0;

    // Tính toán tọa độ bắt đầu và kết thúc của mỗi đoạn thẳng
    for(int i = 0; i < LengthArrayA; i++){
        Upper[i] = i + (long long)A[i];
        Lower[i] = i - (long long)A[i];
    }

    // Sắp xếp tọa độ bắt đầu và kết thúc của mỗi đoạn thẳng
    sort(Upper.begin(), Upper.end());
    sort(Lower.begin(), Lower.end());

    int j = 0;
    for (int i = 0; i < LengthArrayA; ++i) {
        while (j < LengthArrayA && Upper[i] >= Lower[j]) {
            count += j; // Đếm số lượng đoạn thẳng mà đoạn thẳng hiện tại giao với
            count -= i; // Đảm bảo không đếm chính nó
            ++j;
        }
    }

    // Kiểm tra điều kiện vượt quá số lượng tối đa giao điểm
    if (count > 10000000) return -1;
    
    return count;
}