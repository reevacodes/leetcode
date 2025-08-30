#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate combinations
void generate(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &list, int target, int idx)
{
  if (idx == candidates.size())
    return;

  if (target == 0)
  {
    ans.push_back(list);
    return;
  }

  // Pick the current element
  if (target >= candidates[idx])
  {
    list.push_back(candidates[idx]);
    generate(candidates, ans, list, target - candidates[idx], idx); // can reuse same element
    list.pop_back();                                                // backtrack
  }

  // Not pick, move to next index
  generate(candidates, ans, list, target, idx + 1);
}

// Function to return all combinations summing to target
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  vector<vector<int>> ans;
  vector<int> list;
  generate(candidates, ans, list, target, 0);
  return ans;
}

int main()
{
  vector<int> candidates = {2, 3, 6, 7};
  int target = 7;

  vector<vector<int>> result = combinationSum(candidates, target);

  cout << "Combinations summing to " << target << ":\n";
  for (auto &comb : result)
  {
    cout << "[ ";
    for (int num : comb)
      cout << num << " ";
    cout << "]\n";
  }

  return 0;
}
