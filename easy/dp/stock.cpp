#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> prices){
    int min=prices[0], max, prof=0;
    for(int i=0; i<prices.size(); i++){
        if(prices[i]-min > prof){
            prof = prices[i]-min;
        }
        else if(prices[i]<min){
            min = prices[i];
        }
    }
    return prof;
}

int main(){
    int n;
    cin>>n;
    vector <int> prices(n);
    for(int i=0; i<n; i++){
        cin>>prices[i];
    }
    cout<<solve(prices)<<endl;
    return 0;
}