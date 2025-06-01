class Solution {
public:
    int result;
    
    int dfs(unordered_map<int,vector<int>>&adj,int curr,int parent,string &s){
        int longest=0;
        int second_longest=0;

        for(auto &child: adj[curr]){
            if(child==parent) continue;

            int child_longest_length=dfs(adj,child,curr,s);

            if(s[child]==s[curr]) continue;

            if(child_longest_length>second_longest) {
                second_longest=child_longest_length;
            }

            if(second_longest>longest){
                swap(second_longest,longest);
            }

            

            
        }
        int neeche_mil_gya_ans=1+longest+second_longest;

        int only_root_achcha=1;

        int koi_ek_acha=1+max(longest,second_longest);

        result=max({result,neeche_mil_gya_ans,only_root_achcha,koi_ek_acha});

        return max(koi_ek_acha,only_root_achcha);
    }


    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();

        result=0;


        unordered_map<int,vector<int>>adj;
        
        for(int i=1;i<n;i++){
            int u=i;
            int v=parent[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(adj,0,-1,s);

        return result;

    }
};