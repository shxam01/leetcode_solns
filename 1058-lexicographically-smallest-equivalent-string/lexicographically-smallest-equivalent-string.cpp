class Solution {
public:


    char dfs(unordered_map<char,vector<char>>&adj,char curr_ch,vector<int>&vis){
        vis[curr_ch-'a']=1;
        char minChar=curr_ch;
        for(auto &v:adj[curr_ch]){

            if(vis[v-'a']==0){
                minChar=min(minChar,dfs(adj,v,vis));
            }
        }
        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,vector<char>>adj;

        int n=s1.length();
        for(int i=0;i<n;i++){
            char ch1=s1[i];
            char ch2=s2[i];

            adj[ch1].push_back(ch2);
            adj[ch2].push_back(ch1);
        }
        int m=baseStr.length();

        string result;

        for(int i=0;i<m;i++){
            char ch=baseStr[i];
            vector<int>visited(26,0);
            char minChar=dfs(adj,ch,visited);

            result.push_back(minChar);
        }
        return result;
    }
};