#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n=s.length();
        vector<int> mp(26,0);
        for(char c : s){
            mp[c-'a']++;
        }
        //now perform transformation 
        int res=0;
        while(t--){
            vector<int> newmp(26,0);
            for(int i=0;i<26;i++){
                char ch=i+'a';
                int count=mp[i];
                if(ch!='z'){
                    char next=ch+1;
                    newmp[next-'a']=(newmp[next-'a']+count)%m;
                }
                else{
                    newmp['a'-'a']=(newmp['a'-'a']+count)%m;
                    newmp['b'-'a']=(newmp['b'-'a']+count)%m;
                }
            }
            mp=move(newmp);
        }
        for(int i=0;i<26;i++){
            res=(res+mp[i])%m;
        }
        return res;
    }
};