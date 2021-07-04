#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

int get_majority_element(vector<int> &a, int left, int right) {
  if (left > right) return -1;
  if(left == right) return a[left];

  int x= get_majority_element(a, left, left + (right-left)/2);
  int y= get_majority_element(a, left + 1+ (right-left)/2, right);

  if(x==y) return x;
  else{
    int count=0;
    if(y!=-1){
      for(int i=left; i<=right; i++){
        if(a[i]==y) count++;
      }
      if(count>(right-left+1)/2) return y;
    }  
    
    if(x!=-1){
      count=0;
      for(int i=left; i<=right; i++){
        if(a[i]==x) count++;
      }
      if(count>(right-left+1)/2) return x;
    }
    return -1;  
  }
}
        
int solve(vector <int> nums){
    return get_majority_element(nums, 0, nums.size() - 1);
}

int main(){
    fast_cin();
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    solve(arr);
    return 0;
}