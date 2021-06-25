// Given two sorted arrays, find the median of the merged array.
// time complexity: log(max(m,n))

#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

int median_arrays (vector <int>& arr1, int l1, int r1, vector <int>& arr2, int l2, int r2){
    int sol;
    if(r1==l1 && r2==l2){
        if((arr1.size() +arr2.size())%2==0){
            sol= (arr1[r1]+arr2[r2])/2;
        }
        else{
            if (l1+l2+2 == ((arr1.size()+arr2.size())/2 +1)){
                if (arr1[l1] > arr2[l2]) sol = arr1[l1];
                else sol =arr2[l1];
            } 
            else {
                if (arr1[l1] < arr2[l2]) sol = arr1[l1];
                else sol =arr2[l1];
            }
        }
    }    
    if (arr1[l1+(r1-l1+1)/2]<arr2[l2+(r2-l2+1)/2]){
        sol = median_arrays(arr1, l1+(r1 - l1+1) / 2, r1, arr2, l2, l2 + (r2 - l2+1) / 2);
    }
    else if (arr1[l1+(r1-l1+1)/2]>arr2[l2+(r2-l2+1)/2]){
        sol = median_arrays(arr1, l1, l1+ (r1 - l1+1) / 2, arr2, l1+ (r2 - l2+1) / 2, r2);
    }
    else if(arr1[l1+(r1-l1+1)/2]==arr2[l2+(r2-l2+1)/2]){
        sol = (arr1[l1+(r1-l1+1)/2]);
    }
    return sol;
}

int main(){
    fast_cin();
    external_io();
    int m,n;
    cin>>m>>n;
    vector <int> arr1(m);
    vector <int> arr2(n);
    for(int i=0; i<m; i++){
        cin>>arr1[i];
    }
    for(int i=0; i<n; i++){
        cin>>arr2[i];
    }
    int sol = median_arrays(arr1, 0, m, arr2, 0, n);
    cout << sol;
    
    return 0;
}
