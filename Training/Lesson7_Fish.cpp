// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector < int > & A, vector < int > & B) {
  // Implement your solution here
  int LengthStringArrayA = A.size();
  stack < int > StackFish;
  stack < int > StackStream;

  if(LengthStringArrayA == 0) return 0;

  for (int i = 0; i < LengthStringArrayA; i++) {
        if (StackFish.empty()) {
            StackFish.push(A[i]);
            StackStream.push(B[i]);
        } else {
        if (StackStream.top() <= B[i]) {
            StackFish.push(A[i]);
            StackStream.push(B[i]);
        } else {
            while (StackStream.top() > B[i]) {
            if (StackFish.top() < A[i]) {
                StackFish.pop();
                StackStream.pop();
                if(StackFish.empty())  break;
            }else{
                i++;
                if(i >= LengthStringArrayA)  return StackFish.size();
            }
            }
            StackFish.push(A[i]);
            StackStream.push(B[i]);
        }
        }

  }
  return StackFish.size();
}