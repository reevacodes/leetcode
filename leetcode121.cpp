#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int mini = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++) {
        int profit = prices[i] - mini;
        maxProfit = max(maxProfit, profit);
        mini = min(mini, prices[i]);
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}
