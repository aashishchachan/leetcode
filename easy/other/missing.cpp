#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> nums){
    int n= nums.size();
    int s = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum+=nums[i];
    }
    return s-sum;
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