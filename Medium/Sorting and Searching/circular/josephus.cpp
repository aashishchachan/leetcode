#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

int josephus(int n, int k){
    if(n==1) return 1;
    return (josephus(n-1, k)+ k-1)%n +1;
}

int main(){
    fast_cin();
    int n,k;
    cin>>n>>k;
    cout<<josephus(n,k);
    return 0;
}