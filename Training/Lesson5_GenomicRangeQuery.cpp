// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// A: 0 0 1 1 1 1 1 2
// B: 0 1 1 1 2 3 3 3
// G: 0 0 0 1 1 1 1 1
// T: 0 0 0 0 0 0 0 1

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // Implement your solution here
    int Snumber = S.end() - S.begin();
    int Pnumber = P.end() - P.begin();
    vector<int> A(Snumber+1);
    vector<int> C(Snumber+1);
    vector<int> G(Snumber+1);
    vector<int> T(Snumber+1);
    vector<int> Result(Pnumber);

    for(int i = 0; i < Snumber; i++){
        switch (S[i]){
            case 'A':
                A[i+1]++;
                break;
            case 'C':
                C[i+1]++;
                break;
            case 'G':
                G[i+1]++;
                break;
            case 'T':
                T[i+1]++;
                break;
        };
        A[i+1] += A[i];
        C[i+1] += C[i];
        G[i+1] += G[i];
        T[i+1] += T[i];
    }

    for(int i = 0; i < Pnumber; i++){
        int start = P[i];
        int end = Q[i];
             if(start == end){
                switch (S[start]){
                case 'A':
                    Result[i] = 1;
                    break;
                case 'C':
                    Result[i] = 2;
                    break;
                case 'G':
                    Result[i] = 3;
                    break;
                case 'T':
                    Result[i] = 4;
                    break;
              };
            }else{
                if(A[start] != A[end+1]) {Result[i] = 1;}
                else if(C[start] != C[end+1]) {Result[i] = 2;}
                else if(G[start] != G[end+1]) {Result[i] = 3;}
                else if(T[start] != T[end+1]) {Result[i] = 4;}
            }
    }
    return Result;
}
