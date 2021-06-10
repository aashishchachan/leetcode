#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> nums){
       int sum=INT_MIN, temp=0;
    for (int i = 0; i< nums.size(); i++){
        temp = max(temp+nums[i], nums[i]);
        sum = max(sum, temp);
    }
    return sum;
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