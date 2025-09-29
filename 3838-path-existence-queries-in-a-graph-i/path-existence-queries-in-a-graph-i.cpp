class Solution {
public:

    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(x==parent[x]) return x;

        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);

        if(x_parent==y_parent){
            return;
        }

        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;

        }else if(rank[y_parent]>rank[x_parent]){
            parent[x_parent]=y_parent;
        }else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        

        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        vector<pair<int,int>>indexed_nums;

        for(int i = 0; i < n; ++i) {
            indexed_nums.push_back({nums[i], i});
        }

        sort(indexed_nums.begin(),indexed_nums.end());

        for(int i=0;i<nums.size()-1;i++){
                if(indexed_nums[i+1].first-indexed_nums[i].first<=maxDiff){

                    Union(indexed_nums[i].second,indexed_nums[i+1].second);
                }
        }

        vector<bool>ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            int x_parent=find(queries[i][0]);
            int y_parent=find(queries[i][1]);

            if(x_parent==y_parent){
                ans[i]=true;
            }
        }
        return ans;
    }
};