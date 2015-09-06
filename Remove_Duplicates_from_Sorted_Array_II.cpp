#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

       int count = 0;
       int pre;
       vector<int>::iterator it = nums.begin();
       while(it != nums.end()){
       	if(it == nums.begin()){
       		pre = *it;
       		count++;
       		++it;
       		continue;
       	}
       	if(*it == pre){
       		if(count != 2){
       			count++;
       			++it;
       			continue;
       		}
       		if(count == 2){
       			vector<int>::iterator itt = it-1;
       			nums.erase(it);
       			it = itt+1;
       			continue;
       		}
       	}
       	else{
       		pre = *it;
       		count = 1;
       		++it;
       		continue;
       	}
       } 
       return nums.size();
    }
};

int main(int argc, char const *argv[])
{
	Solution* s = new Solution();
	vector<int> test = {1,1,1,2};
	cout<<s->removeDuplicates(test)<<endl;
	for(int i = 0; i<test.size();++i){
		cout<<test[i]<<endl;
	}
	return 0;
}