// NEXT PERMUTATION

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int ind = -1;

    // Step 1: Find breaking point
    for(int i = n - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            ind = i;
            break;
        }
    }

    // Step 2: If no breaking point, reverse and return      //REMEMBER THIS ONE
    if(ind == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find element just greater than nums[ind]
    for(int i = n - 1; i > ind; i--) {
        if(nums[i] > nums[ind]) {
            swap(nums[i], nums[ind]);
            break;
        }
    }

    // Step 4: Reverse right half
    reverse(nums.begin() + ind + 1, nums.end());
}

int main() {
    vector<int> nums = {3, 2, 1};
    nextPermutation(nums);

    cout << "Next permutation: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
