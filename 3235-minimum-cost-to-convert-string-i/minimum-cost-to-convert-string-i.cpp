// class Solution {
// public:
//     int bfs(unordered_map<char,vector<pair<char,int>>>&adj,char initial, char final,unordered_map<char,bool>&vis){
//         if(initial == final) return 0;
        
//         vis[initial]=true;
//         queue<pair<char,int>>q;
//         q.push({initial,0});

//         vector<int>dist(26,INT_MAX);
//         dist[initial-'a']=0;

//         while(!q.empty()){
//             auto character=q.front().first;
//             auto cost_to_reach=q.front().second;
//             q.pop();

//             if(character==final) return cost_to_reach;

//             for(auto &pr:adj[character]){
//                 auto next=pr.first;
//                 auto cost_to_reach_next=pr.second;
                
//                 int new_cost = cost_to_reach + cost_to_reach_next;
                
//                 if(vis[next]==false || new_cost < dist[next-'a']){
//                     vis[next]=true;
//                     dist[next-'a']=new_cost;
//                     q.push({next,new_cost});
//                 }
//             }
//         }
//         return (dist[final-'a'] == INT_MAX) ? -1 : dist[final-'a'];
//     }
    
//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         unordered_map<char,vector<pair<char,int>>>adj;
//         for(int i=0;i<original.size();i++){
//             char A=original[i];
//             char B=changed[i];
//             int cost_to_change=cost[i];
//             adj[A].push_back({B,cost_to_change});
//         }
        
//         long long ans=0;
//         for(int i=0;i<source.size();i++){
//             if(source[i]==target[i]){
//                 continue;
//             }
//             unordered_map<char,bool>vis;
//             int dist=bfs(adj,source[i],target[i],vis);
//             if(dist == -1) return -1;  // Impossible transformation
//             ans+=dist;
//         }
//         return ans;
//     }

class Solution {
public:

    void FloydWarshall(vector<vector<long long>> &adjMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost) {

            for(int i = 0; i < original.size(); i++) {
                int s = original[i] - 'a';
                int t = changed[i] - 'a';

                adjMatrix[s][t] = min(adjMatrix[s][t], (long long)cost[i]);
            }

            //Apply Floyd Warshall
            for (int k = 0; k < 26; ++k) {
                for (int i = 0; i < 26; ++i) {
                    for (int j = 0; j < 26; ++j) {
                        adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]); 
                    }
                }
            }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adjMatrix(26, vector<long long>(26, INT_MAX));

        FloydWarshall(adjMatrix, original, changed, cost); //update adjMatrix with shortest path using Floyd Warshall

        long long ans = 0;

        for(int i = 0; i < source.length(); i++) {
            if(source[i] == target[i]) {
                continue;
            }

            if(adjMatrix[source[i] -'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }

            ans += adjMatrix[source[i] -'a'][target[i] - 'a'];
        }

        return ans;

    }
};