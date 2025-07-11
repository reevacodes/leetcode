// MINIMUM SIZE SUBARRAY SUM(Minimum subarray with a sum>=target)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int i = 0;
        int minLength = INT_MAX;

        for (int j = 0; j < n; j++) {
            sum += nums[j];

            // Shrink window while sum ≥ target
            while (sum >= target) {
                minLength = min(minLength, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};

int main() {
    Solution sol;
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    int result = sol.minSubArrayLen(target, nums);
    cout << "Minimum length subarray with sum ≥ target: " << result << endl;

    return 0;
}
