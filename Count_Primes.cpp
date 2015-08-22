#include <iostream>
#include <complex>
#include <vector>
using namespace std;
// time limited exceed
class MySolution {
public:
    int countPrimes(int n) 
    {
        if ( n <= 1 )
        {
        	return 0;
        }
        if ( n == 2 )
        {
        	return 1;
        }
        int ans = 1;
        for( int i = 3; i < n; i = i + 2 )
        {
        	if(isPrime(i))
        	{
        		++ ans;
        	}
        }
        return ans;
    }

    bool isPrime(int n )
    {
    	if ( n <= 1)
    	{
    		return false;
    	}
    	int up_level = sqrt(n) + 1;
    	for ( int i = 2; i <= up_level; ++i )
    	{
    		if( n%i == 0){
    			return false;
    		}
    	}
    	return true;
    }
};

class Solution{
public:
	int countPrimes(int n) 
    {
        vector<bool> prime_record( n, true );
        prime_record[0] = false;
        prime_record[1] = false;
        for( int i = 2; i < sqrt(n); ++i )
        {
        	if(prime_record[i])
        	{
        		for( int j = i*i; j < n; j = j + i )
        		{
        			prime_record[j] = false;
        		}
        	}
        }
        return count(prime_record.begin(), prime_record.end(), true);
    }
};



















