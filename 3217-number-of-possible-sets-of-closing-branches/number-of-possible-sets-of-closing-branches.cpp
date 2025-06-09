class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int res=0;

        for(int set=0;set<( 1 << n);set++){

            vector<vector<int>>adj(n,vector<int>(n,1e9)); //adjmatrix

            for(auto &it:roads){
                int u=it[0];
                int v=it[1];
                int wt=it[2];

                if((set>>u &1) && (set>>v &1)){
                    adj[u][v]=min(adj[u][v],wt);
                    adj[v][u]=min(adj[v][u],wt);
                }
            }
            for(int i=0;i<n;i++){
                adj[i][i]=0;
            }

            //floydd warshall to find shortest path from any node to any node -- adj matrix
            for(int via=0;via<n;via++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
                    }
                }
            }

            //check if all shortest paths must be<= maxdistance

            bool ok=true;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    if((set>>i &1) && (set>>j &1)){
                        if(adj[i][j]>maxDistance){
                            ok=false;
                            break;
                        }

                    }
                }
            }
            if(ok) res+=1;

        }
        return res;
    }
    
};