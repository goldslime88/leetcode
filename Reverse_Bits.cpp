
#include <stdint.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        uint32_t temp = n;
        for (int i = 0; i < 32; ++i)
        {
        	if(temp&0x00000001)
        	{
        		ans = (ans<<1)|0x00000001;
        	}
        	else
        	{
        		ans = ans<<1;
        	}
        	temp = temp>>1;
        }
        return ans;
    }
};