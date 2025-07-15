#include<iostream>
#include<vector>
using namespace std;

vector<int> generateRows(int row){
    long long ans= 1;
    vector<int>ansRow;
    ansRow.push_back(1);

    for(int col=1;col<row;col++){
        ans = ans*(row-col);
        ans=ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>>generate(int numRows){
    vector<vector<int>>ans;
    for(int i=1;i<=numRows;i++){
        ans.push_back(generateRows(i));
    }
    return ans;
}

int main(){
    int numRows = 5;
    vector<vector<int>>result=generate(numRows);
    
     for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}