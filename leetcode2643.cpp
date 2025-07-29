// MAX NO. OF Is IN A ROW

#include <iostream>
#include <vector>
using namespace std;

// Custom lower bound to find index of first 1
int lowerBound(vector<int>& row) {
    int low = 0, high = row.size() - 1;
    int ans = row.size();  // default to size if 1 is not found

    while (low <= high) {
        int mid = (low + high) / 2;
        if (row[mid] == 1) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

// Solution class
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = 0;
        int rowIndex = 0;
        vector<int> ans;

        for (int i = 0; i < mat.size(); i++) {
            int firstIndex = lowerBound(mat[i]);
            int onesCount = mat[i].size() - firstIndex;

            if (onesCount > maxOnes) {
                maxOnes = onesCount;
                rowIndex = i;
            }
        }

        ans.push_back(rowIndex);
        ans.push_back(maxOnes);
        return ans;
    }
};

int main() {
    // Hardcoded input
    int n = 3, m = 4;
    vector<vector<int>> mat = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };

    Solution sol;
    vector<int> result = sol.rowAndMaximumOnes(mat);

    cout << "Row with maximum 1s: " << result[0] << ", Number of 1s: " << result[1] << endl;

    return 0;
}
