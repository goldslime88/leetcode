#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
    	int count = 0;
        int precount = 0;
        int flag = 0;
    	while(*s != '\0'){
    		if((*s <= 'Z' && *s >= 'A')||(*s <= 'z' && *s >= 'a')){
    			++count;
                flag = 1;
    		}
    		if(*s == ' '){
                if(flag == 1){
                    precount = count;
    			    count = 0;
                    flag = 0;
                }

    	    }

    		++s;

    	}
        if(count == 0){
            return precount;
        }
        else{
    	    return count;
        }

        
    }
};

int main(){
	Solution *a;
	a = new Solution();
    char s[]="aa   a a  bb   ";

	cout<< a->lengthOfLastWord(s)<<endl;
}