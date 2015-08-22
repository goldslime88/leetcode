#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
    	string ans;
    	bool pre_zero = false;
    	string temp;
    	for (int i = 0; i < s.size(); ++i)
    	{
    		if( i == 0 && s[i] == ' ' )
    		{
    			pre_zero = true;
    		}
    		else if( i != 0 && s[i] == ' ' && pre_zero == true )
    		{
    			continue;
    		}
    		else if( i != 0 && s[i] != ' ' && pre_zero == true )
    		{
    			temp = "";
    			temp = temp + s[i];
    			pre_zero = false;
    		}
    		else if( i != 0 && s[i] == ' ' && pre_zero == false )
    		{
    			ans = ' ' + temp +ans;
    			pre_zero = true;
    			temp = "";
    		}
    		else if( i != 0 && s[i] != ' ' && pre_zero == false )
    		{
    			temp = temp + s[i];
    		}
    		else if( i == 0 && s[i] != ' ' && pre_zero == false )
    		{
    			temp = "";
    			temp = temp + s[i];
    		}
    	}

    	if(temp != "")
    	{
    		ans = temp + ans;
    	}
    	if(ans[0] == ' ')
    	{
    		ans.erase(0,1);
    	}
    	s = ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	string test = "  a  b  ";
	s->reverseWords(test);
	cout << test << endl;
	return 0;
}
