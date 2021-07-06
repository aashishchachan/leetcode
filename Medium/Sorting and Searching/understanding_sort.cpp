#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

// input:         output:
// 5 5                          
// 5 4 3 2 1      3 1 1 5 6        
// 3 1 1 5 6      3 1 1 6 7        
// 4 2 2 3 1      4 2 2 3 1        
// 5 5 3 2 1      5 4 3 2 1        
// 3 1 1 6 7      5 5 3 2 1        

// conclusion: sort function first compares the first element (pair.first or vec[0]) and if that is equal, 
// compares the next element in the list. 



void solve(vector<vector <int>> arr, int n, int m){
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout << endl;
    }
    return;
}

int main(){
    fast_cin();
    int n,m;
    cin>>n>>m;
    vector <vector<int>> arr(n);
    for(int i=0; i<n; i++){
        vector <int> vec(m);
        arr[i]=vec;
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    solve(arr, n, m);
    return 0;
}