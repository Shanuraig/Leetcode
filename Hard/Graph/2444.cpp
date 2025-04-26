#include<bits/stdc++.h>
using namespace std;
// 2444. Count Subarrays With Fixed Bounds
// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            int n=nums.size();
            long long res=0;
            int maxpos=-1;
            int minpos=-1;
            int cp=-1;
            for(int i=0;i<n;i++){
                if(nums[i]>maxK || nums[i]< minK){
                    cp=i;
                }
                if(minK==nums[i]){
                    minpos=i;
                }
                if(maxK==nums[i]){
                    maxpos=i;
                }
                int small=min(minpos,maxpos);
                long long temp=small-cp;
                res+=(temp<=0)?0:temp;
            }
            return res;
        }
    };
