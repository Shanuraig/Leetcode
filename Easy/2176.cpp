#include<bits/stdc++.h>
using namespace std;
// 2176. Count Equal and Divisible Pairs in an Array
// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/
class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int n=nums.size();
            int count=0;
            int i=0;
            int j=1;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(nums[i]==nums[j] && (i*j)%k==0) count++;
                }
            }
            return count;
        }
    };