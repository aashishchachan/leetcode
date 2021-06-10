#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define mod 1000000007
#define forn(i, k, n) for(ll i=k; i<n; i++)
#define bfor(i,k, n) for(ll i=k; i>n; i--)
#define mp make_pair
#define pb push_back
#define des greater<int> 
#define sint <int>
#define sll <long long> 
#define llll <long long, long long>
#define stll <string, long long>
#define sstr <string>
#define intint <int,int>
#define stst <string, string>
#define stint <string, int>
#define debug cout<<"hello"<<endl;
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

secsort()

int solve(int n){
    vector<int> arr(n+1);
    arr[0] = 1;
    arr[1] = 1;
    forn(i,2,n+1){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

int main(){
    fast_cin();
    int t;
    cin >> t;
    cout << solve(t) << endl;
    return 0;
}