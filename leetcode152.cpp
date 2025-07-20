// MAXIMUM PRODUCT SUBARRAY

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int prefix = 1;
    int suffix = 1;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;

        prefix *= nums[i];
        suffix *= nums[n - 1 - i];

        maxi = max(maxi, max(prefix, suffix));
    }

    return maxi;
}

int main() {
    vector<int> nums = {2, 3, -2, 4}; // Example input
    cout << "Maximum product subarray: " << maxProduct(nums) << endl;
    return 0;
}
