class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char,vector<pair<int,int>>>mp; // char, index, freq

        

        for(int j=0;j<garbage.size();j++){
            auto str=garbage[j];
            int cnt_g=0;
            int cnt_m=0;
            int cnt_p=0;
            for(int i=0;i<str.size();i++){
                if(str[i]=='G'){
                    cnt_g++;
                    
                }else if(str[i]=='M'){
                    cnt_m++;
                    
                }else{
                    cnt_p++;
                    
                }
            }
            if(cnt_g>0){
                mp['G'].push_back({j,cnt_g});
            }
            if(cnt_m>0) mp['M'].push_back({j,cnt_m});
            if(cnt_p>0) mp['P'].push_back({j,cnt_p});
        }

        int ans=0;

        for(auto pr:mp){
            auto ch=pr.first;
            auto vec=pr.second;

            auto idx=vec.back().first;
            for(int i=0;i<idx;i++){
                ans +=travel[i];
            }

            for(auto &p:vec){
                ans +=p.second;
            }

            
            
        }
        return ans;
    }
};