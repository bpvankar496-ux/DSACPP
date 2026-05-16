// Question 2: Maximum Profit with Transaction Fee
// Stocks buy/sell karo maximum profit sathe — transaction fee lagse
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    int buy = -prices[0];  // stock kharidhi
    int sell = 0;          // stock nathi

    for (int i = 1; i < n; i++) {
        buy  = max(buy, sell - prices[i]);
        sell = max(sell, buy + prices[i] - fee);
    }
    return sell;
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << maxProfit(prices, fee) << endl;
    // 8
    return 0;
}

//ANS:=
//8