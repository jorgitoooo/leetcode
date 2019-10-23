/* ---------------
 * Jorge L. Garcia
 * //2019
 * ---------------
 * Best time to
 * buy and sell
 * a stock I
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
	if(prices.size() < 2) return 0;

	int buy, sell, max, profit;        

	buy = prices[0];
	sell = max = prices[1];

	profit = sell - buy;

	for(int i = 1; i < prices.size(); i++)
	{
		sell = prices[i];
		if(buy >= sell)
			buy = max = sell;
		else if(max < sell) {
			max = sell;
				
			if(profit < (sell - buy))
				profit = sell - buy;
		}
	}
	return profit > 0 ? profit : 0;
}

int main(int argc, char **argv)
{
	vector<int> prices0{7,1,5,3,6,4};
	vector<int> prices1{-1,4,-2,8};
	vector<int> prices2{-1,-3,-2,-5};
	vector<int> prices3{};
	vector<int> prices4{5,4,3,2,3,1};

	printf("Max profit: %d\n", maxProfit(prices0));
	printf("Max profit: %d\n", maxProfit(prices1));
	printf("Max profit: %d\n", maxProfit(prices2));
	printf("Max profit: %d\n", maxProfit(prices3));
	printf("Max profit: %d\n", maxProfit(prices4));

	return 0;
}
