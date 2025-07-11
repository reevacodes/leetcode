// MAXIMUM SUM SUBARRAY
// KADANE ALGORITHM

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;  // Holds the overall max sum
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > maxi) {
                maxi = sum;
            }
            // Reset sum if it becomes negative
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = sol.maxSubArray(nums);
    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}
