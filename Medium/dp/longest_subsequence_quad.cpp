#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

int solve(vector <int>& nums){
    int ans=1;
    vector<int> sol(nums.size());
    sol[nums.size() - 1] = 1;
    for (int i = nums.size() - 2; i >= 0; i--){
        int _max = 0;
        for (int j = i + 1; j<nums.size(); j++){
            if(nums[j]>nums[i]) _max = max(sol[j], _max);
        }
        sol[i] = _max+1;
        if(sol[i]>ans) ans=sol[i];
    }
    return ans; 
}

int main(){
    //fast_cin();
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<solve(arr)<<endl;
    return 0;
}