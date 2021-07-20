#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

int solve(vector <int>& arr){
    unordered_set <int> hash;
    for(int i=0; i<arr.size(); i++){
        hash.insert(arr[i]);
    }
    int sol=0;
    for(int i=0; i<arr.size(); i++){
        int j= arr[i];
        if(hash.find(j-1)!=hash.end()) continue;
        else{
            int temp =0;
            while(hash.find(j)!=hash.end()){
                j++;
                temp++;
            }
            sol = max(sol, temp);
        }
    }
    return sol;
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<solve(arr)<<endl;
    return 0;
}