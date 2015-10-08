#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {

        vector< vector<int> > ans;
        if(num.size() < 3){
            return ans;
        }
        sort(num.begin(), num.end());
        int i = 0;
        while(i < num.size()-2){
            int lead = num[i];
            int j = i + 1;
            int k = num.size()-1;
            while(j < k){
                int sum = lead + num[j] + num[k];
                if(sum == 0){
                    vector<int> sum_set = {num[i], num[j], num[k]};
                    ans.push_back(sum_set);

                    j = find_next(num, j);
                    k = find_pre(num, k);
                }
                else if(sum < 0){
                    ++j;
                }
                else{
                    --k;
                }
                
            }
            i = find_next(num, i);
        }

        return ans;

    }

    int find_next(vector<int> &num, int i){
        int temp = num[i];
        ++i;
        while(i < num.size() && temp == num[i]){
            ++i;
        }
        return i;
    }
    int find_pre(vector<int> &num, int i){
        int temp = num[i];
        --i;
        while(i>=0 && temp == num[i]){
            --i;
        }
        return i;
    }
};

int main(int argc, char const *argv[])
{
	Solution* a;
	a = new Solution();
    vector<int> test;
    test.push_back(-1);
    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(-1);
    test.push_back(-4);
    vector<vector<int> > ans = a->threeSum(test);
    for(int i = 0; i< ans.size(); ++i){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;

    }
	return 0;
}