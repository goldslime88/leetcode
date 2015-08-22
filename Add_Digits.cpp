class Solution {
public:
    int addDigits(int num) {
    	while( num/10 > 0 )
    	{
    		int temp = num;
    		int sum = 0;
    		while(temp>0){
    			sum = sum + temp%10;
    			temp = temp/10;
    		}
    		num = sum;

    	} 
    	return num;

    }
};