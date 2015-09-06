#include <iostream>
#include <vector>
using namespace std;

// time cost O(MN)
class MySolution {
public:
	MySolution(){
		ans = false;
	}
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        recurSearch(matrix, target, 0, 0, rows-1, cols-1);
        return ans;
    }
    void recurSearch(vector< vector<int> >& matrix, int target, int row_now, int col_now, 
    	int rows, int cols){
    	if(ans == true){
    		return;
    	}
    	if(matrix[row_now][col_now] == target){
    		ans = true;
    		return;
    	}
    	if(matrix[row_now][col_now] > target){
    		return;
    	}
    	if(row_now < rows){
    		recurSearch(matrix, target, row_now+1, col_now, rows, cols);
    	}
    	if(col_now < cols){
    		recurSearch(matrix, target, row_now, col_now+1, rows, cols);
    	}
    	return;
    }

private:
	bool ans;
};

class Solution {
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i = 0;
        int j = cols-1;
        while(i < rows && j >= 0){
        	if(matrix[i][j] == target){
        		return true;
        	}
        	else if (matrix[i][j] > target){
        		j--;
        	}
        	else{
        		i++;
        	}
        }
        return false;
    }
};