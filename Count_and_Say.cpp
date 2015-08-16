#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
	if(n == 0){
		return "false";
	}
	else if(n == 1){
		return "1";
	}
	else{
		
		string str = countAndSay(n-1);
		char tmp = str[0];
		string result;
		int count = 0;

		for (int i = 0; i < str.size(); ++i){

			if(tmp == str[i]){
				count++;
				if(i == str.size()-1){
					result.push_back(char('0'+count));
				    result.push_back(tmp);
				}
			}
			else{
				result.push_back('0'+count);
				result.push_back(tmp);
				count = 1;
				tmp = str[i];
				if(i == str.size()-1){
					result.push_back(char('0'+count));
				    result.push_back(tmp);
				}
			}

		}
		return result;
	}
}

int main(){
	cout<< countAndSay(5)<<endl;
}