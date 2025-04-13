#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    const int M=1e9+7;
    //this power function is used to calculate the power of a number is 
        int findpower(long long a, long long b) {
            if (b == 0)
                return 1;
            long long half = findpower(a, b / 2);
            long long result = (half * half)%M;
            if (b % 2 == 1) {
                result = (result * a)%M;
            }
            return result;
        }
        int countGoodNumbers(long long n) { 
            //number of even indicies are (n+1)/2 and number of odd indicies are n/2.
            return (long long)findpower(5,(n+1)/2)*findpower(4,n/2)%M;
         }
    };
    