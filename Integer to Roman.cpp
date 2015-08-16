#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        char* table[4][10] = {"","I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "", "X", "XX", "XXX", "XL","L", "LX","LXX", "LXXX", "XC", "", "C", "CC", "CCC", "CD","D", "DC","DCC", "DCCC", "CM", "", "M", "MM", "MMM","","","","","",""};
        string ans;
        int i = 0;
        while(num != 0){
        	ans = table[i][(num%10)] + ans;
        	num = num/10;
        	i++;

        }

        return ans;

    }
};

int main(){
	Solution *a;
	a = new Solution();
	cout << a->intToRoman(28)<<endl;
}