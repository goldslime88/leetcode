#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > generateMatrix(int n) {
        vector< vector<int> > ans(n, vector<int>(n,0));
        if(n==1){
        	ans[0][0] = 1;
        	return ans;
        }
        if(n==2){
        	ans[0][0] = 1;
        	ans[0][1] = 2;
        	ans[1][1] = 3;
        	ans[1][0] = 4;
        	return ans;
        }
        enum Direction {up, down, right, left};
        //i row, j column
        int val = 1;
        for(int i = 0; i < n ; ++i){
        	ans[0][i] = val;
        	val++;
        }
        for(int i = 1; i < n; ++i){
        	ans[i][n-1] = val;
        	val++;
        }
        for(int i = 1; i < n; ++i){
        	ans[n-1][n-1-i] = val;
        	val++;
        }
        for(int i = 1; i < n-1;++i){
        	ans[n-1-i][0] = val;
        	val++;
        }
        cout<<val<<endl;
        Direction dir = right;
        int i = 1, j = 0;
        while(val <= n*n){

        	if(dir == right){
        		if(ans[i][j+1] == 0){
              		ans[i][++j] = val;
        			val++;  			
        		}
        		else{
        			dir = down;
        		}
        		continue;
        	}
        	if(dir == down){
        		if(ans[i+1][j] == 0){
              		ans[++i][j] = val;
        			val++;  			
        		}
        		else{
        			dir = left;
        		}
        		continue;
        	}
        	if(dir == left){
        		if(ans[i][j-1] == 0){
              		ans[i][--j] = val;
        			val++;  			
        		}
        		else{
        			dir = up;
        		}
        		continue;
        	}
        	if(dir == up){
        		if(ans[i-1][j] == 0){
              		ans[--i][j] = val;
        			val++;  			
        		}
        		else{
        			dir = right;
        		}
        		continue;
        	}
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector< vector<int> > ans;
	ans = s->generateMatrix(5);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans.size(); j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}