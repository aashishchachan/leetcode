// Given integer array representing height of N buildings, delete N-2 buildings so that water
// trapped between remaining two buildings is maximum.
// Water trapped between two buildings: buildings removed between them * height of smaller building.
// time: O(n); space: O(1)
// input: 2 1 3 4 6 5
// output: 8;

#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

//space: O(1)
int waterc (vector <int> &nums){
    int sol = 0;
    int i=0, j=nums.size()-1;
    while(i<j){
        sol =max(sol, (j - i - 1) * min(nums[i], nums[j]));
        if(nums[i]>nums[j]) j--;
        else i++;
    }
    return sol;
}


int main(){
    fast_cin();
    external_io();
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sol = waterc(arr);
    cout << sol;
    return 0;
}