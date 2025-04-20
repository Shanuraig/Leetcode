#include<bits/stdc++.h>
using namespace std;
// 781. Rabbits in Forest
// https://leetcode.com/problems/rabbits-in-forest/description/
class Solution {
    public:
     int numRabbits(vector<int>& answers) {
       int ans = 0;
       vector<int> count(1000);
       for (const int answer : answers) {
         if (count[answer] % (answer + 1) == 0)
           ans += answer + 1;
         count[answer]++; 
       }
       return ans;
     }
   };
   //time complexity: O(n)
   //space complexity: O(1)