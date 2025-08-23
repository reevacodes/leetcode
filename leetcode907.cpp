// SUM OF SUBARRAYS MIN
#include <bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int> &arr)
{
  int n = arr.size();
  vector<int> left(n), right(n);
  stack<int> st;

  // -------- Left: Previous Smaller --------
  for (int i = 0; i < n; i++)
  {
    // strictly smaller
    while (!st.empty() && arr[st.top()] > arr[i])
    {
      st.pop();
    }
    if (st.empty())
      left[i] = i + 1;
    else
      left[i] = i - st.top();
    st.push(i);
  }

  // clear stack for right
  while (!st.empty())
    st.pop();

  // -------- Right: Next Smaller or Equal --------
  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && arr[st.top()] >= arr[i])
    {
      st.pop();
    }
    if (st.empty())
      right[i] = n - i;
    else
      right[i] = st.top() - i;
    st.push(i);
  }

  // -------- Contribution --------
  long long ans = 0;
  int mod = 1e9 + 7;
  for (int i = 0; i < n; i++)
  {
    long long contrib = (long long)arr[i] * left[i] * right[i];
    ans = (ans + contrib) % mod;
  }
  return ans;
}

int main()
{
  vector<int> arr = {3, 1, 2, 4};
  cout << sumSubarrayMins(arr) << endl; // Output: 17
}
