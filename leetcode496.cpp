// NEXT GREATER ELEMENT I

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
  unordered_map<int, int> nge; // map from element -> next greater
  stack<int> st;

  // Traverse nums2 from right to left
  for (int i = nums2.size() - 1; i >= 0; i--)
  {
    int num = nums2[i];

    // Pop smaller elements
    while (!st.empty() && st.top() <= num)
    {
      st.pop();
    }

    // If stack empty => no next greater
    nge[num] = st.empty() ? -1 : st.top();

    // Push current number
    st.push(num);
  }

  // Build result for nums1
  vector<int> result;
  for (int num : nums1)
  {
    result.push_back(nge[num]);
  }

  return result;
}

// Driver code
int main()
{
  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};

  vector<int> ans = nextGreaterElement(nums1, nums2);

  cout << "Next Greater Elements: ";
  for (int x : ans)
    cout << x << " ";
  cout << endl;

  return 0;
}
