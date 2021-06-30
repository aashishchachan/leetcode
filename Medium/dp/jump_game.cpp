#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

bool solve(vector <int> arr){
    vector <bool> vec(arr.size()); int j=1;
    vec[0]=true;
    for(int i=0; i<arr.size(); i++){
        if(vec[i]==false) break;
        if(vec[i]==true && i+arr[i]>=j){
            for(j=j; j<=i+arr[i]; j++){
                vec[j]=true;
                if(j==arr.size()-1) return vec[j];
            }
        }
    }
    return vec[arr.size()-1];
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
    cout<<solve(arr)<<endl;
    return 0;
}