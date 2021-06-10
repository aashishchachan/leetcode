#include <bits/stdc++.h>

using namespace std;

int robbed();
int not_robbed();


int solve(vector<int> nums){
    vector <int> robbed(nums.size());
    vector <int> not_robbed(nums.size());
    robbed[0]=nums[0];
    not_robbed[0]=0;
    if(nums.size()>1){
        robbed[1]= nums[1];
        not_robbed[1]=nums[0];
    }
    if(nums.size()>2){
        robbed[2] = nums[0] + nums[2];
        not_robbed[2]= nums[1];
    }
    for(int i=3; i<nums.size(); i++){
        not_robbed[i] = robbed[i-1];
        robbed[i] = max(robbed[i-2] +nums[i], robbed[i-3] + nums[i]);
    }
    return max(robbed[nums.size() - 1], not_robbed[nums.size() - 1]);
}

int main(){
    int n;
    cin>>n;
    vector <int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<solve(nums)<<endl;
    return 0;
}