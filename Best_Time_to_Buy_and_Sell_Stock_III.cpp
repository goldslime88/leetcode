#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//two side dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.empty()){
    		return 0;
    	}
    	if(prices.size() == 1){
    		return 0;
    	}
    	if(prices.size() == 2){
    		if(prices[1]-prices[0] >= 0){
    			return prices[1]-prices[0];
    		}
    		else{
    			return 0;
    		}
    	}
        //from begin to end
        int size = prices.size();
        vector<int> begin_end(size, 0);
        begin_end[0] = 0;
        int min = prices[0];
        int profit = 0;
        for(int i = 1; i < size; ++i){
        	if(prices[i] - min > profit){
        		profit = prices[i] - min;
        		begin_end[i] = profit;
        	}
        	else{
        		begin_end[i] = profit;
        	}

        	if(prices[i] < min){
        		min = prices[i];
        	}
        }

        vector<int> end_begin(size, 0);
        end_begin[size-1] = 0;
        int max = prices[size-1];
        profit = 0;
        for(int i = size-2; i >= 0; --i){
        	if(max - prices[i]  > profit){
        		profit = max - prices[i];
        		end_begin[i] = profit;
        	}
        	else{
        		end_begin[i] = profit;
        	}

        	if(prices[i] > max){
        		max = prices[i];
        	}
        }

        for(int i = 0; i < begin_end.size(); ++i){
        	cout<<begin_end[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i < end_begin.size(); ++i){
        	cout<<end_begin[i]<<" ";
        }
        cout<<endl;

        int max_profit = 0;
        for(int i = 0; i < size - 1; ++i){
        	int temp = begin_end[i] + end_begin[i+1];
        	if(temp > max_profit){
        		max_profit = temp;
        	} 
        }
        int max_other = begin_end[size-1]>end_begin[0]?begin_end[size-1]:end_begin[0];

        return max_other>max_profit?max_other:max_profit;
    }
};


int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> test = {1,2,4};
	cout<<s->maxProfit(test);
	return 0;
}