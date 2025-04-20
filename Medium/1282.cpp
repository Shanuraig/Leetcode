#include<bits/stdc++.h>
using namespace std;
// 1282. Group the People Given the Group Size They Belong To
// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/
//leetcode 781 Rabbits in Forest is the follow up question of this problem
class Solution {
    public:
        vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
            int n=groupSizes.size();
            vector<vector<int>> vec(n+1);
            vector<vector<int>> result;
            for(int i=0;i<n;i++){
                int l=groupSizes[i];
                vec[l].push_back(i);
                if(vec[l].size()==l){
                    result.push_back(vec[l]);
                    vec[l]={};
                }
            }
            return result;
        }
    };
    //time complexity: O(n)
    //space complexity: O(n)