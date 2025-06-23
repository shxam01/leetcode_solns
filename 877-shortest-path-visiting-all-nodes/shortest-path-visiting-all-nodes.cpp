class Solution {
public:
    int n;
    typedef pair<int,int> p;

    int shortestPathLength(vector<vector<int>>& graph) {
        n=graph.size();
        if(n==1 || n==0){
            return 0;
        }
        int path=0;

        queue<p>q;
        set<p>visited;

        for(int i=0;i<n;i++){
            int mask=(1<<i);

            q.push({i,mask});
        }

        int final_mask=(1<<n) -1;

        while(!q.empty()){
            int sz=q.size();
            path++;

            while(sz--){
                p curr=q.front();

                auto curr_node=curr.first;
                auto curr_mask=curr.second;

                q.pop();

                for(auto &adj:graph[curr_node]){
                    int next_mask= curr_mask | (1<<adj);

                    if(next_mask==final_mask){
                        return path;
                    }

                    if(visited.find({adj,next_mask})==visited.end()){
                        visited.insert({adj,next_mask});
                        q.push({adj,next_mask});
                    }
                }
            }
        }
        return -1;
    }
};