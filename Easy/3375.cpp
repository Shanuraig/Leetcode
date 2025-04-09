#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int n=nums.size();
            unordered_set<int> st;
            for(int i=0;i<n;i++){
                if(nums[i]<k){
                    return -1;
                }
                if(nums[i]>k){
                    st.insert(nums[i]);
                }
            }
            return st.size();
        }
    };
    /*approach -> 
    step 1 ->If the array consist of any element which is less than k , then we cannot perform the operation in the array so just simply return -1 ;
    step 2 -> take an unordered set which stores elements in the array which are larger than k , insert them in the set. the number of larger elements in the set is the total number of operations required to make the array equal to k . 
    */