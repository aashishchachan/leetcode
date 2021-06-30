#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

bool searchMatrix(vector<vector<int>> matrix, int target){
    int i = 0;
    int j = matrix[0].size() - 1;
    int n = matrix.size();
    while(i < n  && j >= 0){
        if(target==matrix[i][j]) return true;
        if(target>matrix[i][j]) i++;
        else j--;
    }
    return false;
}

int main(){
    fast_cin();
    //external_io();
    int rows, col;
    cin>>rows>>col;
    vector<vector<int>> matrix(rows);
	for(int i=0; i<rows; i++){
		vector<int> vec(col);
        matrix[i] = vec;
        for(int j=0; j<col; j++){
			cin>>matrix[i][j];
		}
	}
    int target;
    cin>>target;
    cout<<searchMatrix(matrix, target)<<endl;
    return 0;
}