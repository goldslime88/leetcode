#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct dep_index{
	int height;
	int index;
};

class Solution {
public:
    int trap(vector<int>& height) {
    	stack<dep_index> record;
    	int sum = 0;
    	for(int i = 0; i < height.size(); ++i){
    		//any empty means previous is clear
    		if( record.empty() ){
    			dep_index new_bar;
    			new_bar.height = height[i];
    			new_bar.index = i;
    			record.push(new_bar);
    			continue;
    		}
    		//record when this one is smaller than previous one
    		if(height[i] < record.top().height){
    			dep_index new_bar;
    			new_bar.height = height[i];
    			new_bar.index = i;
    			record.push(new_bar);
    			continue;
    		}
    		//when this one is large than previos
    		if(height[i] >= record.top().height){
    			int pre = 0;
    			//when the nearest in connect like concrete i - record.top().index - 1
    			//will be zero , thus it doesnt matter, but still need to update pre
    			//for boundary (pre is for record the level when in particular bar in stack)
    			//the while loop is for that when the bars in stack is min
    			while(!record.empty() && height[i] >= record.top().height){	
    				sum = sum + (i - record.top().index - 1) * (record.top().height - pre);
    				pre = record.top().height;
    				record.pop();
    			}
    			//check if the height[i] is min
    			if(!record.empty()){
    				sum = sum + (i - record.top().index - 1) * (height[i] - pre);
    			}
    			//add new one
    			dep_index new_bar;
    			new_bar.height = height[i];
    			new_bar.index = i;
    			record.push(new_bar);
    			continue;
    			
    		}
    	}
    	return sum;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> test = {4,2,3};
	cout<< s->trap(test)<<endl;
	return 0;
}

