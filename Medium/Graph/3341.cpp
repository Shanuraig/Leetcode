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
                        int wait=max(moveTime[i_][j_]-currtime,0); 
                        int newtime=currtime + wait + 1;
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

class solution1{
public : 
//This is the function for dijistra algorith to find the shortest path or time , to reach to a destination from a given source 
/*vector<int> dijistra(int v , vector<vector<int>> adj[] , int source){
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>()>> pq;
    vector<int> result (v,INT_MAX);
    result[source]=0;
    pq.push({0,source});
    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto &vec : adj[node]){
            int adjnode=vec[0];
            int weight=vec[1];
            if(d+weight< result[adjnode]){
                result[adjnode]=d+weight;
                pq.push({d+weight,adjnode});
            }
        }
    }
    return result;
}
    */
//Now we are going to solve the problem leetcode 3341 medium 
};