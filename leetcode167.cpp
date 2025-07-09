
//2Sum II

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;

    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum > target) {
            j--;
        } else if (sum < target) {
            i++;
        } else {
            return {i + 1, j + 1}; // 1-based indexing
        }
    }
    return {};
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(numbers, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No pair found!" << endl;
    }

    return 0;
}
