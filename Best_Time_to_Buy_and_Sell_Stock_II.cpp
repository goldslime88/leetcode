#include <iostream>
#include <vector>
#include <array>


int maxProfit(std::vector<int> &prices) {
	int haveBuy = -1;
	int profit = 0;
	int i = 0;
	if(prices.size() == 0){
		return 0;
	}
	while(1){
		if(i == prices.size()-1){
			if(haveBuy != -1){
				profit += prices[i] - haveBuy;
			}
			break;

		}
		if(prices[i] < prices[i+1] && haveBuy == -1){
			haveBuy = prices[i];
			++i;
		}
		else if(prices[i] > prices[i+1] && haveBuy != -1 ){
			profit += prices[i] - haveBuy;
			haveBuy = -1;
			++i;
		}
		else{
			++i;
		}

	}

	return profit;        
}


int main(){
	int pricelist[] = {};
	std::vector<int> prices (pricelist, pricelist + sizeof(pricelist) / sizeof(int));
	std::cout<< maxProfit(prices) <<std::endl;


}