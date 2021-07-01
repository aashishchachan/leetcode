#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

void solve(vector <int> arr){
     bool chng=false;
        if(dividend==0) return 0;
        if(divisor==1) return dividend;
        if(divisor == -1 && dividend == INT_MIN) return INT_MAX;
        if(divisor == -1) return 0-dividend;
        if(divisor == INT_MIN && dividend ==INT_MIN) return 1;
        if(divisor == INT_MIN) return 0;
        if(dividend == INT_MIN){
            if(divisor > 0) {
                divisor=0-divisor;
                chng = true;
            } 
        } 
        
        int ans =0;
        if(dividend >0 && divisor>0){
            while(dividend>=divisor){
                if(ans!=INT_MAX) ans++;
                dividend -=divisor;
            }
        }
        else if(dividend <0 && divisor<0){
            while(dividend<=divisor){
                if(chng) ans--;
                else if(ans!=INT_MAX) ans++;
                dividend -=divisor;
            }
        }
        else{
            if (dividend<0){
                while(0-dividend>=divisor){
                    ans--;
                    dividend +=divisor;
                }
            }
            else{
                while(dividend>=0-divisor){
                    ans--;
                    dividend +=divisor;
                }
            }
        }
        return ans;
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    solve(arr);
    return 0;
}