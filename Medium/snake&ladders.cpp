#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int n;
pair<int,int> coordinate(int num){
        int row=(num-1)/n;
        int col=(num-1)%n;
        row=n-1-row;
        if ((n-row)%2 == 0) {
        col = n-1-col;
    }
        return make_pair(row,col);
}
//bfs gives minimum steps 
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        vector<vector<bool>> visited (n,vector<bool>(n,false));
        queue<int> q;
        int steps=0;
        q.push(1);
        visited[n-1][0]=true;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                int x=q.front();
                q.pop();
                if(x==n*n) return steps;
                for(int i=1;i<=6;i++){
                    int value=x+i;
                    if(value>n*n) break;
                    pair<int,int> c=coordinate(value);
                    int row=c.first;
                    int col=c.second;
                    if(visited[row][col]==true) continue;
                    visited[row][col]=true;
                    if(board[row][col]==-1){
                        q.push(value);
                    }
                    else{
                        q.push(board[row][col]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};