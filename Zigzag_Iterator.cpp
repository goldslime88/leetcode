#include <iostream>
#include <vector>
using namespace std;


class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2):record_1(v1), record_2(v2) {
    	index_1 = 0;
    	index_2 = 0;
        which_vector = true;//true v1, false v2
    }

    int next() {
        if(which_vector){
        	int ans = record_1[index_1];
        	if(index_2 < record_2.size()){
        		which_vector = false;
        	}
        	index_1++;
        	return ans;
        }
        else{
        	int ans = record_2[index_2];
        	if(index_1 < record_1.size()){
        		which_vector = true;
        	}
        	index_2++;
        	return ans;
        }

    }

    bool hasNext() {
       
       if(which_vector){
       		if(record_1.empty() && !record_2.empty()){
       			which_vector = false;
       			return true;
       		}
       		if(index_1 < record_1.size()){
       			return true;
       		}
       		else{
       			return false;
       		}
       }
       else{
       		if(index_2 < record_2.size()){
       			return true;
       		}
       		else{
       			return false;
       		}
       } 
    }


private:
	vector<int> record_1;
	vector<int> record_2;
	int index_1;
	int index_2;
	bool which_vector; 
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */