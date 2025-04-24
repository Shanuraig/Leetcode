#include<bits/stdc++.h>
using namespace std;
// 2799. Count Complete Subarrays in an Array
// https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n=nums.size();
            unordered_set<int> st(begin(nums),end(nums));
            int c=st.size();
            unordered_map<int,int> mp;
            int result=0;
            int i=0,j=0;
            while(j<n){
                mp[nums[j]]++;
                while(mp.size()==c){
                    result+=(n-j);
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    i++;
                }
            j++;
            }
            return result;
        }
    };
    //time complexity: O(n)
    //space complexity: O(n)