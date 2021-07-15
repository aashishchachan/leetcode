#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

void dfs(vector<vector <char>>& matrix, vector <int> directions, int i, int j){
    // directions = {n,s,e,w}
    if(directions[0] && i-1 >= 0  && matrix[i-1][j]=='1') {
        int k = directions[1];
        directions[1] = 0;
        dfs(matrix, directions, i-1, j);
        matrix[i-1][j]='0';
        directions[1] = k;
    }
    
    if(directions[2] && j-1 >=0 && matrix[i][j-1]=='1') {
        int k = directions[3];
        directions[3] = 0;
        dfs(matrix, directions,i, j-1);
        matrix[i][j-1]='0';
        directions[3] = k;
    }

    if(directions[1] && i+1 < matrix.size() && matrix[i+1][j]=='1') {
        int k = directions[0];
        directions[0] = 0;
        dfs(matrix, directions, i+1, j);
        matrix[i+1][j]='0';
        directions[0] = k;
    }
    if(directions[3] && j+1 < matrix[i].size() && matrix[i][j+1]=='1') {
        int k = directions[2];
        directions[2] = 0;
        dfs(matrix, directions,i, j+1);
        matrix[i][j+1]='0';
        directions[2] = k;
    }
}


int numIslands(vector<vector <char>>& matrix){
    int sol=0;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[i][j]=='1') {
                dfs(matrix, {1,1,1,1} , i,j);
                sol++;      
                matrix[i][j]='0';
            }
        }
    }
    return sol;
}

int main(){
    fast_cin();
    int m,n;
    cin>>m>>n;
    vector <vector <char>> matrix(m);
    for(int i=0; i<m; i++){
        vector <char> arr(n);
        matrix[i]=arr;
        for(int j=0; j<n; i++){
            cin>>matrix[i][j];
        }
    }
    cout<<numIslands(matrix)<<endl;
    return 0;
}