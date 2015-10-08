#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class WordDistance {
public:
    WordDistance(vector<string>& words) {
        
        for (int i = 0; i < words.size(); ++i)
        {
        	if(record.find(words[i]) == record.end()){
        		vector<int> temp;
        		temp.push_back(i);
        		record[words[i]] = temp; 
        	}
        	else{
        		record[words[i]].push_back(i);
        	}
        }
        size = words.size();
    }

    int shortest(string word1, string word2) {
        vector<int> word1_index = record[word1];
        vector<int> word2_index = record[word2];
        int min = size;
        for(int i = 0; i < word1_index.size(); ++i){
        	for(int j = 0; j < word2_index.size(); ++j){
        		int temp = word1_index[i] - word2_index[j];
        		if(temp < 0){
        			temp = -temp;
        		}
        		if(temp < min){
        			min = temp;
        		}
        	}
        }
        return min;

    }

private:
	unordered_map< string, vector<int> > record;
	int size;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");