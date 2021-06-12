#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        if(s.length()==0 || s.length()==1) return s.length();
        map <char, int> arr;
        int i=0, j=1, temp=1, max = 1;
        arr[s[i]]=0;
        while(j<s.length()){
            if(!arr.count(s[j])){
                arr[s[j]] = j;
                temp++;
                if(temp>max) max=temp;
                j++;
            }
            else{
                int ind = arr[s[j]];
                while(i<=ind){
                    arr.erase(s[i]);
                    temp--;
                    i++;
                }
            }
        }
        
        return max;
    }


int main(){
    string st;
    cin >> st;
    cout<<lengthOfLongestSubstring(st);
    return 0;
}