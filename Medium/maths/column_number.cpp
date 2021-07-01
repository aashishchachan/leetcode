#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

int titleToNumber(string columnTitle) {
    long long j=1;
    int sol=0;
    for(int i=columnTitle.length()-1; i>=0; i--){
        sol+=(columnTitle[i]-'A'+1)*j;
        j*=26;
    }
    return sol;
}

int main(){
    fast_cin();
    string n;
    cin>>n;
    cout<<titleToNumber(n)<<endl;
    return 0;
}