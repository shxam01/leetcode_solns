class Solution {
public:

   vector<int>parent;
   int components;
   int find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x]);
   }

   void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);

    if(x_parent!=y_parent){
        parent[x_parent]=y_parent;
        components--;
    }
   }


    // int 
    
    int minSwapsCouples(vector<int>& row) {
        int total_couples=row.size()/2;
        components=total_couples;

        parent.resize(total_couples);

        for(int i=0;i<total_couples;i++){
            parent[i]=i;
        }

        for(int i=0;i<row.size()-1;i+=2){
            int person1=row[i];
            int person2=row[i+1];

            int couple_id_1=person1/2;
            int couple_id_2=person2/2;

            Union(couple_id_1,couple_id_2);
        }
        return total_couples-components;
    }
};