#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	vector<int> ans;
    	vector<int>::iterator it;
       	it = digits.end()-1;
       	bool plusFlag = true;
        while(plusFlag){
        	if(*it + 1 < 10){
        		ans.insert(ans.begin(), *it + 1);

        		plusFlag = false;
        	}
        	else{
           		ans.insert(ans.begin(), 0);
        		if(it == digits.begin()){
           			plusFlag = true;
        			break;
        		}
        		else{
        			it--;
        			plusFlag = true;
        		}
        	}
        }

        if(it != digits.begin() && plusFlag == false){
        	for(vector<int>::iterator itt = it-1; itt >= digits.begin(); itt--){
        		ans.insert(ans.begin(), *itt);

        	}       
        }


        if(it == digits.begin() && plusFlag == true){
        	
        	ans.insert(ans.begin(), 1);

        }

        return ans;
        

    }
};

int main(){
	Solution *a;
	a = new Solution();
	int array[]={1,1};
	vector<int> digits (array, array + sizeof(array)/sizeof(int));
	vector<int> ans = a->plusOne(digits);
	for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
		cout<<*it;
	}
	cout<<endl;


}