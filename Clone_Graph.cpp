#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if(node == NULL){
    		return NULL;
    	}
        stack< UndirectedGraphNode* > dfs_origin;
        dfs_origin.push(node);
        stack< UndirectedGraphNode* > dfs_copy;
        UndirectedGraphNode* new_head = new UndirectedGraphNode(node->label);
        dfs_copy.push(new_head);
        unordered_map<int, UndirectedGraphNode*> record;
        record[node->label] = new_head;

        while(!dfs_origin.empty()){
        	UndirectedGraphNode* n_origin = dfs_origin.top();
        	dfs_origin.pop();
        	UndirectedGraphNode* n_copy = dfs_copy.top();
        	dfs_copy.pop();

        	for(int i = 0; i < (n_origin->neighbors).size(); ++i){
        		UndirectedGraphNode* temp = (n_origin->neighbors)[i];
        		if(record.find(temp->label) == record.end()){
        			UndirectedGraphNode* new_node = new UndirectedGraphNode(temp->label);
        			record[temp->label] = new_node;
        			(n_copy->neighbors).push_back(new_node);
        			dfs_copy.push(new_node);
        			dfs_origin.push(temp);
        		}
        		else{
        			(n_copy->neighbors).push_back(record[temp->label]);

        		}
        	}
        }

        return new_head;

    }
};