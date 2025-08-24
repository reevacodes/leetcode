// SUM OF SUBARRAY RANGES

#include <bits/stdc++.h>
using namespace std;

// -------- Sum of subarray minimums --------
long long subarrayMin(vector<int> &nums)
{
  int n = nums.size();
  stack<int> st;
  vector<long long> left(n), right(n);

  // Previous Smaller Element (strictly smaller)
  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && nums[st.top()] > nums[i])
    {
      st.pop();
    }
    left[i] = st.empty() ? i + 1 : i - st.top();
    st.push(i);
  }

  while (!st.empty())
    st.pop();

  // Next Smaller or Equal Element
  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && nums[st.top()] >= nums[i])
    {
      st.pop();
    }
    right[i] = st.empty() ? n - i : st.top() - i;
    st.push(i);
  }

  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += nums[i] * left[i] * right[i];
  }
  return ans;
}

// -------- Sum of subarray maximums --------
long long subarrayMax(vector<int> &nums)
{
  int n = nums.size();
  stack<int> st;
  vector<long long> left(n), right(n);

  // Previous Greater Element (strictly greater)
  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && nums[st.top()] <= nums[i])
    {
      st.pop();
    }
    left[i] = st.empty() ? i + 1 : i - st.top();
    st.push(i);
  }

  while (!st.empty())
    st.pop();

  // Next Greater or Equal Element
  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && nums[st.top()] < nums[i])
    {
      st.pop();
    }
    right[i] = st.empty() ? n - i : st.top() - i;
    st.push(i);
  }

  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += nums[i] * left[i] * right[i];
  }
  return ans;
}

// -------- Sum of subarray ranges --------
long long subArrayRanges(vector<int> &nums)
{
  return subarrayMax(nums) - subarrayMin(nums);
}

int main()
{
  vector<int> nums;

  nums = {1, 2, 3};
  cout << "Array: {1,2,3} -> Subarray Ranges Sum: " << subArrayRanges(nums) << endl;

  nums = {4, 1, 2, 3};
  cout << "Array: {4,1,2,3} -> Subarray Ranges Sum: " << subArrayRanges(nums) << endl;

  nums = {1, 3, 2, 4, 2};
  cout << "Array: {1,3,2,4,2} -> Subarray Ranges Sum: " << subArrayRanges(nums) << endl;

  return 0;
}
