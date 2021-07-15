#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

vector <int> querySum(int n, int arr[], int q, quries[]){
    vector<vector<int>> vec(n+2*q);
    vector <int> sol(q);
    for(int i=0; i<n; i++){
        vec[i]= {arr[i], 'p', i};
    }
    for(int i=0; i<2*q; i+=2){
        vec[n+i]={queries[i], 'l', i};
        vec[n+i+1]={queries[i+1], 'r', i};
    }
    sort(vec.begin(), vec.end());
    stack <vector<int> stk;
    int temp=0;
    for(int i=0; i<vec.size(); i++){
        if(vec[i][1]='l'){
            stk.push(vec[i]);
        }
        else if(vec[i][1]='r'){
            sol[vec[i][2]] += temp;
        }
        else {
            if((stk.top())[1]=='p')
                (stk.top())[0]+=vec[i][0];
            else stk.push(vec[i])
        }
    }
};
    

int main(){
    fast_cin();
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    int queries[q];
    for(int i=0; i<2*q; i++){
        cin>>arr[i];
    }
    querySum(n,arr,q,quries);
    return 0;
}