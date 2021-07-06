//there are n petrol pumps in a circle. we have the data of petrol on each pump and its distance from the next 
// petrol pump. tank capacity is infinite. Find the first point from where a complete circular journey can be done. 

#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

int solve(vector <pair<int, int>> arr){
    vector <int> vec(arr.size());
    for (int i=0; i<arr.size(); i++){
        vec[i]= arr[i].first-arr[i].second;
    }
    pair<int, int> min ={INT_MAX, -1};
    for (int i=0; i<vec.size(); i++){
        if(vec[i]<min.first) min= make_pair(vec[i], i); 
    }
    int r=min.second, l=r, sum= min.first, i=0, n=vec.size();
    
    while(sum<0 && i<vec.size()){
        l = (n + ((l - 1)%n))%n;
        sum+=vec[l];
        i++;
    }
    while(sum>=0 && i<vec.size()){
        r= (r+1)%n;
        sum+=vec[r];
        i++;   
    }    
    
    return l;
}

int find(vector <pair<int, int>> arr){
    vector <int> vec(arr.size());
    for (int i=0; i<arr.size(); i++){
        vec[i]= arr[i].first-arr[i].second;
    }
    int curr = 0, prev = 0, start =0;
    for(int i=0; i<vec.size(); i++){
        curr += vec[i];
        if(curr<0){
            start = i+1;
            prev += curr;
            curr = 0;
        }
    }
    if(curr+prev >=0) return start;
    else return -1;
}


int main(){
    fast_cin();
    int n=4;
    cin>>n;
    vector <pair<int, int>> arr(n);
    arr = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    for(int i=0; i<n; i++){
        cin>>arr[i].first;
        cin>>arr[i].second;
    }
    cout<<solve(arr)<<endl; //for any valid point
    cout<<find(arr)<<endl;  // for point closest to zero index
    return 0;
}