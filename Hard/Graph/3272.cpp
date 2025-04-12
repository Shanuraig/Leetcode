#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            unordered_set<string> st;
            //taking half digits of the number 
            int d=(n+1)/2;
            long long start=pow(10,d-1);
            long long end=pow(10,d)-1;
            //this for loop computes the full number which is a valid k palindrome and insert it into the set.
            for(int num=start;num<=end;num++){
                string half=to_string(num);
                string full="";
                if(n%2==0){
                    string right=half;
                    reverse(right.begin(),right.end());
                    full=half+right;
                }
                else{
                    string right=half.substr(0,d-1);
                    reverse(right.begin(),right.end());
                    full=half+right;
                }
                long long number=stoll(full);
                if(number%k!=0) continue;
                sort(full.begin(),full.end());
                st.insert(full);
            }
            //Here we are copmputing the factorial till 10 to avoid function call and save time . 
            vector<long long> factorial(11,1);
            for(int i=1;i<11;i++){
                factorial[i]=i*factorial[i-1];
            }
            // now we are going to find the number of possible permutations for that k-palindromic number to count the good integers . 
            long long result=0;
            //here this for loop traverse the set and extract the nonzerodigits from the number and count the permutation of that k-palindromic number and then store it into the result.
            for(const string &s : st){
                //this vector is used to store the frequency of the digits in the number to extract the count of 0 and subtract it from totaldigits.
                vector<int> count(10,0);
                for(const char &ch : s){
                    count[ch-'0']++;
                }
                int totaldigits=s.length();
                int zerodigits=count[0];
                int nonzerodigits=totaldigits-zerodigits;
                //calculating possible permutations of the k-palindromic number
                long long permutation=(nonzerodigits*factorial[totaldigits-1]);
                //now dividing the permutations with factorial to avoid duplicates .
                for(int i=0;i<10;i++){
                    permutation/=factorial[count[i]];
                }
                //adding the remaining permutations into the result.
                result+=permutation;
            }
            return result;
        }
    };