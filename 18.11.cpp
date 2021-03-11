#include <iostream>
#include <stack>
#include <cstdlib>
#include <queue>

using namespace std;

int main() {
    stack<int> stack1;
    queue<int> queue1;
    
    for (int i = 0; i < 10; ++i) {
        stack1.push(rand() % 100);
    }
    
    queue1.push(stack1.top());
    stack1.pop();
    int min = queue1.front();
    
    while (!stack1.empty()) {
        if (stack1.top() < queue1.front()) {
            queue1.push(stack1.top());
            if (min > stack1.top()) {
                min = stack1.top();
            }
            stack1.pop();
            while (queue1.front() != min) {
                queue1.push(queue1.front());
                queue1.pop();
            }
            continue;
        }
        queue1.push(queue1.front());
        queue1.pop();
        if (queue1.front() == min) {
            queue1.push(stack1.top());
            if (min > stack1.top()) {
                min = stack1.top();
            }
            stack1.pop();
            while (queue1.front() != min) {
                queue1.push(queue1.front());
                queue1.pop();
            }
        }
    }
    
    return 0;
}