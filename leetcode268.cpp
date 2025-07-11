#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int>& nums) {
    int n = nums.size();
    int xor1 = 0;
    int xor2 = 0;

    for (int i = 0; i < n; i++) {
        xor1 ^= nums[i];
        xor2 ^= (i + 1);  // range: 1 to n
    }

    return xor1 ^ xor2;
}

int main() {
    vector<int> nums = {3, 0, 1};  // Missing number is 2
    int missing = findMissingNumber(nums);
    cout << "Missing number: " << missing << endl;
    return 0;
}
