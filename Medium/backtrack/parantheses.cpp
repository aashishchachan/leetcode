#include <bits/stdc++.h>
using namespace std;

void get_val(stack <char> &stk, int open, int close, string str, vector <string> &sol){
    if(open==0 && close==0){
        sol.push_back(str);
        return;
    }
    if(stk.empty()){
        if(open>0){
            stk.push('(');
            string temp = str + "(";
            get_val(stk, open-1, close, temp, sol);
            stk.pop();
        }
    }
    else if(stk.top()=='('){
        if(open>0){
            stk.push('(');
            string temp =str + "(";
            get_val(stk, open-1, close, temp ,sol);
            stk.pop();
        }
        if(close>0){
            stk.pop();
            string temp =str + ")";
            get_val(stk, open, close-1, temp, sol);
            stk.push('(');
        }
    }
    return;
}

vector<string> generateParenthesis(int n) {
    int open=n, close=n;
    stack<char> stk;
    vector<string> sol;
    string str = "";
    get_val(stk, open, close, str, sol);
    return sol;
}

int main(){
    int n;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    vector <string> sol =generateParenthesis(n);
    for(int i = 0; i < sol.size(); i++){
        cout << sol[i] << endl;
    }
    return 0;   
}