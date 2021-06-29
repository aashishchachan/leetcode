#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

class Solution {
public:
    bool sortbyvec(const vector<int> &a, const vector <int> &b){
        return a[0] < b[0];
    }
    
    
    vector <vector <int>> merge(vector < vector<int>> intervals){
    vector<vector<int>> sol;
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector <int> &b){
        return (a[0] < b[0]);
    });
    
    for(int i=0; i<intervals.size(); ){
        int start = intervals[i][0];
        int end = intervals[i][1];
        while(i< intervals.size() && intervals[i][0]<=end){
            if(intervals[i][1]>end) end =intervals[i][1];
            i++;
        }
        sol.push_back({start, end});
    }
    return sol;
}
};

