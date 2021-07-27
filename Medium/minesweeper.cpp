#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

void assign(vector<vector<int>> &mat, int i, int j){
    if(i-1>=0){
        if(j-1>=0) {
            if(mat[i-1][j-1]!=-1) mat[i-1][j-1]+=1;
        }
        if(mat[i-1][j]!=-1) mat[i-1][j]+=1;
        if(j+1<mat[i].size()) {
            if(mat[i-1][j+1]!=-1) mat[i-1][j+1]+=1;
        }
    }
    if(j-1>=0){
        if(mat[i][j-1]!=-1) mat[i][j-1]+=1;
    }
    if(j+1<mat[i].size()) {
        if(mat[i][j+1]!=-1) mat[i][j+1]+=1;
    }
    if(i+1<mat.size()){
        if(j-1>=0){
            if(mat[i+1][j-1]!=-1) mat[i+1][j-1]+=1;
        }
        if(mat[i+1][j]!=-1) mat[i+1][j]+=1;
        if(j+1<mat[i].size()){
            if(mat[i+1][j+1]!=-1) mat[i+1][j+1]+=1;
        }
    }
    return;
}

void solve(int n, vector <int> &row, vector <int> &col){
    
    vector<vector<int>> mat(n, vector<int> (n,0));
    vector<vector<char>> matc(n, vector<char> (n,'0'));
    
    for(int i=0; i<row.size(); i++){
        mat[row[i]][col[i]] = -1;
        assign(mat,row[i], col[i]);
    } 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j]==-1) matc[i][j] = 'B';
            else matc[i][j]=mat[i][j] + '0';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matc[i][j];    
        }
        cout<<endl;
    }
    return;
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    int r,c;
    cin>>r>>c;
    vector <int> row(r);
    vector <int> col(c);
    for(int i=0; i<r; i++){
        cin>>row[i];
    }
    for(int i=0; i<c; i++){
        cin>>col[i];
    }
    solve(n,row,col);
    return 0;
}