// FIND PEAK ELEMENT

#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int low = 1;
    int high = n - 2;

    if (n == 0) return -1;
    if (n == 1) return 0;
    if (n == 2) return nums[0] > nums[1] ? 0 : 1;
    if (nums[0] > nums[1]) return 0;
    if (nums[n - 1] > nums[n - 2]) return n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        else if (nums[mid] < nums[mid + 1])  // Increasing slope
            low = mid + 1;
        else  // Decreasing or flat
            high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};  // Example input
    int peakIndex = findPeakElement(nums);
    cout << "Peak element is at index: " << peakIndex << endl;
    return 0;
}
