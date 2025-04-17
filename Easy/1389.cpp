#include<bits/stdc++.h>
using namespace std;
// 1389. Create Target Array in the Given Order
// https://leetcode.com/problems/create-target-array-in-the-given-order/description/
class Solution {
    public:
        vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
            int n=nums.size();
            int idxSize=index.size();
            vector<int> res;
            int i=0;
            int j=0;
            for (int i = 0;i<nums.size();++i) {
                res.insert(res.begin()+index[i],nums[i]);
            }
            return res;
        }
    };