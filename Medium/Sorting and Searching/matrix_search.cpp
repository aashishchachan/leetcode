#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

struct Data{
    pair<int,int> start;
    pair<int,int> end;
    bool exists;
    pair <int, int> sol;
};

Data linear_search (vector <vector<int>>& matrix, pair <int, int> co1, pair <int, int> co2, int target){
    Data temp;
    int i = co1.first + (co2.first - co1.first +1)/2;
    int j = co1.second + (co2.second - co1.second +1)/2;
    pair<int, int> co = make_pair(i,j);
    if(co==co1 || co==co2){
        if(matrix[co1.first][co1.second]==target){
            temp.exists = true;
            temp.sol = co1;
            return temp;    
        }
        else if(matrix[co2.first][co2.second]==target){
            temp.exists = true;
            temp.sol = co2;
            return temp;    
        }
        else{
            temp.exists = false;
            temp.start = co1;
            temp.end = co2;
            return temp;
        }
    }
    else if(matrix[i][j]==target) {
        temp.exists = true;
        temp.sol = co;
        return temp;
    }
    else if(target<matrix[i][j]){
        return linear_search(matrix, co1, co, target);
    }
    else return linear_search(matrix, co, co2, target);  
}

pair <int, int> search (vector <vector<int>>& matrix, pair <int, int> co1, pair <int, int> co2, int target){
    pair<int, int> temp1, temp2, c1, c2, sol=make_pair(-1,-1);
    if(co1==co2){
        if(matrix[co1.first][co2.second]==target){
            return co1;
        }
        else return make_pair(-1,-1);
    }  
    Data temp = linear_search(matrix, co1, co2, target);
    if (temp.exists) return temp.sol;
    else{
        temp1 = temp.start;
        temp2 = temp.end;
    }
    c1.first = co1.first;
    c1.second = temp2.second;
    c2.first = temp1.first;
    c2.second = co2.second;
    sol=search(matrix, c1, c2, target);
    if(sol==make_pair(-1,-1)){
        c1.first = temp2.first;
        c1.second = co1.second;
        c2.first = co2.first;
        c2.second = temp1.second;
        sol = search(matrix, c1, c2, target);
    }
    return sol;
}

bool searchMatrix(vector<vector<int>> matrix, int target){
    pair <int, int> co1, co2, sol;
    co1={0, 0}; co2 = {matrix.size()-1, matrix[0].size()-1};  
    sol=search(matrix, co1, co2, target);
    if(sol==make_pair(-1,-1)) return false;
    else{
        cout<<sol.first<<" "<<sol.second<<endl;
        return true;
    }
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