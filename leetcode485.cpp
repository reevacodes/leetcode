#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int maxi = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            count++;
            maxi = max(maxi, count);
        } else {
            count = 0;
        }
    }

    return maxi;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int result = findMaxConsecutiveOnes(nums);
    cout << "Maximum number of consecutive 1s: " << result << endl;

    return 0;
}
