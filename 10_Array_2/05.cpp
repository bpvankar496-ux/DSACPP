//Buy & Sell Stocks
//time compl.=O(n+n)=>O(2n)=>O(n)
//METHOD 1
#include <iostream>
#include <climits>
using namespace std;

//(int price[],int n )
void maxProffit(int *price,int n ){
int bestBuy[100000];
 bestBuy[0]=INT_MAX;

for(int i=1;i<n;i++){
bestBuy[i]=min(bestBuy[i-1],price[i-1]);
   // cout<<bestBuy[i]<<",";

}
int maxProfit=0;
for(int i=0;i<n;i++){
    int currProfit=price[i]-bestBuy[i];
    maxProfit=max(maxProfit,currProfit);
    //cout << currProfit << ",";

}

 cout<<"max profit ="<<maxProfit<<endl;

}

int main() {
    int prices[6] = {7,1,5,3,6,4};
    int n = sizeof(prices) / sizeof(int);

    maxProffit(prices,n);

    return 0;
}

//METHOD 2 SIMPLE
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int price[] = {7,1,5,3,6,4};
    int n = 6;

    int minPrice = INT_MAX;   // sauthi ochho price
    int maxProfit = 0;

    for(int i = 0; i < n; i++) {
        if(price[i] < minPrice) {
            minPrice = price[i];   // buy here
        }

        int profit = price[i] - minPrice; // sell here

        if(profit > maxProfit) {
            maxProfit = profit;
        }
    }

    cout << "Max Profit = " << maxProfit << endl;

    return 0;
}

//ANS:=
//Max Profit = 5