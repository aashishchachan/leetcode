#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

string calc(string mx, string ny, string sym){
    int m = 0, n = 0;
    stringstream t1(mx);
    t1 >> m;
    stringstream t2(ny);
    t2 >> n;
    if(sym == "+") return to_string(m+n);
    if(sym == "-") return to_string(n-m);
    if(sym == "*") return to_string(m*n);
    if(sym == "/") return to_string(n/m);
    return sym;
}

int solve(vector <string> arr){
    stack <string> stk;
    stk.push(arr[0]);
    stk.push(arr[1]);
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == "+" || arr[i] == "-" || arr[i] == "/" || arr[i] == "*"){
            string m = stk.top();
            stk.pop();
            string n = stk.top();
            stk.pop();
            stk.push(calc(m,n,arr[i]));
        }
        else
            stk.push(arr[i]);
    }
    stringstream s(stk.top());
    int sol =0;
    s>>sol;
    return sol;
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector <string> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<solve(arr)<<endl;
    return 0;
}