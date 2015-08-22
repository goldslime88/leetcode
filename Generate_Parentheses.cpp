#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		recurGenerate( "", n, 0 );
		return res;
    }
    void recurGenerate( string str, int left_to_add, int right_need ){
    	if(left_to_add == 0 && right_need == 0)
    	{
    		res.push_back(str);
    		return;
    	}
    	if(left_to_add > 0)
    	{
    		recurGenerate(str+'(', left_to_add-1, right_need+1);
    	}
    	if(right_need > 0)
    	{
    		recurGenerate(str+')', left_to_add, right_need-1);
    	}

    }

private:
	vector<string> res;
};

int main(int argc, char const *argv[])
{
	Solution* s = new Solution();
	vector<string> res = s->generateParenthesis(1);
	for(int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}