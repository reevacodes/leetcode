// PRINT THE MATRIX IN SPIRAL ORDER

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();        // number of rows
    int m = matrix[0].size();     // number of columns
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    vector<int> ans;

    while (top <= bottom && left <= right) {
        // 1. Left → Right
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // 2. Top → Bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // 3. Right → Left (only if still rows left)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // 4. Bottom → Top (only if still columns left)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral order of the matrix:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
