#include <iostream>


class Solution {
public:
    int strStr(char *haystack, char *needle) {
    	char *pchar = haystack, *pchar1 = needle;
       	int index = 0;
       	int lenHaystack = 0, lenNeedle = 0;
    	if(haystack == NULL || needle ==NULL){
    		return -1;
    	}

    	if(*haystack == '\0' && *needle == '\0'){
    		return 0;
    	}

    	if(*haystack != '\0' && *needle == '\0'){
    		return 0;
    	}

    	while(*pchar != '\0'){
    		pchar++;
    		lenHaystack++;
    	}
   

    	while(*pchar1 != '\0'){
    		pchar1++;
    		lenNeedle++;
    	}


    	for(int i = 0; i <= lenHaystack - lenNeedle; ++i){
    		
    		
    		
			pchar = haystack + i;
			pchar1 = needle;
			while(*pchar != '\0' && *pchar1 != '\0' ){
				if(*pchar == *pchar1){
					pchar++;
					pchar1++;
				}
				else{
					break;
				}

			}
			if(*pchar1 == '\0'){
				return index;
			}
			else{
				index++;
			}
    		
    		
    		
    	}

    	return -1;
        
    }
};

int main(){
	Solution* a;
	a = new Solution();
	char haystack[5]={'j','o','h','n','\0'};
	char needle[3]={'o','h', '\0'};
	std::cout<<*haystack<<std::endl;
	std::cout<< a->strStr(haystack, needle)<<std::endl;

}