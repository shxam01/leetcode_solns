class Solution {
public:
    int n;
    int sz;
    bool ischarpresent(string &product,int pos, string &searchWord){
        if(product[pos]==searchWord[pos]){
            return true;
        }
        return false;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        n=products.size();
        sz=searchWord.size();
        vector<vector<string>>ans(sz);
        sort(products.begin(),products.end());
        for(int i=0;i<sz;i++){
            int cnt=0;
            for(int j=0;j<n && cnt<3;j++){
                if(products[j].substr(0, i+1)==searchWord.substr(0, i+1) && products[j].size()>=i+1){
                    ans[i].push_back(products[j]);
                    cnt++;
                }
            }
        }
        return ans;

        
    }
};