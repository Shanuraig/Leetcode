#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n=nums.size();
            vector<int> ans(n);
            int i=0;
            for(auto it : nums){
                ans[i]=nums[it];
                i++;
            }
            return ans;
        }
    };