// MIN NO OF DAYS TO MAKE M BOUQUETS

#include <bits/stdc++.h>
using namespace std;

bool ifPossible(vector<int>& bloomDay, int day, int m, int k) {
    int n = bloomDay.size();
    int cnt = 0;
    int noOfB = 0;

    for (int i = 0; i < n; i++) {
        if (bloomDay[i] <= day) {
            cnt++;
        } else {
            noOfB += cnt / k;
            cnt = 0;
        }
    }
    noOfB += cnt / k;

    return noOfB >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    long long val = 1LL * m * k;
    if (val > n) return -1;

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

    int low = mini, high = maxi, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ifPossible(bloomDay, mid, m, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Example usage
int main() {
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    cout << minDays(bloomDay, m, k) << endl; // Output: 3
    return 0;
}
