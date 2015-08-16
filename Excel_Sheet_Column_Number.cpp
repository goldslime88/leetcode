#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Solution {
public:
	Solution(){}
    int titleToNumber(string s) {
    	int num = 0, sum = 0;
    	for(int i = s.size()-1; i >= 0 ; --i){
    		sum += int(s[i]-'A'+1)*pow(26,num);
    		num++;

    	}
    	return sum;
        
    }
};

int main(){
	Solution *a;
	a = new Solution();
	cout << a->titleToNumber("AAA")<<endl;

}