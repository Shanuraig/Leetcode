#include<bits/stdc++.h>
using namespace std;
// Here the problem is to count the powerfull integer between the given range -> start to finish . 
// We have just created the solve function to calculate the count , in solve function we passed a string , limit and inputstring or you can say the suffix string . 
// After that we are checking the codition that the given string must me greater than the input/suffix string else return 0;
// now calculate remaining string and remaining length , then iterate through the remaining length and extract the digit from the string and compare it with limit , it must be less than limit now calculate the count using digit*pow(limit+1,remaining length -i-1 ), else just calculate the count for if digit is greater than limit using pow(limit+1,remaining length -i ) and return count .
//now comes the edge case -> if remaining string is greater than the input/suffix string then simply add 1 to the count and return it.  

class Solution {
    public:
    long long solve(string &st,int limit , string &s){
            int sl=st.length();
            if(sl<s.length()) return 0;
            long long count=0;
            string remstring=st.substr(sl-s.length());
            int remlen=sl-s.length();
            for(int i=0;i<remlen;i++){
                    int digit=st[i]-'0';
                if(digit<=limit){
                    count+=digit*pow(limit+1,remlen-i-1);
                }
                else{
                    count+=pow(limit+1,remlen-i);
                    return count;
                }
            }
            if(remstring>=s) count++;
            return count;
        }
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            string st=to_string(start-1),f=to_string(finish);
            return solve(f,limit,s)-solve(st,limit,s);
        }
    };