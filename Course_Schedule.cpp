#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
using namespace std;


//topological sort
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector< vector<int> > node;
        for(int i = 0; i < numCourses; ++i){
            vector<int> temp;
            node.push_back(temp);
        }
        for(int j = 0; j < prerequisites.size(); ++j){
            int index = prerequisites[j].first;
            int link = prerequisites[j].second;
            node[index].push_back(link);
        }
        vector<bool> mark_node(numCourses, false);
        stack<int> record;
        record

    }
};



//it's non-directed check loop, not for this probelm
class mySolution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector< vector<int> > node;
        for(int i = 0; i < numCourses; ++i){
        	vector<int> temp;
        	node.push_back(temp);
        }
        for(int j = 0; j < prerequisites.size(); ++j){
        	int index = prerequisites[j].first;
        	int link = prerequisites[j].second;
        	node[index].push_back(link);
        }
        queue<int> record;
        record.push(0);
        set<int> node_set;
        while(!record.empty()){
        	int temp = record.front();
        	record.pop();
        	if(node_set.find(temp) != node_set.end()){
        		return false;
        	}
        	else{
        		node_set.insert(temp);
        	}
        	for(int i = 0; i < node[temp].size(); ++i){
        		record.push(node[temp][i]);
        	}

        }

        return true;

    }
};