#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

bool solve(int n){
    unordered_set <int> mp;
    while(1){
        int temp=0;
        while(n){
            int k =n%10;
            temp += k*k;
            n=n/10;
        }
        if (temp == 1) return true;
        else if (mp.find(temp)!=mp.end()) break;
        else mp.insert(temp);
        n = temp;
    }
    return false;
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}