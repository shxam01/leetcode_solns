class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        

        if(x==parent[x]){
            return x;
        }

        return parent[x]=find(parent[x]);


    }

    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);

        if(x_parent==y_parent) return;

        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }

       unordered_map<string,int>emails_to_idx;
       for(int i=0;i<accounts.size();i++){
        for(int j=1;j<accounts[i].size();j++){
            string email=accounts[i][j];
            if(emails_to_idx.count(email)){
                Union(i,emails_to_idx[email]);
            }else{
                emails_to_idx[email]=i;
            }
        }
       }

        unordered_map<int, vector<string>> merged_emails;
        for(auto const& [email, idx] : emails_to_idx){
            int root_parent = find(idx);
            merged_emails[root_parent].push_back(email);
        }

        vector<vector<string>>ans;

        for(auto &[idx,email]:merged_emails){
            vector<string>temp_emails=email;
            sort(temp_emails.begin(),temp_emails.end());

            string name=accounts[idx][0];

            vector<string>merge;

            merge.push_back(name);

            merge.insert(merge.end(),temp_emails.begin(),temp_emails.end());

            ans.push_back(merge);
        }

        return ans;
    }
};