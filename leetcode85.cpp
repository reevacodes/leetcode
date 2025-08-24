// MAXIMUM RECTANGLE

#include <bits/stdc++.h>
using namespace std;

// Largest Histogram Area
int lHist(vector<int> &preSum)
{
  stack<int> st;
  int n = preSum.size();
  int maxArea = 0;

  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && preSum[st.top()] > preSum[i])
    {
      int el = st.top();
      st.pop();
      int nse = i;
      int pse = st.empty() ? -1 : st.top();
      maxArea = max(maxArea, preSum[el] * (nse - pse - 1));
    }
    st.push(i);
  }

  while (!st.empty())
  {
    int el = st.top();
    st.pop();
    int nse = n;
    int pse = st.empty() ? -1 : st.top();
    maxArea = max(maxArea, preSum[el] * (nse - pse - 1));
  }

  return maxArea;
}

// Maximal Rectangle Function
int maximalRectangle(vector<vector<char>> &matrix)
{
  int n = matrix.size();
  if (n == 0)
    return 0;
  int m = matrix[0].size();

  int maxArea = 0;
  vector<vector<int>> preSum(n, vector<int>(m, 0));

  // Build histogram heights column-wise
  for (int j = 0; j < m; j++)
  {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += matrix[i][j] - '0';
      if (matrix[i][j] == '0')
        sum = 0;
      preSum[i][j] = sum;
    }
  }

  // Calculate max rectangle row by row
  for (int i = 0; i < n; i++)
  {
    maxArea = max(maxArea, lHist(preSum[i]));
  }

  return maxArea;
}

// Driver Code
int main()
{
  vector<vector<char>> matrix = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};

  cout << "Maximal Rectangle Area: " << maximalRectangle(matrix) << endl;
  return 0;
}
