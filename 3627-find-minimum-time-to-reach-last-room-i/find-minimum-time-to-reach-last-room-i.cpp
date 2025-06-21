class Solution {
public:
    int n,m;
    
    typedef pair<int,pair<int,int>> p;

    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }



    int dijkstra(vector<vector<int>>&moveTime,int x_src,int y_src){
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        // vis[x_src][y_src]=true;
        priority_queue<p,vector<p>,greater<p>>pq;

        pq.push({0,{x_src,y_src}});

        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};

        vector<vector<int>>min_time(n,vector<int>(m,INT_MAX));

        min_time[x_src][y_src]=0;

        while(!pq.empty()){
            auto &pr=pq.top();
            auto curr_time=pr.first;
            auto coordinates=pr.second;

            auto x=coordinates.first;
            auto y=coordinates.second;

            pq.pop();

            

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(valid(nx,ny)){
                    int wait_time=max(moveTime[nx][ny]-curr_time,0);
                    int next_time=curr_time+1+wait_time;

                    if(next_time<min_time[nx][ny]){
                        min_time[nx][ny]=next_time;

                        pq.push({min_time[nx][ny],{nx,ny}});
                    }

                }

            }
        }
        return min_time[n-1][m-1];
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        n=moveTime.size();
        m=moveTime[0].size();
        return dijkstra(moveTime,0,0);
    }
};