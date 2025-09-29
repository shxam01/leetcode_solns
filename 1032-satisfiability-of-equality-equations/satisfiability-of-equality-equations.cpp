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

        if(x_parent==y_parent){
            return;
        }

        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if(rank[y_parent]>rank[x_parent]){
            parent[x_parent]=y_parent;
        }else{
             parent[x_parent]=y_parent;
             rank[y_parent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {

        parent.resize(26,0);
        rank.resize(26,0);

        for(int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=0;
        }

        for(auto str:equations){
            if(str[1]=='='){
                Union(str[0]-'a',str[3]-'a');
            }
        }

        for(auto str:equations){
            if(str[1]=='!'){
                if(find(str[0]-'a')==find(str[3]-'a')) return false;
            }
        }
        
        return true;
    }
};