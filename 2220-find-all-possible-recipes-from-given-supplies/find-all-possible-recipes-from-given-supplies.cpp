class Solution {
public:
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        int sz=recipes.size();
        unordered_set<string>st(supplies.begin(),supplies.end());
        vector<string>res;
        vector<bool>cooked(n,false);
        while(sz--){
            for(int i=0;i<n;i++){
                if(cooked[i]) continue;
                bool banpayega=true;
                for(int j=0;j<ingredients[i].size();j++){
                    if(st.find(ingredients[i][j])==st.end()){
                        banpayega=false;
                        break;
                    }
                }
                if(banpayega){
                    res.push_back(recipes[i]);
                    st.insert(recipes[i]);
                    cooked[i]=true;
                }
            }
        }
        return res;

    }
};