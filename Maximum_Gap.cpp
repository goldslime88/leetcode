#include <vector>
#include <iostream>
#include <unordered_map>
#include <limits>
using namespace std;



class Solution {
public:
    int maximumGap(vector<int>& nums) {
       if(nums.size() < 2){
         return 0;
       }
       int size = nums.size();
       int max = -1, min = INT_MAX;
       for(int i = 0; i < nums.size(); ++i){
       	if(nums[i] >= max){
       		max = nums[i];
       	}
       	if(nums[i] <= min ){
       		min = nums[i];
       	}
       }
       cout<<max<<endl;
       cout<<min<<endl;
       int bucket_size = (max - min)/size + 1;
       vector<int> min_array(size+1, INT_MAX);
       vector<int> max_array(size+1, -1);
       if(max == min){
       	return 0;
       }
       for(int i = 0; i < nums.size(); ++i){
       	int bucket_index = (nums[i] - min)/bucket_size;

       	if(nums[i] >= max_array[bucket_index]){
       		max_array[bucket_index] = nums[i];
       	}
       	if(nums[i] <= min_array[bucket_index]){
       		min_array[bucket_index] = nums[i];
       	}
       }
       cout<<"haha"<<endl;
	   	int max_gap = 0;
	   	int pre_max = -1;
	   	for(int i = 0; i < size+1; ++i){
	   		if(min_array[i] == INT_MAX && max_array[i] == -1){
	   			continue;
	   		}
	   		else{
	   			if(pre_max == -1){
	   				pre_max = max_array[i];
	   				continue;
	   			}
	   			else{
	   				int temp_max_gap = min_array[i] - pre_max;
	   				if(temp_max_gap >= max_gap){
	   					max_gap = temp_max_gap;
	   				}
	   				pre_max = max_array[i];
	   			}
	   		}
	   	}
       	return max_gap;
       


    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> test = {1,1,1,1,1,5,5,5,5,5};
	cout<<s->maximumGap(test)<<endl;
	return 0;
}

// wrong understanding it's maximum successive 
class mySolution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2){
        	return 0;
        }
        int max_gap = 0;
        //the num and the max mum diff if it is the head or tail of the successive
        // elements
        unordered_map< int, int > record;
        for(int i = 0; i < nums.size(); ++i){
        	unordered_map< int, int >::iterator it = record.find(nums[i]);
        	unordered_map< int, int >::iterator it_pre = record.find(nums[i]-1);
        	unordered_map< int, int >::iterator it_next = record.find(nums[i]+1);
        	unordered_map< int, int >::iterator it_end = record.end();
        	if(it == it_end){
        		if(it_pre == it_end && it_next == it_end){
        			record[nums[i]] = 1;
        			if(record[nums[i]] > max_gap){
        				max_gap = record[nums[i]];
        			}
        		}
        		else if(it_pre != it_end && it_next == it_end){
        			record[nums[i]] = it_pre->second + 1;
        			record[nums[i] - it_pre->second] = it_pre->second + 1;
        			if(record[nums[i]] > max_gap){
        				max_gap = record[nums[i]];
        			}
        		}
        		else if(it_pre == it_end && it_next != it_end){
        			record[nums[i]] = it_next->second + 1;
        			record[nums[i] + it_next->second] = it_next->second + 1;
        			if(record[nums[i]] > max_gap){
        				max_gap = record[nums[i]];
        			}
        		}
        		else{
        			int total = it_pre->second + it_next->second + 1;
        			record[nums[i]] = total;
        			record[nums[i] - it_pre->second] = total;
        			record[nums[i] + it_next->second] = total;
        			if(record[nums[i]] > max_gap){
        				max_gap = record[nums[i]];
        			}
        		}
        	}
        	else{
        		continue;
        	}

        }

        return max_gap;

    }
};




