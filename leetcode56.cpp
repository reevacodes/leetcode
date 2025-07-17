// MERGE INTERVALS

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    int n = intervals.size();

    // Sort intervals based on starting time
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < n; i++) {
        // If no overlap, add the interval
        if (ans.empty() || intervals[i][0] > ans.back()[1]) {
            ans.push_back(intervals[i]);
        } 
        // Else merge the current with the previous one
        else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> merged = mergeIntervals(intervals);

    cout << "Merged Intervals: " << endl;
    for (auto interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
