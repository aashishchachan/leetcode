#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

vector <pair<int, int>> merge(vector <pair<int, int>> intervals){
    vector <pair<int, int> > sol;
    sort(intervals.begin(), intervals.end());
    
    for(int i=0; i<intervals.size(); ){
        int start = intervals[i].first;
        int end = intervals[i].second;
        while(i< intervals.size() && intervals[i].first<end){
            end = intervals[i].second;
            i++;
        }
        sol.push_back(make_pair(start, end));
    }
    return sol;
}

int main(){
    fast_cin();
    external_io();
    int n;
    cin>>n;
    vector <pair<int, int>> intervals(n);
    for(int i=0; i<n; i++){
        cin>>intervals[i].first;
        cin>>intervals[i].second;
    }
    vector <pair<int, int>> sol = merge(intervals);
    for(int i=0; i<sol.size(); i++){
        cout << sol[i].first << " ";
        cout<<sol[i].second<<endl;
    }
    return 0;
}
