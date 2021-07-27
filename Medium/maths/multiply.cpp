#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

class Solution {
public:
    string add (string num1, string num2){
        if(num2.length()>num1.length()) swap (num2, num1);
        string sol(num1.length(), ' ');
        int carry=0;
        
        for(int i= num1.length()-1, j= num2.length()-1; i>=0; i--, j--){
            int k;
            if(j<0) k=0;
            else k = num2[j] - '0';
            int s = num1[i] - '0' + k + carry;
            sol[i] = '0' + (s%10);
            carry = s/10;
        }
        if(carry>0){
            string st = " ";
            st[0]= carry + '0';
            sol = st.append(sol);
        }
        return sol;
    }
    
    string mult (char num2, string num1){
        string sol(num1.length(), ' ');
        int carry=0;
        
        for(int i= num1.length()-1 ; i>=0; i--){
            int k = num2 - '0';
            int s = (num1[i] - '0')*k + carry;
            sol[i] = '0' + (s%10);
            carry = s/10;
        }
        if(carry>0){
            string st = " ";
            st[0]= carry + '0';
            sol = st.append(sol);
        }
        return sol;
    }
    
    string multiply(string num1, string num2) {
        string sol;
        for(int i=0; i<num1.length(); i++){
            string temp = mult(num1[i],num2);
            for(int j=0; j<num1.length()-i-1; j++){
                temp+="0";
            }
            sol = add(temp, sol);
        }
        int i = 0;
        while(sol[i]=='0'){
            i++;
        }
        sol = sol.substr(i, sol.length() - i);
        if(sol=="") sol = "0";
        return sol;
    }
};


int main(){
    fast_cin();
    string num1, num2;
    cin>>num1>>num2;
    Solution* sol = new Solution;
    string str = sol->multiply(num1, num2);
    cout<<str;
    return 0;
}