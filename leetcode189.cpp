// LEFT ROTATE AN ARRAY BY K PLACES

#include <iostream>
#include <vector>
using namespace std;

// Reverse a portion of the array
void reverse(vector<int>& arr, int start, int end) {
    while (start <= end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate array to the left by k positions
vector<int> rotateArray(vector<int> arr, int k) {
    int n = arr.size();
    k = k % n; // Handle if k > n

    reverse(arr, 0, k - 1);     // Reverse first k elements
    reverse(arr, k, n - 1);     // Reverse remaining elements
    reverse(arr, 0, n - 1);     // Reverse the entire array

    return arr;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of positions to rotate left: ";
    cin >> k;

    vector<int> rotated = rotateArray(arr, k);

    cout << "Rotated Array: ";
    for (int x : rotated) {
        cout << x << " ";
    }

    return 0;
}
