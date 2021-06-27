#include <bits/stdc++.h>
using namespace std;

#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);


vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    map<int, int> mp;
    vector <int> sol(2);
    for(int i = 0; i < edges.size(); i++){
         
    
    }

}

int main(){
    fast_cin();
    external_io;
    ll t;
    cin >> t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> edges(n);
        for(int i=0; i<n; i++){
            vector<int> temp(2);
            for(int j=0; j<2; j++){
                cin>>temp[j];
            }
            edges[i]=temp;
        }
        vector <int> sol;
        sol = findRedundantConnection(edges);
        cout<<sol[0]<<" "<<sol[1]<<endl;
    }
    return 0;
}