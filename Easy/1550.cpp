#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int oddcount=0;
        int maxodd=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2!=0){
                oddcount++;
            }
            else{
                oddcount=0;
            }
            maxodd=max(maxodd,oddcount);

        }
        return maxodd>=3?true : false;
    }
};