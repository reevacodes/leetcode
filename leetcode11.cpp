// LEETCODE-11
// container_w_max_water

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int maxWater = 0; 
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int width = right - left;
        int ht = min(height[left], height[right]);
        int curWater = width * ht;
        maxWater = max(maxWater, curWater);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = maxArea(height);
    cout << "Maximum water that can be contained: " << result << endl;

    return 0;
}
