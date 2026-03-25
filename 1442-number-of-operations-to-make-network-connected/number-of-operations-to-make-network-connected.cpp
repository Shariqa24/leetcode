

class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa != pb) {
            if (rankv[pa] < rankv[pb])
                swap(pa, pb);
            parent[pb] = pa;
            if (rankv[pa] == rankv[pb])
                rankv[pa]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        rankv.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &e : connections)
            unite(e[0], e[1]);

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        return components - 1;
    }
};