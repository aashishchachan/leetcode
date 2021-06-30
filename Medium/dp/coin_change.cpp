#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

int solve(vector <int> &coins, int amount){
    sort(coins.begin(), coins.end());
    vector<int> sol(amount+1);
    sol[0] = 0;
    for(int i=1; i<sol.size();i++){
        int _min = INT_MAX;
        bool possible = false;
        for(int j=0; j<coins.size(); j++){
            if(i-coins[j]<0) break;
            if(sol[i-coins[j]] == -1) continue;
            _min = min(_min, sol[i-coins[j]]+1);
            possible = true;
        }
        if(possible) sol[i] = _min;
        else sol[i] = -1;
    }
    return sol[amount];
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int amount;
    cin>>amount;
    cout<<solve(arr, amount)<<endl;
    return 0;
}