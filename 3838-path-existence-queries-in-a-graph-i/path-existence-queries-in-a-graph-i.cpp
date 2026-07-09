class Solution {
public:
    vector<int> parent, rank;

    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);

        if(x==y)
            return;

        if(rank[x]<rank[y])
            parent[x]=y;
        else if(rank[x]>rank[y])
            parent[y]=x;
        else{
            parent[y]=x;
            rank[x]++;
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        parent.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++)
            parent[i]=i;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1] <= maxDiff)
                unite(i,i-1);
        }

        vector<bool> ans;

        for(auto &q:queries){
            ans.push_back(find(q[0])==find(q[1]));
        }

        return ans;
    }
};