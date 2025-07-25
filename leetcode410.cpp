// SPLIT ARRAY LARGEST SUM

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of parts (subarrays) required
// such that the maximum subarray sum is less than or equal to mid
int cntParts(vector<int> &nums, int mid) {
    int parts = 1;
    int currentSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (currentSum + nums[i] > mid) {
            parts++;
            currentSum = nums[i];
        } else {
            currentSum += nums[i];
        }
    }
    return parts;
}

// Function to find the minimum possible largest subarray sum when splitting into k parts
int splitArray(vector<int> &nums, int k) {
    int n = nums.size();
    int maxi = INT_MIN, sum = 0;

    for (int i = 0; i < n; i++) {
        maxi = max(maxi, nums[i]);
        sum += nums[i];
    }

    int low = maxi, high = sum, ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        int parts = cntParts(nums, mid);

        if (parts > k) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << "Minimum possible largest subarray sum: " << splitArray(nums, k) << endl;
    return 0;
}
