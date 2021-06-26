#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

vector <int> topKFrequent (vector <int>& nums, int k){
    map <int, int> freq;
    vector <int> sol(k);
    multiset<pair<int,int>> multi;
    for(int i=0; i<nums.size(); i++){
        freq[nums[i]]++;
    }
        
    for(auto i=freq.begin(); i!=freq.end(); i++){
        pair<int, int> temp;
        temp.first= i->second;
        temp.second = i->first;
        multi.insert(temp);
    }
    
    int j = 0;
    for (auto i = multi.rbegin(); i != multi.rend() && j<k; i++){
        sol[j]=(i->second);
        j++;
    }
    return sol;
}

int main(){
    fast_cin();
    external_io();
    int n,k;
    cin>>n>>k;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector <int> sol = topKFrequent(arr, k);
    for(int i=0; i<sol.size(); i++){
        cout << sol[i];
    }
    return 0;
}
