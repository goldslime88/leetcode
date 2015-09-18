#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		
		vector<char> temp;
		for(int i = 0; i < 10; ++i){
			dict.push_back(temp);			
		}
		dict[2].push_back('a');
		dict[2].push_back('b');
		dict[2].push_back('c');
		dict[3].push_back('d');
		dict[3].push_back('e');
		dict[3].push_back('f');
		dict[4].push_back('g');
		dict[4].push_back('h');
		dict[4].push_back('i');
		dict[5].push_back('j');
		dict[5].push_back('k');
		dict[5].push_back('l');
		dict[6].push_back('m');
		dict[6].push_back('n');
		dict[6].push_back('o');
		dict[7].push_back('p');
		dict[7].push_back('q');
		dict[7].push_back('r');
		dict[7].push_back('s');
		dict[8].push_back('t');
		dict[8].push_back('u');
		dict[8].push_back('v');
		dict[9].push_back('w');
		dict[9].push_back('x');
		dict[9].push_back('y');
		dict[9].push_back('z');
		string now;
		vector<string> ans;
		if(digits == ""){
			return ans;
		}
		recurCombie(digits, 0, now, ans);
		return ans;

    }
    void recurCombie(const string& digits, int index, string& now, vector<string>& ans){
    	if(index >= digits.size()){
    		ans.push_back(now);
    		return;
    	}

    	int symbol = digits[index] - '0';
    	for(int i = 0; i < dict[symbol].size(); ++i){
    		now = now + dict[symbol][i];
    		recurCombie(digits, index+1, now, ans);
    		now.pop_back();
    	}

    }

private:
	vector< vector<char> > dict;

};