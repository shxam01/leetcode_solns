// class Solution {
// public:
   
//     bool bfs(int sx,int sy,int tx,int ty){
//         unordered_set<long long> vis;
//         queue<pair<int,int>>q;

//         q.push({tx,ty});
//         vis.insert((long long)tx * 1000000001LL + ty);

//         while(!q.empty()){
//             auto [x,y]=q.front();
//             q.pop();

//             if(x==sx && y==sy) return true;
//             if(x<sx || y<sy) continue;
            
//             vector<pair<int,int>> next_positions;
            
//             if(x>y) next_positions.push_back({x-y,y});
//             if(y>x) next_positions.push_back({x,y-x});

//             for(auto &it:next_positions){
//                 auto nx=it.first;
//                 auto ny=it.second;

//                 long long hash = (long long)nx * 1000000001LL + ny;
//                 if(!vis.count(hash)){
//                     vis.insert(hash);
//                     q.push({nx,ny});
//                 }
//             }
//         }
//         return false;
//     }
//     bool reachingPoints(int sx, int sy, int tx, int ty) {
//         return bfs(sx,sy,tx,ty);
//     }
// };

class Solution {
public:
    bool bfs(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy) {
            if(tx == sx && ty == sy) return true;
            
            if(tx > ty) {
                if(ty == sy) return (tx - sx) % ty == 0;
                tx %= ty;
            } else {
                if(tx == sx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }
        return false;
    }
    
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        return bfs(sx, sy, tx, ty);
    }
};