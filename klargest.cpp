#include <iostream>
#include <queue>
using namespace std;

class mycompare{
	bool operator()(const int& a, const int& b){
		return a > b;
	}
};

int main(int argc, char const *argv[])
{
	priority_queue<int> kqueue;
	int k = 10;

	for(int i = 0; i < 20; ++i){
		if(kqueue.size()<k){
			kqueue.push(i);
		}
		else{
			kqueue.push(i);
			kqueue.pop();
		}
	}

	cout<<kqueue.top()<<endl;
	return 0;
}