// SEARCH IN ROTATED ARRAY II

#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return true;

        // Handle duplicates: skip equal elements on both ends
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }

        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target <= nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } 
        // Right half is sorted
        else {
            if (target >= nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return false;
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    if (search(nums, target))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}
