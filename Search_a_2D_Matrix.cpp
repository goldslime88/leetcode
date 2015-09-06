#include <iostream>
#include <vector>
using namespace std;
// binary search i<=j
class Solution {
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
        int i = 0, j = matrix.size()-1;
        if(matrix[0][0]>target){
        	return false;
        }
        while(i <= j){
        	int mid = (i+j)/2;
        	if(matrix[mid][0] == target){
        		return true;
        	}
        	if(matrix[mid][0] < target){
        		i = mid+1;
        	}
        	else{
        		j = mid-1;
        	}
        }

        int row = j;

        if(row < 0){
        	return false;
        }
        j = matrix[0].size()-1;
        i = 0;
        
        while(i <= j){
        	int mid = (i+j)/2;
        	if(matrix[row][mid] == target){
        		return true;
        	}
        	if(matrix[row][mid] < target){
        		i = mid+1;
        	}
        	else{
        		j = mid-1;
        	}
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector< vector<int> > test = {{1}};
	cout<<s->searchMatrix(test,2)<<endl;
	return 0;
}
