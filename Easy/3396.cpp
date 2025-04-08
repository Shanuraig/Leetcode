#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool check (int start,vector<int> &nums ,int n){
        unordered_set<int> st;
        for(int i=start;i<n;i++){
            if(st.count(nums[i])) return false;
            st.insert(nums[i]);
        }
        return true;
    }
        int minimumOperations(vector<int>& nums) {
            int cnt=0;
            int n=nums.size();
            for(int i=0;i<n;i+=3){
                if(check(i,nums,n)==true){
                    return cnt;
                }
                cnt++;
            }
            return cnt;
        }
    };