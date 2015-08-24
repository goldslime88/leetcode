#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector< vector<int> >& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();

        //x = y
        for( int i = 0; i < m; ++i ){
        	int temp_m = 0;
        	int temp_n = i;
        	while(temp_n > temp_m){
        		swap(matrix[temp_m][temp_n],matrix[temp_n][temp_m]);
        		temp_m++;
        		temp_n--;
        	}
        }
        for( int i = 0; i < m-1; ++i ){
        	int temp_m = 1+i;
        	int temp_n = m-1;
        	while(temp_n > temp_m){
        		swap(matrix[temp_m][temp_n],matrix[temp_n][temp_m]);
        		temp_m++;
        		temp_n--;
        	}

        }

        //y
        for( int j = 0; j < m; ++j ){
			for( int i = 0; i < n/2; ++i ){
				swap(matrix[j][i], matrix[j][n-1-i]);
			}        	
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector< vector<int> > matrix {{1,2,3},{4,5,6},{7,8,9}};
	s->rotate(matrix);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}