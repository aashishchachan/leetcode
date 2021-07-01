#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

int search(long long l, long long h, int n){
    if(l==h) return l;
    long long m = l + (h - l+1) / 2;
    long long s = m * m;
    if(s==n) return m;
    else if(s<n){
        return search(m, h, n);
    }
    else return search(l,m-1,n);
}

int mySqrt(int n){
    long long l, h;
    if(n==0) return 0;
    if(n<=3) return 1;
    for (long long i = 2; i <= n; ){
        long long k = i * i;
        if(k==n) return i;
        else if(k<n){
            l = i;
            i = k;
        }
        else{
            h = i;
            break;
        }
    }
    return search(l, h, n);
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    cout<<mySqrt(n)<<endl;
    return 0;
}