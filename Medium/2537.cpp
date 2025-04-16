#include <bits/stdc++.h>
using namespace std;
//Count the number of good Sub-Arrays
class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int n=nums.size();
            long long res=0;
            unordered_map<int,int> mp;
            int i=0,j=0;
            long long pairs=0;
            while(j<n){
               pairs+=mp[nums[j]];
               mp[nums[j]]++;
               while(pairs>=k){
                res+=n-j;
                mp[nums[i]]--;
                pairs-=mp[nums[i]];
                i++;
               }
               j++;
            }
            return res;
        }
    };