#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(int idx, string &digits, vector<string>& phone, string &current, vector<string> &res) {
    if (idx == digits.size()) {
        res.push_back(current);
        return;
    }

    string letters = phone[digits[idx] - '2'];
    for (char c : letters) {
        current.push_back(c);
        generate(idx + 1, digits, phone, current, res);
        current.pop_back(); // backtrack
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> phone = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    string current;

    if (digits.empty()) return res; // handle empty input

    generate(0, digits, phone, current, res);
    return res;
}

int main() {
    string digits = "25";
    vector<string> result = letterCombinations(digits);

    cout << "Combinations for digits " << digits << " are:\n";
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
