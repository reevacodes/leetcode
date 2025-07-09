// TRAPPING RAIN WATER

#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int l = 0, r = n - 1;
    int leftMax = 0, rightMax = 0;
    int total = 0;

    while (l < r) {
        if (height[l] <= height[r]) {
            if (height[l] < leftMax)
                total += leftMax - height[l];
            else
                leftMax = height[l];
            l++;
        } else {
            if (height[r] < rightMax)
                total += rightMax - height[r];
            else
                rightMax = height[r];
            r--;
        }
    }
    return total;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped Water: " << trap(height) << endl;
    return 0;
}
