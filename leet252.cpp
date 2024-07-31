#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>>nums={{0,30},{5,10},{15,20}};
int main(){
    int flag;
    for(int i=0;i<nums.size();i++){
    if(nums[i].end()>nums[i+1].begin()){
        flag=1;
        break;
    }
}

if(flag==1){
    cout<<"False"<<endl;
}
else{
    cout<<"True"; 
}
return 0;
}


 