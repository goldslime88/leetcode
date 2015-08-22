class Solution {
public:
    bool isHappy(int n) {
        int num = n;
        for ( int i = 0; i < 100; ++i)
        {
        	int temp = num;
        	int sum = 0;
        	while( temp/10 > 0 )
        	{
        		sum += (temp%10)*(temp%10);
        		temp = temp/10;
        	}
        	sum = sum + temp * temp;
        	num = sum;
        	if ( num == 1 )
        	{
        		return true;
        	}
        }

        return false;
    }
};