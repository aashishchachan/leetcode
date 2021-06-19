#include <bits/stdc++.h>
using namespace std;

void get_permute(vector<int> &nums, int s, vector<vector<int>> &sol)
{
    if(s==nums.size()-1){
        sol.push_back(nums);
        return;
    }

    for (int i = s; i<nums.size(); i++){
        swap(nums[s], nums[i]);
        get_permute(nums, s+1, sol);
        swap(nums[s], nums[i]);
    }
    return;
}

vector<vector <int>> permute(vector <int> &nums) {
    vector < vector<int>> sol;
    get_permute(nums, 0,sol );
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
    vector<vector <int>> sol =permute(nums);
    for(int i = 0; i < sol.size(); i++){
        for(int j = 0; j<sol[i].size(); j++){
            cout << sol[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}