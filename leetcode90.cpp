#include <bits/stdc++.h>
using namespace std;

void generate(int idx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
  ans.push_back(ds);
  for (int i = idx; i < nums.size(); i++)
  {
    if (i > idx && nums[i] == nums[i - 1])
      continue; // skip duplicates
    ds.push_back(nums[i]);
    generate(i + 1, nums, ds, ans);
    ds.pop_back(); // backtrack
  }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
  vector<int> ds;
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end()); // sort to handle duplicates
  generate(0, nums, ds, ans);
  return ans;
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  vector<int> nums(n);
  cout << "Enter the elements (space separated): ";
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  vector<vector<int>> result = subsetsWithDup(nums);

  cout << "Subsets with duplicates removed:\n";
  for (const auto &subset : result)
  {
    cout << "[ ";
    for (int num : subset)
      cout << num << " ";
    cout << "]\n";
  }

  return 0;
}
