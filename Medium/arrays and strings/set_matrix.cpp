#include <bits/stdc++.h>
using namespace std; 

void setZeroes(vector<vector<int>>& matrix) {
    pair<int, int> m00 = {1,1};
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){ 
            if (matrix[i][j]==0){
                if(i==0) m00.first = 0;
                else matrix[i][0]=0; 
                if(j==0) m00.second = 0;
                else  matrix[0][j]=0;
            }
        }
    }
    
    for(int i=1; i<matrix.size(); i++){
        if (matrix[i][0]==0){
            for(int j=1; j<matrix[0].size(); j++){  
                matrix[i][j]=0;
            }    
        }
    }
    
    for(int j=1; j<matrix[0].size(); j++){
        if (matrix[0][j]==0){
            for(int i=1; i<matrix.size(); i++){  
                matrix[i][j]=0;
            }    
        }
    }
    if(m00.first==0){    
        for(int j=0; j<matrix[0].size(); j++){
            matrix[0][j] = 0;
        }
    }
    if(m00.second==0){
        for (int i = 0; i<matrix.size(); i++){
            matrix[i][0] = 0;
        }
    }
    return;
}

int main(){
    vector<vector<int>> matrix;
    matrix.push_back({0,1,2,0});
    matrix.push_back({3,4,5,2});
    matrix.push_back({1,3,1,5});
    setZeroes(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
