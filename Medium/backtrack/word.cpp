#include <bits/stdc++.h>
using namespace std;

bool find (vector <vector<char>> &board, pair <int, int> idx, string &word, int s, char d, map<pair<int,int>, bool> &c){
    if(s==word.length()) return true;
    int i = idx.first, j = idx.second;

    if(!c.count(make_pair(i+1,j)) && i+1<board.size() && d!='u' && board[i+1][j]==word[s]) {
        c[make_pair(i + 1,j)] = true;
        bool sol =find(board, make_pair(i+1, j), word, s+1, 'd', c);
        if(sol==true) return true;
        c.erase(make_pair(i + 1, j));
    }
    if(!c.count(make_pair(i,j-1)) && j > 0 && d!='r' && board[i][j-1]==word[s]) {
        c[make_pair(i, j - 1)] = true;
        bool sol =find(board, make_pair(i, j-1), word, s+1, 'l', c);
        if(sol==true) return true;
        c.erase(make_pair(i, j - 1));
    }
    if(!c.count(make_pair(i-1,j)) && i > 0 && d!='d' && board[i-1][j]==word[s]) {
        c[make_pair(i - 1, j)]= true;
        bool sol =find(board, make_pair(i-1, j), word, s+1, 'u', c);
        if(sol==true) return true;
        c.erase(make_pair(i-1, j));
    }
    if(!c.count(make_pair(i,j+1)) && j+1<board[0].size() && d!='l' && board[i][j+1]==word[s]) {
        c[make_pair(i , j + 1)] = true;
        bool sol =find(board, make_pair(i, j+1), word, s+1, 'r', c);
        if(sol==true) return true;
        c.erase(make_pair(i, j + 1));
    }
    return false;
}



bool exist(vector <vector<char>> &board, string word) {
    map<pair<int, int>, bool> c;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j]==word[0]){
                c[make_pair(i, j)]= true;
                bool sol = find(board, make_pair(i, j), word,1, 'o', c);
                if(sol==true) return true;
                c.erase(make_pair(i, j));
            }    
        }
    }
    return false;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector <vector<char>> board;
    int n, m;
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        vector <char> temp(m);
        for(int j = 0; j<m; j++){
            cin>>temp[j];
        }
        board.push_back(temp);
    }
    string word;
    cin>>word;
    bool sol =exist(board, word);
    cout<<sol<<endl;
    return 0;
}