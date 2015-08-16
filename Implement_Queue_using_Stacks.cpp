#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while ( !reverse_store.empty() )
        {
            normal_store.push(reverse_store.top());
            reverse_store.pop();
        }
        normal_store.push(x);
        while ( !normal_store.empty() )
        {
            reverse_store.push(normal_store.top());
            normal_store.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        reverse_store.pop();
    }

    // Get the front element.
    int peek(void) {
        return(reverse_store.top());
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return(reverse_store.empty());
    }

private:
    stack<int> normal_store;
    stack<int> reverse_store;
};