// Find out the number of operations required to make a square matrix beautiful.
// A beautiful matrix is where sum of each row and column is equal.
// In each operation, value of a cell can be incremented by one.

#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

int main(){
    external_io();
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    int sum =0;
    int row[n], col[n]; 
    for(int i=0; i<n; i++){
        int temp=0;
        for(int j=0; j<n; j++){
            temp+=arr[i][j];
        }
        row[i]=temp;
        if(temp>sum) sum=temp;
    }
    for(int j=0; j<n; j++){
        int temp=0;
        for(int i=0; i<n; i++){
            temp+=arr[i][j];
        }
        col[j]=temp;
        if(temp>sum) sum=temp;
    }
    int sol=0;
    for(int i=0; i<n; i++){
        sol += sum - row[i];
    }
    
    // straightforward approach : (max_sum)*n - (total_sum) 

    cout<<sol<<endl;
    return 0;
}