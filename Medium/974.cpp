#include <bits/stdc++.h>
using namespace std;
// 974. Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
class Solution {
    public:
        int subarraysDivByK(vector<int>& nums, int k) {
            int n=nums.size();
            unordered_map<int,int> mp;
            int res=0;
            int sum=0;
            mp[0]=1;
            for(auto it:nums){
                sum+=it;
                int rem=sum%k;
                if(rem<0) rem+=k;
                if(mp.find(rem)!=mp.end()){
                res+=mp[rem];
                }
                mp[rem]++;
            }
            return res;
        }
    };