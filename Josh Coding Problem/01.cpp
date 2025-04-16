#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num:nums)
            strNums.push_back(to_string(num));
        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b) {
            return a + b < b + a;
        });
        if (strNums[0] == "0") return "0";
        string res = "";
        for (const string& s:strNums)
            res += s;
        return res;
    }
};
int main() {
    Solution obj;
    vector<int> arr = {9, 90, 99, 999, 9999};
    cout << obj.smallestNumber(arr) << endl;
    return 0;
}
