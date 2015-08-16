#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {

        vector<string> ans;
        if( nums.empty() )
        {
        	return ans;
        }
        int head, tail;
        for( int i = 0; i < nums.size(); ++i )
        {
        	if ( i == 0 )
        	{
        		head = nums[i];
        		tail = nums[i];
        	}
        	else
        	{
        		if ( nums[i]-tail == 1 )
        		{
        			tail = nums[i];
        		}
        		else
        		{
        			if ( head == tail )
        			{
        				ans.push_back( to_string(head) );
        			}
        			else
        			{
        				string str_head = to_string(head);
        				string str_tail = to_string(tail);
        				ans.push_back( str_head + "->" + str_tail );
        			}
        			head = nums[i];
        			tail = nums[i];	
        		}
        	}
        }
        if ( head == tail )
		{
			ans.push_back( to_string(head) );
		}
		else
		{
			string str_head = to_string(head);
			string str_tail = to_string(tail);
			ans.push_back( str_head + "->" + str_tail );
		}
		return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> test { -1, 0, 1, 2, 4, 8, 9 };
	vector<string> res = s->summaryRanges(test);
	for( int i = 0; i < res.size(); ++i )
	{
		cout<< res[i] << endl;
	}


	return 0;
}