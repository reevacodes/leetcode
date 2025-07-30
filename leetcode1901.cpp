// FIND A PEAK ELEMENT II

#include <bits/stdc++.h>
using namespace std;

// Function to find the row index with maximum value in the given column
int findRowInd(vector<vector<int>>& mat, int n, int col) {
    int index = -1;
    int maxValue = -1;
    for (int i = 0; i < n; i++) {
        if (mat[i][col] > maxValue) {
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}

// Main function to find a peak element in the 2D grid
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int rowInd = findRowInd(mat, n, mid);

        int left = (mid - 1 >= 0) ? mat[rowInd][mid - 1] : -1;
        int right = (mid + 1 < m) ? mat[rowInd][mid + 1] : -1;

        if (mat[rowInd][mid] > left && mat[rowInd][mid] > right) {
            return {rowInd, mid};
        }
        else if (mat[rowInd][mid] < left) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return {-1, -1}; // should never be reached if a peak exists
}

int main() {
    vector<vector<int>> mat = {
        {1, 4, 3},
        {6, 5, 2}
    };

    vector<int> peak = findPeakGrid(mat);
    cout << "Peak found at: [" << peak[0] << ", " << peak[1] << "]\n";
    return 0;
}
