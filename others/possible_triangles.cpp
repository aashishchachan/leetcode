// Given the array of sides, count the number of possible triangles. 

#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

int triangles(vector <int> sides){
    sort(sides.begin(), sides.end());
    int sol=0;
    int l, m, r;
    for (int i = sides.size() - 1; i>=2; i--){
        r = sides[i];
        m = sides[i - 1];
        l = m;
        int k;
        for (int j = i - 2; j >= 0; j--){
            l = sides[j];
            if(l+m>r) {
                m = l;
                k = j;
            }
            else break;
        }
        sol += (i-k)*(i-k-1)/2;
    }

    return sol;
}

int main(){
    fast_cin();
    external_io();
    int n;
    cin>>n;
    vector <int> sides(n);
    for(int i=0; i<n; i++){
        cin>>sides[i];
    }
    int sol =triangles(sides);
    cout << sol;
    return 0;
}
