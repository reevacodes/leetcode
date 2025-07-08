// 3sum 
// Brute force

// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// using namespace std;

// vector<vector<int>> threeSum(vector<int>& nums) {
//     set<vector<int>> st;
//     int n = nums.size();

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             for (int k = j + 1; k < n; k++) {
//                 if (nums[i] + nums[j] + nums[k] == 0) {
//                     vector<int> temp = {nums[i], nums[j], nums[k]};
//                     sort(temp.begin(), temp.end());  // sort to ensure uniqueness
//                     st.insert(temp);
//                 }
//             }
//         }
//     }

//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// int main() {
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;

//     vector<int> nums(n);
//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     vector<vector<int>> result = threeSum(nums);

//     cout << "Triplets that sum to 0:\n";
//     for (auto triplet : result) {
//         for (int num : triplet) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// Better
// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// using namespace std;

// vector<vector<int>> threeSum(vector<int>& nums) {
//     set<vector<int>> st;
//     int n = nums.size();

//     for (int i = 0; i < n; i++) {
//         set<int> hashset;
//         for (int j = i + 1; j < n; j++) {
//             int third = -(nums[i] + nums[j]);
//             if (hashset.find(third) != hashset.end()) {
//                 vector<int> temp = {nums[i], nums[j], third};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(nums[j]);
//         }
//     }

//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// int main() {
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;

//     vector<int> nums(n);
//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     vector<vector<int>> result = threeSum(nums);

//     cout << "Triplets that sum to 0:\n";
//     for (auto triplet : result) {
//         for (int num : triplet) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


// Optimal

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicates

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1]) j++;  // skip duplicates
                while (j < k && nums[k] == nums[k + 1]) k--;  // skip duplicates
            }
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets that sum to 0:\n";
    for (auto triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
