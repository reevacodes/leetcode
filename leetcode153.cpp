// FIND MINIMUM IN ROTATED ARRAY

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int mini = INT_MAX;

    while (low <= high) {
        int mid = (low + high) / 2;

        // If the left part is sorted
        if (nums[low] <= nums[mid]) {
            mini = min(mini, nums[low]);
            low = mid + 1;
        } 
        // Right part is sorted
        else {
            mini = min(mini, nums[mid]);
            high = mid - 1;
        }
    }

    return mini;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element is: " << findMin(nums) << endl;
    return 0;
}
