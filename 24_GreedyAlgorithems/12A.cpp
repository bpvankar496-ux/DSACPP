//Question 4: Best Time to Buy and Sell Stock==>think greedy style system
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int profit = 0;

    for(int i = 1; i < prices.size(); i++) {
        profit = max(profit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }

    return profit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Output: " << maxProfit(prices) << endl;
    return 0;
}
//ANS:=
//Output: 5