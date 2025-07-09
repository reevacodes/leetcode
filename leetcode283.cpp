// MOVE ZEROES TO END

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int j = -1;

    // Step 1: Find first zero
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            j = i;
            break;
        }
    }

    // If no zero found, return
    if (j == -1) return;

    // Step 2: Swap non-zero with zero at position j
    for (int i = j + 1; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    for (int x : nums)
        cout << x << " ";

    return 0;
}
