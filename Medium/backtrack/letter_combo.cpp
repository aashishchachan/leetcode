#include <bits/stdc++.h>
using namespace std;

vector <string> formation(string digits){
    map <char, string> values;
    values['2']= "abc";
    values['3']= "def";
    values['4']= "ghi";
    values['5']= "jkl";
    values['6']= "mno";
    values['7']= "pqrs";
    values['8']= "tuv";
    values['9']= "wxyz";
    vector<string> str;
    for(int i=0; i<digits.length(); i++){
        str.push_back(values[digits[i]]);
    }
    return str;
}

vector<string> joining(string a, vector<string> str){
    vector<string> sol;
    for (int i = 0; i<a.length(); i++){
        for (int j = 0; j<str.size(); j++){
            sol.push_back(a[i] + str[j]);
        }
    }
    return sol;
}

vector <string> letterCombinations(string digits){
    vector <string> str = formation(digits);
    vector <string> sol;
    string m = str[str.size()-1];
    for (int i = 0; i<m.length(); i++){
        sol.push_back(m[i]+"");
    }
    for (int i = str.size() - 2; i >= 0; i--){
        sol = joining(str[i], sol);
    }
    return sol;
}

int main(){
    string digits;
    cin >> digits;
    vector <string> sol =letterCombinations(digits);
    for(int i = 0; i < sol.size(); i++){
        cout << sol[i] << endl;
    }
    return 0;
}