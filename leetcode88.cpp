// MERGE SORTED ARRAYS

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int left = 0, right = 0;
    vector<int> nums3;

    while (left < m && right < n) {
        if (nums1[left] <= nums2[right]) {
            nums3.push_back(nums1[left]);
            left++;
        } else {
            nums3.push_back(nums2[right]);
            right++;
        }
    }

    while (left < m) {
        nums3.push_back(nums1[left++]);
    }

    while (right < n) {
        nums3.push_back(nums2[right++]);
    }

    for (int i = 0; i < m + n; i++) {
        nums1[i] = nums3[i];
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }

    return 0;
}
