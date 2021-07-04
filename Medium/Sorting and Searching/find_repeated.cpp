#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

void solve(vector <int> arr){
    //assume the elements of array to be in the range [1, n-1]
    //the elements are nodes and their values act as address to next node
    int s=arr[0], f=arr[0];
    while(1){
        s=arr[s];
        f=arr[arr[f]];
        if(s==f) break;
    }
    s = arr[0];
    int m = 50;
    while(s!=f && m--){
        s = arr[s];
        f = arr[f];
    }
    cout << s;
    return;
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
    solve(arr);
    return 0;
}