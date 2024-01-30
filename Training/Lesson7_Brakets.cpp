// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // Implement your solution here
    int LengthStringS = S.size();
    stack<char> CharStack;
    for(int i = 0; i < LengthStringS; i++){
        switch (S[i]) {
            case ')':
                if( CharStack.top() != '(' ) return 0;
                CharStack.pop();
                break;
            case ']':
                if( CharStack.top() != '[' ) return 0;
                CharStack.pop();
                break;
            case '}':
                if( CharStack.top() != '{' ) return 0;
                CharStack.pop();
                break;
            default:
                CharStack.push(S[i]);
        }
    }
    if(!CharStack.empty()) return 0;
    return 1;
}