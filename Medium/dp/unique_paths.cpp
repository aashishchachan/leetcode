#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

int solve(int m, int n){
    vector <vector<int>> vec(m);
    vector<int> temp(n);
    for(int i=0; i<m; i++){
        vec[i] = temp;
    } 
    for(int i=0; i<m; i++){
        vec[i][0] = 1;
    }
    for(int i=0; i<n; i++){
        vec[0][i] = 1;
    }    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            vec[i][j] = vec[i-1][j] + vec[i][j-1];
        }
    }
    return vec[m-1][n-1];
}

int main(){
    fast_cin();
    //external_io();
    int m,n;
    cin>>m>>n;
    cout<<solve(m,n)<<endl;
    return 0;
}