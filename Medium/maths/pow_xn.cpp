#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

double myPow(double x, int n){
    if(n==0) return 1;
    if(x==0 || x==1) return x;
    //bool sign = false;
    if(n<0) {x=1/x;n=abs(n);} //{sign = true; n=abs(n);}
    double sol=1;
    if(n%2!=0){
        sol *= x;
        n -= 1;
    }
    double t= myPow(x, n/2);
    sol *= t * t;
    if(  isinf(sol)) return 0;
    //if(sign) sol = 1/sol;
    return sol;
}

int main(){
    fast_cin();
    double x;
    cin >> x;
    int n;
    cin>>n;
    cout<<myPow(x,n)<<endl;
    return 0;
}