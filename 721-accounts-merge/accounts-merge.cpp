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
        for(int i=0; i<n; ++i) {
            parent[i] = i;
        }

        // Map emails to the index of the account set they belong to
        unordered_map<string, int> email_to_idx;

        for(int i=0; i<n; ++i){
            for(int j=1; j<accounts[i].size(); ++j){
                string email = accounts[i][j];
                // If we've seen this email before, merge the current account (i)
                // with the account we saw it in before.
                if(email_to_idx.count(email)){
                    Union(i, email_to_idx[email]);
                } else {
                // Otherwise, map this email to the current account index.
                    email_to_idx[email] = i;
                }
            }
        }

        // Group emails by their root parent
        unordered_map<int, vector<string>> merged_emails;
        for(auto const& [email, idx] : email_to_idx){
            int root_parent = find(idx);
            merged_emails[root_parent].push_back(email);
        }

        // Prepare the final result
        vector<vector<string>> result;
        for(auto const& [idx, emails] : merged_emails){
            vector<string> temp_emails = emails;
            sort(temp_emails.begin(), temp_emails.end());
            
            // The name is the first element of the original account at this index
            string name = accounts[idx][0];
            
            vector<string> merged_account;
            merged_account.push_back(name);
            merged_account.insert(merged_account.end(), temp_emails.begin(), temp_emails.end());
            
            result.push_back(merged_account);
        }

        return result;
    }
};