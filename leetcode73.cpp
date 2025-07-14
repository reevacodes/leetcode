// SET MATRIX TO 0

// BRUTE FORCE

// #include <bits/stdc++.h>
// using namespace std;

// void setMatrixZeroBruteForce(vector<vector<int>> &matrix) {
//     int n = matrix.size();
//     int m = matrix[0].size();
//     int marker = -1e9; // Unique placeholder value

//     // Step 1: Traverse and mark rows and columns
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == 0) {
//                 // Mark entire row (avoid overwriting 0s)
//                 for (int col = 0; col < m; col++) {
//                     if (matrix[i][col] != 0)
//                         matrix[i][col] = marker;
//                 }

//                 // Mark entire column
//                 for (int row = 0; row < n; row++) {
//                     if (matrix[row][j] != 0)
//                         matrix[row][j] = marker;
//                 }
//             }
//         }
//     }

//     // Step 2: Replace all marker values with 0
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == marker)
//                 matrix[i][j] = 0;
//         }
//     }
// }

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 1, 1},
//         {1, 0, 1},
//         {1, 1, 1}
//     };

//     setMatrixZeroBruteForce(matrix);

//     cout << "The final matrix is:\n";
//     for (auto &row : matrix) {
//         for (int val : row) {
//             cout << val << " ";
//         }
//         cout << "\n";
//     }

//     return 0;
// }


// BETTER SOLN

// #include <bits/stdc++.h>
// using namespace std;

// void setMatrixZeroBetter(vector<vector<int>> &matrix) {
//     int n = matrix.size();        // rows
//     int m = matrix[0].size();     // columns

//     vector<int> row(n, 0);  // row markers
//     vector<int> col(m, 0);  // column markers

//     // Step 1: Mark the rows and columns where 0 is found
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == 0) {
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }

//     // Step 2: Set cells to 0 based on markers
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (row[i] == 1 || col[j] == 1) {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }

// int main() {
//     vector<vector<int>> matrix = {
//         {1, 1, 1},
//         {1, 0, 1},
//         {1, 1, 1}
//     };

//     setMatrixZeroBetter(matrix);

//     cout << "The final matrix is:\n";
//     for (auto &row : matrix) {
//         for (int val : row) {
//             cout << val << " ";
//         }
//         cout << "\n";
//     }

//     return 0;
// }


// OPTIMAL SOLN

#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroOptimal(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;

    // Step 1: Use first row & first column as markers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;  // mark row
                if (j != 0)
                    matrix[0][j] = 0;  // mark col
                else
                    col0 = 0;  // if zero is in first column
            }
        }
    }

    // Step 2: Set cells to 0 based on markers (excluding first row/col)
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: Handle first row (if needed)
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 4: Handle first column (tracked by col0)
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    setMatrixZeroOptimal(matrix);

    cout << "The final matrix is:\n";
    for (auto &row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
