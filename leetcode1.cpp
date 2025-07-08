// LEETCODE - 1

// BRUTE FORCE 

// #include<iostream>
// #include<vector>
// using namespace std;

// string twoSum(int n, vector<int>book, int target){
//     for(int i=0;i<n;i++){
//         for(int j=1;j<n;j++){
//             if(book[i]+book[j]==target) return "YES";
//             return "NO";
//         }
//     }
// }

// int main(){
//     vector<int>book;
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         book.push_back(x);
//     }
//     int target;
//     cin>>target;
//     cout<<twoSum(n,book,target);
//     return 0;
// }


// BETTER-HASHING

// #include<iostream>
// #include<vector>
// #include<map>
// using namespace std;


// string twoSum(int n, vector<int> book, int target){
//     map<int,int>mpp;
//     for(int i=0;i<n;i++){
//         int current = book[i];
//         int more = target - current;
//         if(mpp.find(more)!=mpp.end()){
//             return "YES";
//         }
//         mpp[current]=i;
//     }
//     return "NO";
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int>book;
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         book.push_back(x);
//     }
//     int target;
//     cin>>target;

//     cout<<twoSum(n,book,target);
//     return 0;
// }


// OPTIMAL- 2 POINTER

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort
using namespace std;

string read(int n, vector<int> book, int target)
{
    int left = 0, right = n - 1;
    sort(book.begin(), book.end()); // Sort first

    while (left < right) {
        int sum = book[left] + book[right];

        if (sum == target) {
            return "YES"; // Found the pair
        }
        else if (sum < target) {
            left++; // Need a bigger sum
        }
        else {
            right--; // Need a smaller sum
        }
    }
    return "NO"; // No pair found
}

int main()
{
    int n;
    cin >> n;

    vector<int> book;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        book.push_back(x);
    }

    int target;
    cin >> target;

    cout << read(n, book, target) << endl;
    return 0;
}