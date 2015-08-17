#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map< char, char > char_map;
        set<char> used_char_set;
        if( s.size() != t.size() )
        {
        	return false;
        }

        for ( int i = 0; i < s.size(); ++i )
        {

        	unordered_map< char, char >::iterator it = char_map.find(s[i]);
        	if( it == char_map.end() )
        	{
        		if( used_char_set.find(t[i]) != used_char_set.end() )
		    	{
		    		return false;
		    	}
		    	else
		    	{
		    		used_char_set.insert(t[i]);
		    		char_map[s[i]] = t[i];
		    	}
        		
        	}
        	else
        	{
        		if( (char_map[s[i]]) != t[i] )
        		{
        			return false;
        		}
        	}
        }
        return true;
    }
};