#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

void find(int dividend, int divisor, int &ans){
    if(dividend>divisor) return;
    int j = 1;
    int div = divisor;
    while(dividend<=div){
        ans-=j;
        dividend -=div;
        if(div<-107741824) break; 
        if(j<-107741824) break;
        div += div;
        j+=j;
    }
    find(dividend, divisor, ans);
    return;
}

int solve(int dividend, int divisor ){
    bool change=false;
    if(dividend>0 && divisor>0){
        divisor = 0-divisor;
        dividend = 0-dividend;
        change = true;
    }
    else if(dividend>0)  
        dividend = 0-dividend;
    else if(divisor>0)
        divisor = 0-divisor;
    else
        change = true;

    int ans = 0;
    find(dividend, divisor, ans);
    if(change){
        if (ans == INT_MIN)
            return INT_MAX;
        else
            return 0 - ans;
    }
    return ans;
    //2147483647
}

int main(){
    fast_cin();
    int n, m;
    cin>>n>>m;
    cout<<solve(n, m)<<endl;
    return 0;
}