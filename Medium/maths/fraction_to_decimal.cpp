#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

string fractionToDecimal(int numerator, int denominator){
    long long n = numerator;
    long long d = denominator;
    string sol;
    long long m = n / d;
    if(m==0 && ((d>0 && n<0) || (n>0 && d<0))) sol="-0";
    else sol = to_string(m);
    if(n<0) n=0-n;
    if(d<0) d=0-d;
    string temp=".";
    map <long long, long long> rem; 
    long long rep=0, k=1;
    while(n%d!=0){
        n=(n%d)*10;
        if(rem[n]!=0) {rep=rem[n]; break;}
        else {rem[n]=k; k++;}
        temp+=to_string(n/d);
    }
    if(temp.length()>1){
        if(rep!=0){
            temp.insert(temp.begin() + rep , '(');
            temp += ")";
        }
        sol+=temp;
    }
    return sol;
}

int main(){
    fast_cin();
    int n, d;
    cin>>n>>d;
    cout<<fractionToDecimal(n,d)<<endl;
    return 0;
}