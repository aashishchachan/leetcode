#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    if(s.length()==0 || s.length()==1) return s;
    vector<char> str;
    str.push_back('|');
    for(int i=0; i<s.length(); i++) {
        str.push_back(s[i]);
        str.push_back('|');
    }
    int sol_l, sol_r;
    int n= str.size();
    sol_l = 0, sol_r = 0;
    for (int i = 0; i < n; i++) {
        int l=i, r=i;
        for (int j = 0; i-j>=0 && i+j<n ; j++){ 
            if(str[i-j] == str[i+j]){
                l = i- j;
                r = i +j;
                if(r-l> sol_r-sol_l){
                    sol_l = l;
                    sol_r = r;
                }
            }
            else break;
        }
    }
    string sol = "";
    for (int i = sol_l+1; i < sol_r; i+=2){
        sol += str[i];
    }

    return sol;
}


int main(){
    string st;
    cin >> st;
    cout<<longestPalindrome(st);
    return 0;
}