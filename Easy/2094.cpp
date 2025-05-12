#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> result;
        vector<int> count(10);
        for (auto it : digits) { count[it]++; }
        for (int a = 1; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 8; c += 2) {
                    if(count[a] > 0 && count[b] > (b==a) && count[c] > (c==a)+(c==b)){
                    result.push_back(a*100+b*10+c);
                    }
                }
            }
        }
        return result;
    }
};