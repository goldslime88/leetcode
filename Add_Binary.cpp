#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    	if(a == "" && b != ""){
    		return b;
    	}
    	if(a != "" && b == ""){
    		return a;
    	}
    	if(a == "" && b == ""){
    		return "";
    	}

        string ra, rb, ans;
        ra = reverse(a);
        rb = reverse(b);
        string::iterator ita, itb;
        ita = ra.begin();
        itb = rb.begin();
        int flag = 0;
        int aint,bint;
        while(ita!=ra.end() && itb!=rb.end()){
            aint =(int)(*ita-'0');
            bint = (int)(*itb-'0');

            if(aint+bint == 0 && flag == 1){
                ans = ans + "1";
                flag = 0;
            }
            else if(aint+bint == 0 && flag == 0){
                ans = ans + "0";
                flag = 0;

            }
            else if(aint+bint == 1 && flag == 0){
                ans = ans + "1";
                flag = 0;
            }
            else if(aint+bint == 1 && flag == 1){
                ans = ans + "0";
                flag = 1;
            }
            else if(aint+bint == 2 && flag == 0){
                ans = ans + "0";
                flag = 1;
            }
            else if(aint+bint == 2 && flag == 1){
                ans = ans + "1";
                flag = 1;
            }
            ++ita;
            ++itb;


        }
        while(ita!=ra.end()){
            aint = (int)(*ita-'0');
            if(aint == 0 && flag == 0){
                ans = ans + "0";
                flag = 0;
            }
            else if(aint == 0 && flag == 1){
                ans = ans + "1";
                flag = 0;

            }
            else if(aint == 1 && flag == 0){
                ans = ans + "1";
                flag = 0;

            }
            else{
                ans = ans + "0";
                flag = 1;

            }
            ++ita;
        }

        while(itb!=rb.end()){
            bint = (int)(*itb-'0');
            if(bint == 0 && flag == 0){
                ans = ans + "0";
                flag = 0;
            }
            else if(bint == 0 && flag == 1){
                ans = ans + "1";
                flag = 0;

            }
            else if(bint == 1 && flag == 0){
                ans = ans + "1";
                flag = 0;

            }
            else{
                ans = ans + "0";
                flag = 1;

            }

            ++itb;
        }

        if(flag == 1){
            ans = ans + "1";

        }

        return reverse(ans);






    	
        
    
    }
    string reverse(string a){
        string ans;
        for(string::iterator it = a.begin(); it != a.end(); ++it){
            ans = *it + ans;

        }

        return ans;
    }
};

int main(){
    Solution *a;
    a = new Solution();
    string n1 = "1";
    string n2 = "1001";
    cout << a->addBinary(n1,n2)<<endl;

}