// Given a sorted rotated array and a key element, return the index of key element in the array.
// time: O(logn), space: O(1)
// Note: 4 5 6 1 2 3 is a sorted rotated array.

#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

int srch (vector <int>& nums, int l, int r, int k ){
    if(l>r) return -1;
    int mid = l+(r-l+1)/2;
    if(nums[mid]==k) return mid;

    if(nums[l]<nums[mid]){
        if(nums[mid]>k && nums[l]<=k) return srch(nums, l, mid-1, k);
        else return srch(nums, mid+1, r, k);
    }
    else {
        if(nums[mid]<k && nums[r]>=k) return srch(nums, mid+1, r, k);
        else return srch(nums, l , mid-1, k);

    }
    return mid;
}

int search(vector <int>& nums, int target){
    return srch(nums, 0, nums.size() - 1, target);
}

int main(){
    fast_cin();
    //external_io();
    int n, k;
    cin>>n>>k;
    vector <int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int sol =search(nums, k);
    cout << sol;
    return 0;
}
