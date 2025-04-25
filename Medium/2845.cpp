#include<bits/stdc++.h>
using namespace std;
// 2845. Count of Integers
// https://leetcode.com/problems/count-of-integers/description/
class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
            int n=nums.size();
           for(int i=0;i<n;i++){
            if(nums[i]%m==k){
                nums[i]=1;
            }
            else{
                nums[i]=0;
            }
           }
           unordered_map<int,long long> mp;
        long long res=0;
        long long sum=0;
        mp[0]=1;
        for(auto it:nums){
            sum+=it;
            int r1=sum%m;
            int r2=(r1-k+m)%m;
            res+=mp[r2];
            mp[r1]++;
        }
        return res;
        }
    };