#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generate(int start, int k, int n, vector<int>& ds, vector<vector<int>>& ans) {
        // Base case: combination size is k
        if(ds.size() == k) {
            if(n == 0) ans.push_back(ds); // sum matches
            return;
        }

        for(int i = start; i <= 9; i++) {
            if(i > n) break; // pruning: no need to continue if i > remaining sum
            ds.push_back(i);
            generate(i + 1, k, n - i, ds, ans); // pick i, reduce remaining sum
            ds.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        generate(1, k, n, ds, ans); // start numbers from 1
        return ans;
    }
};

int main() {
    Solution sol;
    int k, n;
    cout << "Enter number of elements (k): ";
    cin >> k;
    cout << "Enter target sum (n): ";
    cin >> n;

    vector<vector<int>> result = sol.combinationSum3(k, n);

    cout << "Combinations:\n";
    for(const auto &comb : result) {
        cout << "[ ";
        for(int num : comb) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
