// Given an array of integers, find the length of longest subsequence of consecutive integers.
// Consecutive integers can be in any order.
// input: 9 5 6 8 4 3 8 2 1 ; output: 6 (1,2,3,4,5,6)
// time, space: O(n)

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    //map<int, int> mp;
    int max = 0;
    
    cout << max << endl;
    return 0;
}