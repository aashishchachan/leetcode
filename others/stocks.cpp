#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

vector <vector<int>> solve(vector <int> arr){
    vector<vector<int>> sol;
    int min, max,m,n;
    for (int i=0; i<arr.size(); ){
        min =arr[i];
        m = i;
        i++;
        while(i<arr.size() && arr[i]<=min){
            min=arr[i];
            m = i;
            i++;
        }
        max=arr[i];
        n = i;
        i++;
        while(i<arr.size() && arr[i]>=max){
            max=arr[i];
            n = i;
            i++;
        }
        vector <int> days = {m,n};
        sol.push_back(days);
    }
    return sol; 
}
    
int main(){
    fast_cin();
    //external_io();
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<vector<int>> sol = solve(arr);
    for(int i=0; i<sol.size(); i++){
        cout<<sol[i][0]<<" "<<sol[i][1]<<" ";
    }
    return 0;
}