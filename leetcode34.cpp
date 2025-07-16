// FIRST AND LAST OCCURENCE

#include<iostream>
#include<vector>
using namespace std;

// Find first occurrence of target
int firstOccurrence(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
            first = mid;
            high = mid - 1; // search left side
        }
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return first;
}

// Find last occurrence of target
int lastOccurrence(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
            last = mid;
            low = mid + 1; // search right side
        }
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return last;
}

// Main function to return range
vector<int> searchRange(vector<int>& nums, int target) {
    int first = firstOccurrence(nums, target);
    int last = lastOccurrence(nums, target);
    if (first == -1) return {-1, -1};
    return {first, last};
}

int main() {
    vector<int> nums = {2, 4, 6, 8, 8, 8, 11, 13};
    int target = 8;

    vector<int> result = searchRange(nums, target);
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}