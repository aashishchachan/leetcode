#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

void build_adj(vector<vector <int>>& arr, int n){
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0; i<arr.size(); i++){
        matrix[arr[i][0]-1][arr[i][1]-1] = 1;
    }
    arr=matrix;
    return;
}

int solve( int n, vector<vector <int>>& arr){ //all hori zero, verti 1
    build_adj(arr, n);
    // for(int i=0; i<arr.size();i++){
    //     for(int j=0; j<arr.size();j++){
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }
    int i = 0, j = 0;
    while(i<n && j<n){
        for(j=i; j<n; j++){
            if(arr[i][j]==0) continue;
            else {
                i=j;
                if(arr[i][j]!=0) i++;
                if(i>=n) return -1;
            }
        }
        for(j=0; j<=i; j++){
            if(arr[i][j]!=0) break;
        }
        if(j<=i) {
            i++;
            continue;
        }
        else{
            j=i;
            for(i=0; i<n; i++){
                if(arr[i][j]==0 && i!=j) break;
            }
            if(i<n){ 
                i=j+1;
                continue;
            }
            else return j+1;
        }
    }
    return -1;
}

int main(){
    fast_cin();
    int n;
    int edges;
    cin>>n>>edges;
    vector <vector<int>> arr(edges, vector <int> (2));
    for(int i=0; i<edges; i++){
        for(int j=0; j<2; j++){
            cin>>arr[i][j];
        }
    }
    cout<<solve(n, arr);
    return 0;
}
// 

 