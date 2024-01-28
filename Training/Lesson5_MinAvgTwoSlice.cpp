// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// Ta chỉ cần xét các mảnh có kích thước là 2 hoặc 3, vì nếu có mảnh lớn hơn 3 thì nó sẽ chứa một mảnh con nhỏ hơn và có trung bình nhỏ hơn. Với mỗi mảnh kích thước 2 hoặc 3, ta tính trung bình của hai số đầu tiên và tính trung bình của hai số tiếp theo, và tổng trung bình của mảng 3 phần tử, so sánh và lấy giá trị nhỏ nhất.
//kiểu float bị overload khi giá trị hơn 1.000.000.000 trong codility

double Slice(vector<double> &B, int PositionA, int PositionB){
    return B[PositionB+1] - B[PositionA];
}

int solution(vector<int> &A) {
    // Implement your solution here
    
    int LengthArrayA = A.end() - A.begin();
    vector<double> PrefixSumArrayA(LengthArrayA+1);
    int MinPosition = 0;
    double Avg = 100001;
    for(int i = 1; i <= LengthArrayA; i++){
        PrefixSumArrayA[i] = PrefixSumArrayA[i-1] + A[i - 1];
    }

    if(PrefixSumArrayA[LengthArrayA]/LengthArrayA == A[0]) return 0;
    
    for(int i = 0; i < LengthArrayA - 2; i++){
        double Avg12 = Slice(PrefixSumArrayA, i, i+2)/3;
        double Avg1 = Slice(PrefixSumArrayA, i, i+1)/2;
        double Avg2 = Slice(PrefixSumArrayA, i+1, i+2)/2;
 

        if(Avg1 < Avg2){
            if(Avg1 < Avg) {MinPosition = i; Avg = Avg1;};
        }else if(Avg1 > Avg2){
            if(Avg2 < Avg) {MinPosition = i+1; Avg = Avg2;};
        };   

        if(Avg12 < Avg){
            MinPosition = i; Avg = Avg12;
        }
    }
    return MinPosition;
};