#include <bits/stdc++.h>
using namespace std;

void get_subset(vector<int> &nums, int s, vector<vector<int>> &sol, vector<int> &temp ){
    
    for(int i=s+1; i<nums.size(); i++){
        temp.push_back(nums[i]);
        sol.push_back(temp);
        get_subset(nums, i, sol, temp);
        temp.pop_back();
    }
    return;
}

vector<vector <int>> subsets(vector <int> &nums) {
    vector<vector <int>> sol;
    vector <int> temp;
    sol.push_back(temp);
    get_subset(nums,  -1, sol, temp);
    return sol;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    vector<vector <int>> sol =subsets(nums);
    for(int i = 0; i < sol.size(); i++){
        for(int j = 0; j<sol[i].size(); j++){
            cout << sol[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}