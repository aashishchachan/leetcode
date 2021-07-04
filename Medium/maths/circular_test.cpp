#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

void solve(vector <int> arr){
    int i=10; 
    for(int j= 1; j<=10; j++){
        arr[i]=j;
        i=j;
    }
    int s=1, f=arr[s];
    while(s!=f){
        cout<<s<<" "<<f<<endl;
        s=arr[s];
        f=arr[arr[f]];
    }
    cout<<s<<" "<<f<<endl;

    return;
}

int main(){
    fast_cin();
    vector <int> arr(11);
    solve(arr);
    return 0;
}