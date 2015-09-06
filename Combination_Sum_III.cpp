#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector< vector<int> > combinationSum3(int k, int n) {
        vector<int> combine;
        recurCombine(combine, 0, 0, k, n);
        return ans;
    }
    void recurCombine(vector<int>& combine, int max, int sum, int k, int n){
    	if(combine.size() == k && sum == n){
    		ans.push_back(combine);
    		return;
    	}
    	for(int i = max + 1; i < 10; ++i){
    		sum = sum + i;
    		combine.push_back(i);
    		recurCombine(combine, i, sum, k, n);
    		sum = sum - i;
    		combine.pop_back();
    	}

    	return;

    }
private:
	vector< vector<int> > ans;
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector< vector<int> > ans = s->combinationSum3(3, 9);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<"[";
		for (int j = 0; j < ans[0].size(); ++j)
		{
			cout<<ans[i][j]<<",";
		}
		cout<<"]"<<endl;
	}
	return 0;
}