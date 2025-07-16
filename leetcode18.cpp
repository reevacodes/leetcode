// 4 SUM

// BRUTE FORCE

// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> fourSumBrute(vector<int>& nums, int target) {
//     int n = nums.size();
//     set<vector<int>> s;
//     sort(nums.begin(), nums.end());

//     for (int i = 0; i < n; i++) {
//         for (int j = i+1; j < n; j++) {
//             for (int k = j+1; k < n; k++) {
//                 for (int l = k+1; l < n; l++) {
//                     long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
//                     if (sum == target) {
//                         s.insert({nums[i], nums[j], nums[k], nums[l]});
//                     }
//                 }
//             }
//         }
//     }

//     return vector<vector<int>>(s.begin(), s.end());
// }

// int main() {
//     vector<int> nums = {1, 0, -1, 0, -2, 2};
//     int target = 0;

//     vector<vector<int>> res = fourSumBrute(nums, target);
//     for (auto &quad : res) {
//         for (int num : quad)
//             cout << num << " ";
//         cout << endl;
//     }

//     return 0;
// }


// OPTIMAL SOLN

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSumOptimal(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicates

            int k = j + 1;
            int l = n - 1;

            while (k < l) {
                long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    while (k < l && nums[k] == nums[k - 1]) k++;  // Skip duplicates
                    while (k < l && nums[l] == nums[l + 1]) l--;  // Skip duplicates
                }
                else if (sum < target) {
                    k++;
                }
                else {
                    l--;
                }
            }
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> res = fourSumOptimal(nums, target);
    for (auto &quad : res) {
        for (int num : quad)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
