#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    typedef pair<int , pair <int,int>> p;
    vector<vector<int>> directions= {{1,0},{-1,0},{0,1},{0,-1}};
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int m = moveTime.size();
            int n = moveTime[0].size();
            priority_queue<p,vector<p>,greater<p>> pq;
            vector<vector<int>> result(m,vector<int>(n,INT_MAX));
            result[0][0]=0;
            pq.push({0,{0,0}});
            while(!pq.empty()){
                int currtime=pq.top().first;
                auto cell=pq.top().second;
                int i=cell.first;
                int j=cell.second;
                pq.pop();
                if(i == m-1 && j == n-1){
                    return currtime;
                }
                for(auto &dir : directions ){
                    int i_=i+dir[0];
                    int j_=j+dir[1];
                    if(i_>=0 && i_<m && j_>=0 && j_<n){
                        int movetime=(i_+j_)%2==0?2:1;
                        int wait=max(moveTime[i_][j_]-currtime,0); 
                        int newtime=currtime + wait + movetime;
                        if(result[i_][j_]>newtime){
                            result[i_][j_]=newtime;
                            pq.push({newtime, {i_,j_}});
                        }
                    }
                }
            }
            return -1;
        }
    };