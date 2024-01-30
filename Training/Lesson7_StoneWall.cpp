// you can use includes, for example:
// #include <algorithm>

#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
    // Implement your solution here
    stack<int> stoneStack; // Stack lưu trữ độ cao của các khối đá
    int blockCount = 0; // Số lượng khối đá cần xây dựng

    for (int height : H) {
        // Loại bỏ các khối đá lớn hơn hoặc bằng khối đá hiện tại
        while (!stoneStack.empty() && stoneStack.top() > height) {
            stoneStack.pop();
        }

        if (stoneStack.empty() || stoneStack.top() < height) {
            // Nếu không có khối đá trước hoặc khối đá hiện tại lớn hơn khối đá trước
            stoneStack.push(height); // Thêm một khối đá mới
            blockCount++; // Tăng số lượng khối đá cần xây dựng
        }
    }

    return blockCount;
}