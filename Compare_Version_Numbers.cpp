#include <iostream>
#include <string>
using namespace std;

struct strNode{
    string str;
    strNode* next;
    strNode() : str(""),next(NULL){}
};

class Solution {
public:
    Solution(){}
    int compareVersion(string version1, string version2) {
    	
        strNode *p1, *p2;
        p1 = splitString(version1);
        p2 = splitString(version2);

        while(p1 != NULL && p2 != NULL){
            int result = compareString(p1->str, p2->str);
            if(result == -1 || result == 1){
                return result;
            }
            else{
                p1 = p1->next;
                p2 = p2->next;
            }

        }

        if(p1 == NULL && p2 == NULL){
            return 0;
        }
        else if(p1 == NULL && p2 != NULL){            
            while(p2 != NULL){              
                if(p2->str != "")
                    return -1;
                p2 = p2->next;
            }
            return 0;
            
        }
        else{           
            while(p1 != NULL){              
                if(p1->str != "")
                    return 1;
                p1 = p1->next;
            }
            return 0;

        }
            
    }

    string removeBeginZero(string str){
        while(str[0]=='0'){
            str.erase(0,1);
        }
        return str;
    }

    int compareString(string str1, string str2){
        if(str1.size() > str2.size()){
            return 1;
        }
        else if(str1.size() < str2.size()){
            return -1;
        }
        else{
            if(str1 > str2)
                return 1;
            else if(str1 < str2)
                return -1;
            else
                return 0;
        }

    }

    strNode* splitString(string str){
        string strTemp = "";
        strNode* head = NULL; 
        strNode* current = NULL;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] != '.'){
                strTemp = strTemp + str[i];
            }
            else{
                
                strNode* newNode = new strNode();
                if(head == NULL){
                    head = newNode;
                }
                else{
                    current->next = newNode;
                }
                current = newNode;
                newNode->str = removeBeginZero(strTemp);
                strTemp = "";   
            }

        }

        if(strTemp != ""){
            strNode* newNode = new strNode();
            if(head == NULL){
                head = newNode;
            }
            else{
                current->next = newNode;
            }
            current = newNode;
            newNode->str = removeBeginZero(strTemp);
            strTemp = "";  

        }
        
        return head;

    }
};

int main(){
    Solution a;
    string str1="1";
    string str2="1.0";
    cout<< a.compareVersion(str1, str2) <<endl;
}