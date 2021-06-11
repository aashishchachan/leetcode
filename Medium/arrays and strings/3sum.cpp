//this is a very lengthy solution. use hash map instead.


#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define mod 1000000007
#define forn(i, k, n) for(ll i=k; i<n; i++)
#define bfor(i, k, n) for(ll i=k; i>n; i--)
#define mp make_pair
#define pb push_back
#define des greater<int> 
#define sint <int>
#define sll <long long> 
#define llll <long long, long long>
#define stll <string, long long>
#define sstr <string>
#define intint <int,int>
#define stst <string, string>
#define stint <string, int>
#define debug cout<<"hello"<<endl;
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);


void findSum(vector sint::iterator start, vector sint::iterator end, int sum, set <vector sint> &sol){
    int comp;
    if(sum<0) comp=abs(sum);
    else comp= sum-2*sum;
    while(start<end){
        if (*start + *end == comp){
            while( start<end && (*(end-1)) == (*end)){ 
                end--;
            }
            while(start<end && *(start+1)==*start){ 
                start++;
            }
              
            vector sint temps;
            temps.push_back(sum); 
            temps.push_back(*start); temps.push_back(*end); sol.insert(temps);
            
            start++;
            end--;
        }
        else if(*start + *end > comp) end--;
        else start++;
    }
}

int main(){
    fast_cin();
    vector sint nums, temps;
    set <vector sint> sol;
    vector <vector sint> fsol;
    int n,temp; 
    cin>>n;
    forn(i, 0, n){
        cin>>temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    vector sint::iterator neut;
    int nt=-1;
    forn(i,0,n){
        if (nums[i]<0) continue;
        else neut = nums.begin() + i;
        nt =i;
        break;
    }

    int j=n-1;

    if(n<3) goto terminate;
    if(nt==-1 ) goto terminate;
    else if(nt==0){
        if (nums.size()>=3 && *neut==0 && *(neut+1)==0 && *(neut+2)==0){
            sol.insert({0,0,0});
            goto terminate;
        }
        else goto terminate;
    }
    else if(nums.size()-nt>=3 && *neut==0 && *(neut+1)==0 && *(neut+2)==0){
        sol.insert({0,0,0});
    }
    else if(*(nums.end()-1)==0) goto terminate; 

    forn(i,0,nt){
        if(i>0 && nums[i-1]==nums[i]) continue;
        int sum = nums[i];
        for(j=j; j>nt-1; j--){
            if (nums[j]<= abs(sum)){
                findSum(neut, nums.begin()+j, sum, sol);
                break;
            }
        }
    }

    j=0;
    bfor(i,n-1,nt-1){
        if(i<n-1 && nums[i]==nums[i+1]) continue;
        int sum = nums[i];
        for(j=j; j<nt; j++){
            if (abs(nums[j])<= abs(sum)){
                findSum(nums.begin()+j, neut-1, sum, sol);
                break;
            }
        }
    }

    terminate:
    for (auto it = sol.begin(); it != sol.end();it++) {
        fsol.push_back(*it);
    }

    forn(i,0,fsol.size()){
        forn(j,0,3){
            cout<<fsol[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}