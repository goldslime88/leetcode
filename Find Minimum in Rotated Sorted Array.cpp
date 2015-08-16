#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int findMin(vector<int> &num) {
        int start = 0;
        int finish = num.size()-1;
        int mid;
        int result;
        try{
        	if(num.size() == 0){
        		throw 0;
        	}
        }
        catch (int e){
        	cout<<"the vector is empty"<<endl;
        	return 0;
        }
        
        while(1){
        	if(finish == start){
        		return num[finish];
        	}
        	else if(finish - start == 1){
        		if(num[start] > num[finish]){
        			return num[finish];
        		}
        		else{
        			return num[start];
        		}
        	}
        	else{
		    	mid = (start + finish)/2;
		    	if(num[mid] > num[start] && num[mid] > num[finish]){
		    		start = mid;
		    		
		    	}
		    	else if(num[mid] < num[start] && num[mid] < num[finish]){
		    		finish = mid;

		    	}
		    	else if(num[mid] > num[start] && num[mid] < num[finish]){
		    		return num[start];
		    	}
		    	else if(num[mid] < num[start] && num[mid] > num[finish]){
		    		return num[finish];
		    	}
        	}
        }



    }
};

int main(int argc, char const *argv[])
{
	Solution *a;
	a = new Solution();
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);

	cout<<a->findMin(test)<<endl;
	return 0;
}