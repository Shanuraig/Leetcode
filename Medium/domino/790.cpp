#include<bits/stdc++.h>
using namespace std;
class solution{
public : 
int count(int n){
    int m=1e9+7;
    vector<long long> res(1000,0);
    res[0]=0,res[1]=1,res[2]=2,res[3]=3;
    if(n>=4){
        for(int i=4;i<=n;i++){
            res[i]=2*res[i-1]+res[i-3];
            res[i]%=m;
        }
    }
    return res[n];
}
};
int main(){
    solution obj1;
    int n;
    cout<<"enter the value of n : "<<endl;
    cin>>n;
    obj1.count(n);
}