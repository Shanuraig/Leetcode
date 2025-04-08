#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    //this approach is brute force 
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
        //this approach is optimised approach
        class Solution1 {
            public:
            
                int minimumOperations(vector<int>& nums) {
                    int cnt=0;
                    int n=nums.size();
                    unordered_set<int> st;
                    for(int i=n-1;i>0;i--){
                        if(st.count(nums[i])){
                           cnt=ceil((i+1)/3.0);
                           return cnt;
                        }
                        st.insert(nums[i]);
                    }
                    return cnt;
                }
            };
    };