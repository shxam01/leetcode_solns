class Solution {
public:
    int n;
    unordered_map<int,vector<int>>adj;
    unordered_map<int,int>BobMap;

    int ans;
    bool DFSBob(int curr,int time,vector<bool>&vis){
        vis[curr]=true;
        BobMap[curr]=time;

        if(curr==0){
            return true;
        }

        for(auto &child:adj[curr]){

           if(!vis[child]){

            if(DFSBob(child,time+1,vis)==true){
                return true;
            }
           }

        }
        BobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr,int time,int income,vector<int>&amount,vector<bool>&vis){
        vis[curr]=true;
        if(BobMap.find(curr)==BobMap.end() || time<BobMap[curr]){
            income +=amount[curr];
        }
        else if(time==BobMap[curr]) {
            income +=amount[curr]/2;
        }

        if(adj[curr].size()==1 && curr!=0){
            ans=max(ans,income);
        }

        for(auto &ngbr:adj[curr]){
            if(!vis[ngbr]){
                DFSAlice(ngbr,time+1,income,amount,vis);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // unordered_map<int,vector<int>>adj;

        ans=INT_MIN;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        n=amount.size();

        vector<bool>vis(n,false);

        int time=0;

        DFSBob(bob,time,vis);

        vis.assign(n,false);
         
        int income=0;

        DFSAlice(0,0,income,amount,vis);

        return ans;

    }
};