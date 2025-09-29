class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(x==parent[x]){
            return x;
        }

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
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n,0);

        if(connections.size()<n-1) return -1;

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &pr:connections){
            Union(pr[0],pr[1]);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(parent[i]==i){
                ans++;
            }
        }
        return ans-1;
    }
};