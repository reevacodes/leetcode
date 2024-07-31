#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main(){\"{}"
    string stones="aAAbbbb";
    string jewels="aA";
    int count=0;
    for(int i=0;i<stones.size();i++){
        for(int j=0;j<jewels.size();j++){
            if(stones[i]==jewels[j]){
                count++;
            }
        }
    }
    cout<<count;
}