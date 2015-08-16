#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
struct indexPair
{
    int a;
    int b;
};

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
    	unordered_map< int, vector<indexPair> > sumSet;
    	for(int i = 0; i < num.size(); ++i){
    		for(int j = i+1; j < num.size(); ++j){
                    int temp = -num[i]-num[j];
                    unordered_map< int, vector<indexPair> >::iterator it = sumSet.find(temp);
                    if(it == sumSet.end()){
                        indexPair tempP;
                    
                        tempP.a = i;
                        tempP.b = j;   
                        vector<indexPair> tempV;
                        tempV.push_back(tempP);
                        sumSet[temp] = tempV;
                    }
                    else{
                        indexPair tempP;
                        tempP.a = i;
                        tempP.b = j;
                        (it->second).push_back(tempP);
                    }
    			
    		}
    	}

        for(int i = 0; i < num.size(); ++i){
            unordered_map< int, vector<indexPair> >::iterator it = sumSet.find(num[i]);
            if(it != sumSet.end()){
                for(int j = 0; j < (it->second).size(); ++j){
                    if(i!= (it->second)[j].a && i!= (it->second)[j].b){
                        vector<int> t;
                        t.push_back(num[i]);
                        t.push_back(num[(it->second)[j].a]);
                        t.push_back(num[(it->second)[j].b]);
                        sort(t.begin(), t.end());
                        ans.push_back(t);
                    }
                }
            }
        }
        vector<vector<int> > Ans;
        set<int> pool;
        for(int i = 0; i < ans.size(); ++i){
            int tem = 26*26*ans[i][0]+26*ans[i][1]+ans[i][2];
            set<int>::iterator it = pool.find(tem);
            if(it == pool.end()){
                pool.insert(tem);
                Ans.push_back(ans[i]);
            }

        }



        return Ans;


        
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