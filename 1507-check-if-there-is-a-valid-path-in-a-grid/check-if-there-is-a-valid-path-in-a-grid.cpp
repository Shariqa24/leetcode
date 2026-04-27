class Solution {
public:
    vector<vector<int>> dirs = {
        {-1,0}, {1,0}, {0,-1}, {0,1}
    };

    vector<vector<int>> typeDirs = {
        {},
        {2, 3},
        {0, 1},
        {2, 1},
        {3, 1},
        {2, 0},
        {3, 0}
    };

    bool isValid(int fromDir, int toType) {
        for (int d : typeDirs[toType]) {
            if ((fromDir == 0 && d == 1) ||
                (fromDir == 1 && d == 0) ||
                (fromDir == 2 && d == 3) ||
                (fromDir == 3 && d == 2))
                return true;
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if (x == m-1 && y == n-1) return true;

            int type = grid[x][y];

            for (int d : typeDirs[type]) {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (vis[nx][ny]) continue;

                int nextType = grid[nx][ny];

                if (isValid(d, nextType)) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};