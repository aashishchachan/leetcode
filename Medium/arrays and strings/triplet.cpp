#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    vector<bool> bleft(nums.size());
    bleft[0] = false;
    int min = nums[0];
    for(int i = 1; i<nums.size(); i++){
        if(nums[i]>min) bleft[i] = true;
        else {
            min = nums[i];
            bleft[i] = false;
        }
    }
    vector<bool> bright(nums.size());
    bright[bright.size()-1] = false;
    int max = nums[nums.size()-1];
    for(int i = nums.size()-2; i>=0; i--){
        if(nums[i]<max) bright[i] = true;
        else {
            max = nums[i];
            bright[i] = false;
        }
        if(bright[i]==true && bleft[i]==true) return true;
    }

    return false;
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++){
        cin>>nums[i];
    }
    cout << increasingTriplet(nums);
    return 0;
}