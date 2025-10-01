class Solution {
public:
    int bfs(string s1,string s2){
        int ans=0;

        if(s1==s2) return 0;

        unordered_set<string>vis;

        vis.insert(s1);


        queue<pair<string,pair<int,int>>>q;

        q.push({s1,{0,0}});

        while(!q.empty()){
            auto pr=q.front();
            auto curr_str=pr.first;
            auto idx=pr.second.first;
            auto steps=pr.second.second;
            q.pop();

            // vis.insert(curr_str);

            if(curr_str==s2) return steps;

            while(idx < curr_str.size() && curr_str[idx]==s2[idx]){
                idx++;
            }
            for(int i=idx+1;i<s2.size();i++){
                if(curr_str[i]==s2[idx]){
                    string next_str = curr_str;
                    swap(next_str[i],next_str[idx]);
                    
                    if(next_str==s2) return steps+1;

                    if(vis.find(next_str)==vis.end()){
                        vis.insert(next_str);
                        q.push({next_str,{idx+1,steps+1}});
                    }
                }
            }
        }
        return -1;
    }
    int kSimilarity(string s1, string s2) {
        return bfs(s1,s2);
    }
};