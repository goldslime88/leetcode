#include <iostream>
#include <queue>
using namespace std;
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        normal_queue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int full_size = normal_queue.size();
        for ( int i = 0; i < full_size-1; ++i )
        {
            cache_queue.push(normal_queue.front());
            normal_queue.pop();
        }
        normal_queue.pop();
        while( !cache_queue.empty() )
        {
            normal_queue.push(cache_queue.front());
            cache_queue.pop();
        }
    }

    // Get the top element.
    int top() {
        int full_size = normal_queue.size();
        for ( int i = 0; i < full_size - 1; ++i )
        {
            cache_queue.push(normal_queue.front());
            normal_queue.pop();
        }
        int ans = normal_queue.front();
        cache_queue.push(normal_queue.front());
        normal_queue.pop();
        while( !cache_queue.empty() )
        {
            normal_queue.push(cache_queue.front());
            cache_queue.pop();
        }
        return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        return normal_queue.empty();
    }
private:
    queue<int> normal_queue;
    queue<int> cache_queue;
};

int main(int argc, char const *argv[])
{
    Stack* test_stack = new Stack();
    test_stack->push(1);
    test_stack->push(2);
    test_stack->push(3);
    cout<<test_stack->top()<<endl;
    return 0;
}