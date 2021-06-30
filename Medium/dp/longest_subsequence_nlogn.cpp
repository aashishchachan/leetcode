#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005


 

int solve(vector <int>& nums){
    vector<int> sol;
    sol.push_back(nums[0]);
    for (int i =1; i < nums.size(); i++){
        if(nums[i]>sol[sol.size()-1]) sol.push_back(nums[i]);
        else if(nums[i]<sol[sol.size()-1]) {
            auto it = lower_bound(sol.begin(), sol.end(), nums[i]);
            *it = nums[i];
        }
    }
    return sol.size(); 
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