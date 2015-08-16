#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        const int x(m),y(n);
        int a[x][y];
        for(int i = 0; i < n; ++i){
            a[0][i] = 1;
        }
        for(int j = 0; j < m; ++j){
            a[j][0] = 1;
        }

        for(int j = 1; j < m; ++j){
            for(int i = 1; i < n; ++i){
                a[j][i]= a[j-1][i]+a[j][i-1];
            }
        }

        return a[m-1][n-1];

    }
};

int main(){
    Solution* a;
    a = new Solution();
    cout<<a->uniquePaths(36,7)<<endl;
}
