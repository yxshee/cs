#include <iostream>
#include <stack>

class QueueUsingStacks {
private:
    std::stack<int> stack1, stack2;

    void transferStack1ToStack2() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    void enqueue(int x) {
        stack1.push(x);
    }

    void dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                std::cout << "Queue is empty" << std::endl;
                return;
            }
            transferStack1ToStack2();
        }
        stack2.pop();
    }

    int front() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                std::cout << "Queue is empty" << std::endl;
                return -1;
            }
            transferStack1ToStack2();
        }
        return stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    QueueUsingStacks q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Front element is: " << q.front() << std::endl;
    q.dequeue();
    std::cout << "Front element is: " << q.front() << std::endl;
    q.dequeue();
    std::cout << "Front element is: " << q.front() << std::endl;
    q.dequeue();

    if (q.isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
    }

    return 0;
}