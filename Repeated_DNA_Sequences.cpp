#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences1(string s) {
    	unordered_map< string, int > record;
    	
    	vector<string> ans;
    	if(s.size() <= 10){
    		return ans;
    	}
    	string temp;
    	string::iterator tail;
    	for(int i = 0; i < 10; ++i){
    		temp = temp + s[i];
    	}

    	unordered_map< string, int>::iterator it;
    	tail = s.begin()+10;
    	while(tail != s.end()){
    		
    		it = record.find(temp);
    		if(it == record.end()){
    			record[temp] = 1;
    		}
    		else{
    			it->second = it->second + 1 ;
    		}
    		temp.erase(0,1);
    		temp = temp + *tail;
    		tail++;

    	}
    	if(it == record.end()){
    		record[temp] = 1;
    	}
    	else{
    		it->second = it->second + 1 ;
   		}

    	for(unordered_map< string, int >::iterator it = record.begin(); it != record.end(); ++it){
    		if(it->second > 1){
    			ans.push_back(it->first);
    		}
    		
    	}

    	return ans;

        
    }

    vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> r;
    int t = 0, i = 0, ss = s.size();
    while (i < 9)
        t = t << 3 | (s[i++] & 7);
    while (i < ss)
        if (m[t = (((t << 3) & 0x3FFFFFFF) | (s[i++] & 7))]++ == 1)
            r.push_back(s.substr(i - 10, 10));
    return r;
	}
};

int main(){
	Solution* a;
	a = new Solution();
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	vector<string> ans;
	ans = a->findRepeatedDnaSequences(s);
	for(vector<string>::iterator it = ans.begin(); it != ans.end(); ++it){
		cout<<*it<<endl;
	}

}