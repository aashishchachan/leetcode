#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

int trailingZeroes(int n) {
    int twoes=0, fives=0; 
    for(int i=n; i>0; i/=2){
        twoes+=i/2;
    }
    for(int i=n; i>0; i/=5){
        fives+=i/5;
    }
    return min(twoes, fives);
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    cout<<trailingZeroes(n)<<endl;
    return 0;
}