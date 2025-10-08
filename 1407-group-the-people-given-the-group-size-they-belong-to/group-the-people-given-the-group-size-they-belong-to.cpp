class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>mp; // size, indexes

       int n=groupSizes.size();

        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            int sz=groupSizes[i];

            mp[sz].push_back(i);
        }

        for(auto pr:mp){
            auto size_of_grp=pr.first;
            auto index_vector=pr.second;

            auto sz_of_index_vec=index_vector.size();

            
            int cnt=sz_of_index_vec/size_of_grp;

            

            if(cnt>1){
                int j=0;
                while(cnt--){
                    vector<int>temp;
                    for(int i=j;i<j+size_of_grp;i++){
                        temp.push_back(index_vector[i]);
                    }
                    j+=size_of_grp;
                    ans.push_back(temp);
                }
            }else{
                ans.push_back(index_vector);
            }
        }
        return ans;
    }
};