#include<bits/stdc++.h>
using namespace std;
// 38. Count and Say
// https://leetcode.com/problems/count-and-say/description/
class Solution {
    public:
        string countAndSay(int n) {
            //base case
            if(n==1) return "1";
            //recursive call
            string say=countAndSay(n-1);
            string res="";
            //process the previous string
            for(int i=0;i<say.length();i++){
                char ch=say[i];
                int count=1;
                //count the number of times a digit appears in the string
                while(i<say.length()-1 && say[i]==say[i+1]){
                    count++;
                    i++;
                }
                res+=to_string(count)+string(1,ch);
            }
            return res;
        }
    };