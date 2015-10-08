#include <iostream>
#include <vector>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	bool peeked;
	int peeked_ele;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    peeked = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!peeked && Iterator::hasNext()){
        	peeked = true;
        	peeked_ele = Iterator::next();
        	
        }
        
        return peeked_ele;
        
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if(peeked){
			peeked = false;
			return peeked_ele;
		}  
		if(Iterator::hasNext()){
			return Iterator::next();
		}
		
	}

	bool hasNext() const {
		if(peeked){
			return true;
		}
	    return Iterator::hasNext();
	}
};

int main(int argc, char const *argv[])
{
	vector<int> test = {2,3,1,5,7,6};	
	PeekingIterator it(test);
	cout<<it.next()<<endl;
	
	return 0;
}