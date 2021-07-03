#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

int iterate(vector<int>& arr, int n, int k, int t){
    int m = 10;
    while(m--){
        t=(t+(k%n))%n;
        cout << arr[t] << endl;
    }
    return arr[t];
}

void solve(vector<int> arr, int k, int t){
    int n=arr.size();
    cout << iterate(arr, n, k, t) << endl;
    return;
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin >> k;
    solve(arr, k,-1);
    return 0;
}