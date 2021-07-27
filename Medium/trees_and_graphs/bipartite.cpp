#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005

bool isBipartite(vector<vector<int>>& graph) {
    unordered_set <int> mpa;
    unordered_set <int> mpb;
    mpa.insert(0);
    for(int i=0; i<graph[0].size(); i++){
        mpb.insert(graph[0][i]);
    }   
    for(auto it = bnext.begin(); it!=mpb.end(); it++){
        for(int i=0; i<graph[*it].size(); i++){
            bool check = mpa.insert(graph[*it][i]).second;
            if(!check) return false;
        }
    }

    while(++anext!=mpa.end() && ++bnext!=mpb.end()){
        auto anext = mpa.begin();
        auto bnext = mpb.begin();
        for(auto it = bnext; it!=mpb.end(); it++){
            for(int i=0; i<graph[*it].size(); i++){
                bool check = mpa.insert(graph[*it][i]).second;
                if(!check) return false;
            }
            bnext = it--;
        }

        for(auto it = anext; it!=mpa.end(); it++){
            for(int i=0; i<graph[*it].size(); i++){
                bool check = mpb.insert(graph[*it][i]).second;
                if(!check) return false;
            }
            anext = it--;
        }
    }

    for(int i=0; )


    // for(int i=1; i<graph.size(); i++){
    //     if(mpa.find(i)!=mpa.end()){
    //         for(int j=0; j<graph[i].size(); j++){
    //             if(mpa.find(graph[i][j])!=mpa.end()) return false;
    //             else mpb.insert(graph[i][j]);
    //         }
    //     }
    //     else if(mpb.find(i)!=mpb.end()){
    //         for(int j=0; j<graph[i].size(); j++){
    //             if(mpb.find(graph[i][j])!=mpb.end()) return false;
    //             else mpa.insert(graph[i][j]);
    //         }
    //     }
    //     else{
            

    //     }
    // }
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