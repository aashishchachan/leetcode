// Given an array of size N, every element is in the range 0 to n-1
// Rearrange the given array so that arr[i] becomes arr[arr[i]].

#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

void rearrange(vector <int> &arr){
    int n= arr.size();
    for(int i=0; i<arr.size(); i++){
        arr[i] += (arr[arr[i]] % n)*n;
    }
    for(int i=0; i<arr.size(); i++){
        arr[i] = arr[i]/n;
    }
    return;
}

int main(){
    fast_cin();
    external_io();
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    rearrange(arr);
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    return 0;
}