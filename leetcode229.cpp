// MAJORITY ELEMENT II (>n/3)

// Brute force

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<int> majorityElement(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> res;

//     for (int i = 0; i < n; i++) {
//         int count = 0;
//         if (find(res.begin(), res.end(), nums[i]) != res.end())
//             continue;

//         for (int j = 0; j < n; j++) {
//             if (nums[j] == nums[i])
//                 count++;
//         }

//         if (count > n / 3)
//             res.push_back(nums[i]);
//     }

//     sort(res.begin(), res.end());
//     return res;
// }

// int main() {
//     vector<int> nums = {1, 2, 3, 1, 1};
//     vector<int> result = majorityElement(nums);

//     cout << "Brute Force Output: ";
//     for (int num : result)
//         cout << num << " ";
//     cout << endl;

//     return 0;
// }


// Better soln

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;

// vector<int> majorityElement(vector<int>& nums) {
//     unordered_map<int, int> freq;
//     vector<int> res;
//     int n = nums.size();

//     for (int num : nums)
//         freq[num]++;

//     for (auto it : freq) {
//         if (it.second > n / 3)
//             res.push_back(it.first);
//     }

//     sort(res.begin(), res.end());
//     return res;
// }

// int main() {
//     vector<int> nums = {1, 2, 3, 1, 1};
//     vector<int> result = majorityElement(nums);

//     cout << "Better (HashMap) Output: ";
//     for (int num : result)
//         cout << num << " ";
//     cout << endl;

//     return 0;
// }


// Optimal soln

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int el1 = INT_MIN, el2 = INT_MIN;
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && nums[i] != el2) {
            cnt1 = 1;
            el1 = nums[i];
        } else if (cnt2 == 0 && nums[i] != el1) {
            cnt2 = 1;
            el2 = nums[i];
        } else if (nums[i] == el1) {
            cnt1++;
        } else if (nums[i] == el2) {
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el1) cnt1++;
        else if (nums[i] == el2) cnt2++;
    }

    vector<int> res;
    if (cnt1 > n / 3) res.push_back(el1);
    if (cnt2 > n / 3) res.push_back(el2);

    sort(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1};
    vector<int> result = majorityElement(nums);

    cout << "Optimal (Boyer-Moore) Output: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
