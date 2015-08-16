#include <iostream>
using namespace std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	int maxLeft = max(A,E);
    	int minRight = min(C,G);
    	int maxDown = max(B,F);
    	int minUp = min(D,H);
    	if(maxLeft < minRight && maxDown < minUp){
    		return (C-A)*(D-B)+ (G-E)*(H-F) - (minRight-maxLeft)*(minUp - maxDown);
    	}
        return (C-A)*(D-B)+ (G-E)*(H-F);
    }

};

int main(int argc, char const *argv[])
{
	Solution *a = new Solution();
	cout << a->computeArea(-2, -2, 2, 2, -2, -2, 2, 2)<<endl;
	return 0;
}