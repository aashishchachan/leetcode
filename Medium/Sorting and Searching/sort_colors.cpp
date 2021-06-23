#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    vector <int> m(3);
    for(auto i: nums){
        m[i]++;
    }
    int k = 0, j=0;
    for (int i = 0; i <3; i++)
    {
        for(j=0; j<m[i]; j++, k++){
            nums[k]=i;
        }
    }
    for(auto i:nums){
        cout<<i;
    }
    return 0;
}