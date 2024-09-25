#include <iostream>
#include <queue>

class Stack {
private:
    std::queue<int> q1, q2;

public:
    // Push element x onto stack.
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        std::swap(q1, q2);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (!q1.empty()) {
            q1.pop();
        }
    }

    // Get the top element.
    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1; // Return -1 if stack is empty
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "Top element: " << s.top() << std::endl; 

    s.pop();

    std::cout << "Top element after pop: " << s.top() << std::endl; 
    std::cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << std::endl;
    
    return 0;
}