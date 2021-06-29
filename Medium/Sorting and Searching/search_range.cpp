#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

void find(vector<int>& nums, int i, int j, int target, pair<int, int>& sol){
    if(i>j) return; 
    int k= i+(j-i+1)/2;
    if(target==nums[k]) {
        if(sol.first==-1 && sol.second==-1){
            sol = {k,k};
            find(nums, i, k-1, target, sol);
            find(nums, k+1, j, target, sol);
        }
        else if(k<sol.first){
            sol.first = k;
            find(nums, i, k - 1, target, sol);
        }
        else if(k>sol.second){
            sol.second = k;
            find(nums, k+1, j, target, sol);
        }
    }
    else if (target<nums[k]) find(nums, i, k-1, target, sol);
    else find(nums, k+1, j, target, sol);
    return;
}

vector<int> searchRange(vector<int>& nums, int target) {
    pair<int, int> sol={-1,-1};
    find(nums, 0, nums.size()-1, target, sol);
    vector<int> m(2);
    m[0] = sol.first;
    m[1] = sol.second;
    return m;
}


int main(){
    fast_cin();
    //external_io();
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    vector<int> sol;
    sol = searchRange(arr, target);
    cout << sol[0] << " " << sol[1] << endl;
    return 0;
}

