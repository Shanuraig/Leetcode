#include<bits/stdc++.h>
using namespace std;
// 2563. Count the Number of Fair Pairs
// https://leetcode.com/problems/count-the-number-of-fair-pairs/description/
class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            int n=nums.size();
            sort(begin(nums),end(nums));
            long long result=0;
            for(int i=0;i<n;i++){
               int idx_x=lower_bound(begin(nums)+i+1,end(nums),lower-nums[i])-begin(nums);
               int idx_y=upper_bound(begin(nums)+i+1,end(nums),upper-nums[i])-begin(nums);
               int x=idx_x-1;
               int y=idx_y-1;
               result+=(y-x);
            }
            return result;
        }
    };