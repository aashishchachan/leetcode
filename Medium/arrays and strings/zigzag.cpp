#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

string solve(string s, int numRows){
    string sol="";
    if (numRows>=s.length() || numRows==1) return s;
    for(int i=1; i<=numRows; i++){
        int j1=i-1;
        int j2 = numRows - i;
        int j=j1;
        string str="";
        str += s[j];
        while(1){
            j+=j2*2;
            if(j>=s.length()) break;
            if(j2>0) str+=s[j];
            j+=j1*2;
            if(j>=s.length()) break;
            if(j1>0) str+=s[j];
        }
        sol+=str; 
    }
    return sol;
}

int main(){
    fast_cin();
    //external_io();
    string str;
    cin>>str;
    int n;
    cin>>n;
    string sol =solve(str,n);
    cout << sol;
    return 0;
}