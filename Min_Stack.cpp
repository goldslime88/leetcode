#include <iostream>
#include <stack>
using namespace std;


class MinStack {
public:
    void push(int x) {
        s.push(x);
        if (mins.empty() || x<=mins.top()) {
            mins.push(x);
        }
    }

    void pop() {
        int temp = s.top();
        s.pop();
        if (temp == mins.top()) {
            mins.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return mins.top();
    }

private:
    stack<int> s;
    stack<int> mins;
};


int main(){
	MinStack stack1;
	stack1.push(1);
	stack1.push(7);
	stack1.push(4);
    stack1.push(11);
    
	

	cout<< stack1.getMin() << " "<< stack1.top()<< endl;

}