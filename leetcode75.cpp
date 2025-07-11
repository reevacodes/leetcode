// LEETCODE- 75
// SORT COLOURS

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (only 0s, 1s, and 2s): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sortColors(nums);

    cout << "Sorted colors: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
