// class Solution {
// public:
//     bool isSimilar(string &a, string &b) {
//         int cnt = 0;
//         int n = a.size();
//         int m = b.size();
//         if (n != m) return false;
//         for (int i = 0; i < n; i++) {
//             if (a[i] != b[i]) {
//                 cnt++;
//                 if (cnt > 2) return false;
//             }
//         }
//         return cnt == 2;
//     }

//     void dfs(unordered_map<string, vector<string>> &adj, unordered_map<string, bool> &vis, string &str) {
//         vis[str] = true;
//         for (auto &next : adj[str]) {
//             if (!vis[next]) {
//                 dfs(adj, vis, next);
//             }
//         }
//     }
    
//     int numSimilarGroups(vector<string>& strs) {
//         int n = strs.size();
//         unordered_map<string, vector<string>> adj;

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (isSimilar(strs[i], strs[j])) {
//                     adj[strs[i]].push_back(strs[j]);
//                     adj[strs[j]].push_back(strs[i]);
//                 }
//             }
//         }

//         int cnt = 0;
//         unordered_map<string, bool> vis;
        
//         for (auto &str : strs) {
//             if (!vis[str]) {
//                 cnt++;
//                 dfs(adj, vis, str);
//             }
//         }
//         return cnt;
//     }
// };


class Solution{
public:
    int N;
    
    bool isSimilar(string &a,string &b){
        int n=a.size();
        int m=b.size();
        if(n!=m) return false;

        int cnt=0;

        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                cnt++;
                if(cnt>2) return false;
            }
        }
        return cnt<=2;
    }

    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(x==parent[x]) return x;

        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);

        if(x_parent==y_parent) return;

        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }


    int numSimilarGroups(vector<string>& strs){
        N=strs.size();
        parent.resize(N);
        rank.resize(N,0);
        for(int i=0;i<N;i++) parent[i]=i;

        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs.size();j++){
                if(i!=j && isSimilar(strs[i],strs[j])){
                    Union(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<N;i++){
            if(parent[i]==i) ans++;
        }
        return ans;
    }

};