#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int xorr = 0;
    for (int i = 0; i < nums.size(); i++) {
        xorr ^= nums[i];  // XOR with each element
    }
    return xorr;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = singleNumber(nums);
    cout << "The element that appears only once is: " << result << endl;
    return 0;
}
