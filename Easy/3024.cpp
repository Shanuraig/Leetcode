#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
                return "equilateral";
        } else if ((nums[0] == nums[1] && nums[1] != nums[2]) ||
                   nums[0] != nums[1] && nums[1] == nums[2]) {
            if ((nums[0] + nums[1]) > nums[2] &&
                (nums[0] + nums[2]) > nums[1] &&
                (nums[1] + nums[2]) > nums[0]) {
                return "isosceles";
            }
        } else if (nums[0] != nums[1] && nums[1] != nums[2]) {
            if ((nums[0] + nums[1]) > nums[2] &&
                (nums[0] + nums[2]) > nums[1] &&
                (nums[1] + nums[2]) > nums[0]) {
                return "scalene";
            }
        }
        return "none";
    }
};