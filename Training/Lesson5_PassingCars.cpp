// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int Prefix_Sums(vector<int> &Array, vector<int> &PrefixSum);
int Count_Total(vector<int> &PrefixSum, int x, int y);

int solution(vector<int> &A) {
    // Implement your solution here
    int SizeA = end(A) - begin(A);
    vector<int> PrefixSum;
    Prefix_Sums(A, PrefixSum);
    int result = 0;

    for(int i = 0; i < SizeA; i++){
        if(A[i] == 0){
            result += Count_Total(PrefixSum, i, SizeA - 1);
            if(result > 1000000000) return -1;
        }
    }
    return result;
}

int Prefix_Sums(vector<int> &Array, vector<int> &PrefixSum){
    int SizeA = end(Array) - begin(Array);
    PrefixSum.push_back(0);
    for(int i = 1; i < SizeA+1; i++){
        // PrefixSum[i] = PrefixSum[i - 1] + Array[i - 1];
        PrefixSum.push_back(PrefixSum[i - 1] + Array[i - 1]);
    }
    return 1;
}

int Count_Total(vector<int> &PrefixSum, int x, int y){
    return PrefixSum[y+1] - PrefixSum[x];
}