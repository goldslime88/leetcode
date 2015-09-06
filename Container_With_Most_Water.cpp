#include <iostream>
#include <vector>
using namespace std;
//natural container
class MySolution {
public:
    int maxArea(vector<int>& height) {
    	if(height.size() == 0){
    		return 0;
    	}
        vector<int> max_area( height.size(), 0 );
        for(int i = 1; i < height.size(); ++i){
        	if(height[i] <= height[i-1]){
        		max_area[i] = max_area[i-1] + height[i];
        	}
        	else{
        		int temp = 0;
        		int temp_index = 0;
        		int larger_height = 0;
        		for(int j = i-1; j >= 0; --j){
        			if(height[j] > height[i]){
        				temp = height[i];
        				temp_index = j;
        				break;
        			}
        			if(height[j]>temp && height[j] <= height[i]){
        				temp = height[j];
        				temp_index = j;
        				if(temp >= height[i]-1){
        					break;
        				}
        			}
        		}
        		max_area[i] = max_area[temp_index] + (i - temp_index)*temp;
        	}
        }

        return max_area[height.size()-1];
    }
};

//choose two board; time limit exceed
class aSolution {
public:
    int maxArea(vector<int>& height) {
    	if(height.size() == 0){
    		return 0;
    	}
        int max_area = 0;
        for(int i = 1; i < height.size(); ++i){
        	
    		for(int j = i-1; j >= 0; --j){
    			int area = (i-j)*(height[i]<height[j]?height[i]:height[j]);
    			if(area > max_area){
    				max_area = area;
    			}
    		}
        }

        return max_area;        
    }
};

//shrink from two sides, O(n)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1, max_area = 0;
        while(i<j){
        	max_area = max( max_area, (j-i)*min(height[i],height[j]) );
        	if(height[i] >=height[j]){
        		j--;
        	}
        	else{
        		i++;
        	}
        }
        return max_area;
    }
};


int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> test{1,2,3,4};
	cout<< s->maxArea(test)<<endl;
	return 0;
}