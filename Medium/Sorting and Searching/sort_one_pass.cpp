#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int z=0, o=0, t=0;
    for(int i=0; i<nums.size();i++){
        if(nums[i]==0){
            z++;
            nums[z-1]=0;
            if(o>0) nums[z+o-1]=1;
            if(t>0) nums[z+o+t-1]=2;
        }
        else if(nums[i]==1){
            o++;
            nums[z+o-1]=1;
            if(t>0) nums[z+o+t-1]=2;
        }
        else if(nums[i]==2){
            t++;
            nums[z+o+t-1]=2;
        }
    }
    return;        
}

int main(){
    int n;
    cin>>n;
    vector <int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    sortColors(nums);
    for(auto i:nums){
        cout<<i;
    }
    return 0;
}