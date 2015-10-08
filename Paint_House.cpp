#include <vector>
#include <algorithm>
using namespace std;


//if this one can pick the lowest pick it, if not try second lowet + before or 
//lowest + changed before(not efficient!!)
//0 is 0 + min(pre[1],pre[2]), 1 is 1 + min(pre[0],pre[2])...
class Solution {
public:
    int minCost(vector< vector<int> >& costs) {
        if(costs.empty()){
        	return 0;
        }

        vector< vector<int> > dp_cost(costs.size(), vector<int>(3,0));
        dp_cost[0][0] = costs[0][0];
        dp_cost[0][1] = costs[0][1];
        dp_cost[0][2] = costs[0][2];
        for(int i = 1; i < dp_cost.size(); ++i){
        	dp_cost[i][0] = costs[i][0] + min(dp_cost[i-1][1],dp_cost[i-1][2]);
        	dp_cost[i][1] = costs[i][1] + min(dp_cost[i-1][0],dp_cost[i-1][2]);
        	dp_cost[i][2] = costs[i][2] + min(dp_cost[i-1][0],dp_cost[i-1][1]);
        }
        int temp = dp_cost.size() - 1;
        return min(min(dp_cost[temp][0], dp_cost[temp][1]), dp_cost[temp][2]);


    }

};