#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> sol;
    for (int i = 0; i<strs.size(); i++){
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        if(sol.count(temp)) sol[temp].push_back(strs[i]);
        else sol[temp] = {strs[i]};
    }
    vector<vector<string>> fin;
    for (auto it = sol.begin(); it != sol.end(); ++it){
        fin.push_back((*it).second);
    }
    return fin;
}

int main(){
    vector<string> strs = {"hello", "llhoe", "how", "are", "era", "you"};
    vector<vector<string>> sol = groupAnagrams(strs);
    for(int i=0; i<sol.size(); i++){
        for(int j=0; j<sol[i].size(); j++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0; 
}