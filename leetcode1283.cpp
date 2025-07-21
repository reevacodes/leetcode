// FIND THE SMALLEST DIVISOR GIVEN A THRESHOLD

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool ifPossible(vector<int>& nums, int div, int threshold) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += (nums[i] + div - 1) / div;  // Efficient ceiling without float
    }
    return sum <= threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        maxi = max(maxi, nums[i]);
    }

    int low = 1, high = maxi;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ifPossible(nums, mid, threshold))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    vector<int> nums = {21212, 10101, 12121};
    int threshold = 1000000;
    cout << "Smallest Divisor = " << smallestDivisor(nums, threshold) << endl;
    return 0;
}
