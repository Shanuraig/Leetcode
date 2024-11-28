#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
typedef pair<int, pair<int, int>> P; // Properly define the pair type
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX)); // Initialize with max value
        result[0][0] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}}); // Push initial node with distance 0

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int d = curr.first; // Distance from the start
            int i = curr.second.first;
            int j = curr.second.second;

            if (i == m - 1 && j == n - 1) return d; // Early exit if we reach the end

            for (auto& dir : directions) {
                int x = i + dir[0];
                int y = j + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue; // Skip invalid cells

                int wt = (grid[x][y] == 1) ? 1 : 0; // Weight is 1 for obstacles, 0 otherwise
                if (d + wt < result[x][y]) {        // Update if a shorter path is found
                    result[x][y] = d + wt;
                    pq.push({d + wt, {x, y}});
                }
            }
        }

        return result[m - 1][n - 1];
    }
};