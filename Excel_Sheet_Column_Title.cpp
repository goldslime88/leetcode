#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	Solution(){}
    
    string convertToTitle(int n) {
     	string result;
        while(n > 26){
            result = char((n-1)%26 + 'A')+ result;
            n = (n-1)/26;


        }
        result = char(n-1+'A') + result; 
 
        return result;
    }
};

int main(){
	Solution a;
	cout<< a.convertToTitle(703)<<endl;
}