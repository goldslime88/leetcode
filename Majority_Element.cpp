#include <vector>
#include <array>
#include <iostream>

#define maxInt 10000

class hashmap{
public:
    int number;
    int counter;
    bool used;

};

int majorityElement(std::vector<int> &num) {

    int numOfInt = 0;
    hashmap map[maxInt];

    for(int i = 0; i < maxInt; ++i){
        map[i].used = false;
    }

    for(std::vector<int>::iterator it = num.begin(); it != num.end(); ++it){
        int i = 0;
        for(i = 0; i < numOfInt; ++i){
            if(map[i].number == *it && map[i].used == true){
                map[i].counter++;
                break;
            }
        }
        if (i == numOfInt){
            map[i].number = *it;
            map[i].counter = 1;
            map[i].used = true;
            numOfInt++;
        }
    }
    
    for(int i = 0; i < numOfInt; ++i){
        if(map[i].counter > (num.size()/2)){
            return map[i].number;
        }
        
    }

    return -1;
}



int main(){

    int myints[] = {1,2,1,1,2,2,2,2};
    std::vector<int> num (myints, myints + sizeof(myints) / sizeof(int) );

    int majority = majorityElement(num);
   	std::cout << majority << std::endl;	
 
}

