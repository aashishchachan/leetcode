#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

void sequence(string str){
    vector<queue<pair<char, int>>> vec;
    for (int i = 0; i<str.length(); ){
        queue<pair<char, int>> que;
        que.push(make_pair(str[i], i));
        i++;
        while(i<str.length() && str[i]==str[i-1]){
            que.push(make_pair(str[i], i));
            i++;
        }   
        vec.push_back(que);
    }

    vector<int> sol(str.length());
    int empty_ques = 0;
    int num = 0;
    while(empty_ques<vec.size()){
        char curr = 'a';
        num++;
        for (int i = 0; i<vec.size(); i++){
            if(!vec[i].empty() &&  vec[i].front().first!=curr){
                if(curr== 'a') curr=vec[i].front().first;
                else if(curr == '1') curr='0';
                else curr = '1';
                
                sol[vec[i].front().second]=num;
                vec[i].pop();
                if(vec[i].empty()) empty_ques++;
                
            }
        }
    }
    cout << num << endl;
    for(int i=0; i < sol.size(); i++){
        cout << sol[i] << " ";
    }
    cout << endl;
    return;
}

int main(){
    fast_cin();
    external_io();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        sequence(str);
    }
    return 0;
}


// #include<stdio.h>
// #include<bits/stdc++.h>
// #include<math.h>
// #include<string.h>
// #define MOD 1000000007
// #define MAXN 100005
// #define pb push_back
// #define mp make_pair
// #define F first
// #define S second
// #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// using namespace std;
// typedef long long ll;
// typedef pair<ll,ll> PP;


// ll modpower(ll a,ll b,ll c)
// {
// 	ll res=1;
// 	while(b)
// 	{
// 		if(b&1LL)
// 			res=(res*a)%c;
// 		a=(a*a)%c;
// 		b>>=1;
// 	}
// 	return res;
// }

// vector<ll> adj[4000];
// set<ll> s;
// ll aa[2002][2002];
// set<pair<ll,ll> > ss;

// int main()
// {

//     fast;

//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         string s;
//         ll n;
//         cin>>n;
//         cin>>s;
//         ll cnt_one=0,cnt_zero=0;
//         ll a[n];
//         for(ll i=0;i<n;i++)
//         {
//             if(s[i]=='0')
//             {
//                 cnt_zero++;
//             }
//             else{
//                 cnt_one++;
//             }
//         }
//         if(cnt_zero==n)
//         {
//             cout<<s.size()<<endl;
//             for(ll i=0;i<n;i++)
//             {
//                 cout<<i+1<<" ";
//             }
//             cout<<endl;
//             continue;
//         }
//         if(cnt_one==n)
//         {
//             cout<<s.size()<<endl;
//             for(ll i=0;i<s.size();i++)
//             {
//                 cout<<i+1<<" ";
//             }
//             cout<<endl;
//             continue;
//         }

//        // vector<ll> ad[max(cnt_one,cnt_zero)+1];
//         ll k=2;
//         stack<ll> lo,lz;
//         if(s[0]=='0')
//         {
//             lo.push(1);
//             //lz=2;
//             //k=2;
//         }
//         else{
//             //lo=2;
//             lz.push(1);
//         }

//         for(ll i=0;i<s.size();i++)
//         {
//             if(s[i]=='0')
//             {
//                 if(lo.size()==0)
//                 {
//                     lo.push(k);
//                     k++;
//                 }
//                 ll j=lo.top();
//                 a[i]=j;
//                 lo.pop();
//                 lz.push(j);
//                // ad[j].pb(i);
//             }
//             else{

//                 if(lz.size()==0)
//                 {
//                     lz.push(k);
//                     k++;
//                 }
//                 ll j=lz.top();
//                 a[i]=j;
//                 lz.pop();
//                 lo.push(j);
//                // ad[j].pb(i);
//             }

//         }
//         cout<<k-1<<endl;
//         for(ll i=0;i<n;i++)
//         {
//             cout<<a[i]<<" ";
//         }
//         cout<<endl;









//     }
// }