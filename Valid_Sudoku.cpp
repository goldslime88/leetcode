#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	Solution(){

	}
    bool isValidSudoku(vector<vector<char> > &board) {
    	vector< set<int> > rowSet, colSet, sqrSet;
    	set<int> temp;
       	for(int i = 0; i < 9; i++){
    		rowSet.push_back(temp);
    		colSet.push_back(temp);
    		sqrSet.push_back(temp);
    	}
    	

    	for(int i = 0; i < 9; ++i){
    		for(int j = 0; j < 9; ++j){
    			if(board[i][j] != '.'){
					if(!isValid(rowSet[i], (int)(board[i][j])-'0'))
						return false;
					if(!isValid(colSet[j], (int)(board[i][j])-'0'))
						return false;
					if(i>=0&&i<=2&&j>=0&&j<=2){
						if(!isValid(sqrSet[0], (int)(board[i][j])-'0')){
							return false;
						}
					}
					if(i>=0&&i<=2&&j>=3&&j<=5){
						if(!isValid(sqrSet[1], (int)(board[i][j])-'0')){
							return false;
						}
					}
					if(i>=0&&i<=2&&j>=6&&j<=8){
						if(!isValid(sqrSet[2], (int)(board[i][j])-'0')){
							return false;
						}
					}
					if(i>=3&&i<=5&&j>=0&&j<=2){
						if(!isValid(sqrSet[3], (int)(board[i][j])-'0')){
							return false;
						}
					}
					if(i>=3&&i<=5&&j>=3&&j<=5){
						if(!isValid(sqrSet[4], (int)(board[i][j])-'0')){
							return false;
						}
					}
					if(i>=3&&i<=5&&j>=6&&j<=8){
						if(!isValid(sqrSet[5], (int)(board[i][j])-'0')){
							return false;
						}
					}
					if(i>=6&&i<=8&&j>=0&&j<=2){
						if(!isValid(sqrSet[6], (int)(board[i][j])-'0')){
							return false;
						}
					}
					if(i>=6&&i<=8&&j>=3&&j<=5){
						if(!isValid(sqrSet[7], (int)(board[i][j])-'0')){
							return false;
						}
					}
					if(i>=6&&i<=8&&j>=6&&j<=8){
						if(!isValid(sqrSet[8], (int)(board[i][j])-'0')){
							return false;
						}
					}






				}
    		}    
    	}

    	return true;



        
    }

    bool isValid(set<int> &A, int a){
    	set<int>::iterator it;
    	it = A.find(a);
    	if(it == A.end()){
    		A.insert(a);
			return true;

    	}
    	else{
    		return false;
    	}

    }
};

int main(){
	Solution *a;
	a = new Solution();
	vector<vector<char> > board;
	vector<char> temp;
	for(int i = 0; i < 9; ++i)
		temp.push_back('.');
	for(int i = 0; i < 9; ++i)
		board.push_back(temp);
	board[0][0] = '1';
	board[1][1] = '1';


	cout<<a->isValidSudoku(board)<<endl;


}