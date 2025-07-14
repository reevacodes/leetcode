// ROTATE ARRAY BY 90 DEGREE

// BRUTE FORCE
// #include <bits/stdc++.h>
// using namespace std;

// void rotateMatrixBruteForce(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//     vector<vector<int>> rotated(n, vector<int>(n)); // new matrix

//     // Fill the rotated matrix
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             rotated[j][n - i - 1] = matrix[i][j];
//         }
//     }

//     // Copy back to the original matrix
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             matrix[i][j] = rotated[i][j];
//         }
//     }
// }

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     rotateMatrixBruteForce(matrix);

//     cout << "Matrix after 90-degree clockwise rotation (Brute Force):\n";
//     for (auto& row : matrix) {
//         for (int val : row) cout << val << " ";
//         cout << "\n";
//     }

//     return 0;
// }

// OPTIMAL SOLN

#include <bits/stdc++.h>
using namespace std;

void rotateMatrix90Clockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose the matrix (swap across the diagonal)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrix90Clockwise(matrix);

    cout << "Matrix after 90-degree clockwise rotation:\n";
    for (auto &row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
