class Solution {
public:
    int dfs(int &box,set<int>&foundboxes,vector<bool>&vis,vector<int>& status,vector<int>& candies,vector<vector<int>>& keys, vector<vector<int>>& containedBoxes){
        if(vis[box]==true) return 0;

        if(status[box]==0){
            foundboxes.insert(box);
            return 0;
        }
        vis[box]=true;
        int candy=0;
        candy+=candies[box];

        for(auto &insidebox:containedBoxes[box]){
            candy+=dfs(insidebox,foundboxes,vis,status,candies,keys,containedBoxes);
        }
        for(auto &key:keys[box]){
            status[key]=1;
            if(foundboxes.find(key)!=foundboxes.end()){
                candy+=dfs(key,foundboxes,vis,status,candies,keys,containedBoxes);
            }
        }
        return candy;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        set<int>foundboxes;
        int n=candies.size();
        vector<bool>vis(n,false);

        int ans=0;
        for(auto &box:initialBoxes){
            ans+=dfs(box,foundboxes,vis,status,candies,keys,containedBoxes);
        }
        return ans;
    }
};