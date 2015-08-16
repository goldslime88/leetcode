#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if ( n <= 0)
        {
        	return false;
        }
        if ( n == 1 ){
        	return true;
        }
        else
        {
        	int temp = n;
        	while ( temp != 1)
        	{
        		if( temp%2 != 0 )
        		{
        			return false;
        		}
        		temp = temp/2;
        	}
        	return true;
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution* s = new Solution();
	cout<< s->isPowerOfTwo(16)<<endl;
	return 0;
}