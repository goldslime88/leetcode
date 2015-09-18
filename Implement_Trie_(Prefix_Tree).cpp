#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(){

        isLeaf = false;

    }

    unordered_map< char, TrieNode* > children;
    char key;
    bool isLeaf;

};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* temp = root;
        int index = 0;
        
        while(index < word.size()){
            char temp_char = word[index];
            
            if((temp->children).find(temp_char) == (temp->children).end()){
                TrieNode* new_node = new TrieNode();
                new_node->key = temp_char;
                if(index == word.size()-1){
                    new_node->isLeaf = true;
                }
                (temp->children)[temp_char] = new_node;
                temp = new_node;
            }
            else{

                temp = (temp->children)[temp_char];
                if(index == word.size()-1){
                    temp->isLeaf = true;
                }

            }
            ++index;
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* temp = root;
        int index = 0;
        while(index < word.size()){
            char temp_char = word[index];
            
            if((temp->children).find(temp_char) == (temp->children).end()){
                return false;
            }
            else{
                temp = (temp->children)[temp_char];
            }
            ++index;
        }
        if(temp->isLeaf){
            return true;            
        }
        else{
            return false;
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        int index = 0;
        while(index < prefix.size()){
            char temp_char = prefix[index];
            
            if((temp->children).find(temp_char) == (temp->children).end()){
                return false;
            }
            else{
                temp = (temp->children)[temp_char];
            }
            ++index;
        }

        return true;
    }

private:
    TrieNode* root;
};

int main(int argc, char const *argv[])
{
    Trie trie;
    trie.insert("ab");
    trie.insert("door");
    cout<<trie.startsWith("ke")<<endl;
    return 0;
}
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");