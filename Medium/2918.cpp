#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        long long c1=0,c2=0,s1=0,s2=0;
        for(auto &it : nums1){
            s1+=it;
            if(it == 0){
                c1++;
                s1+=1;
            }
        }
        for(auto &it : nums2){
            s2+=it;
            if(it == 0){
                c2++;
                s2+=1;
            }
        }
        if(s1<s2 && c1==0) return -1;
        if(s2<s1 && c2==0) return -1;
    return max(s1,s2);
    }
};