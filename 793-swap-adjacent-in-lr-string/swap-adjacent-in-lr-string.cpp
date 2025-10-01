// class Solution {
// public:
    
//     bool bfs(string start, string result){
//         queue<string>q;

//         q.push(start);

//         unordered_set<string>vis;

//         vis.insert(start);

//         // int level=0;

//         while(!q.empty()){
           

           
//                 auto curr=q.front();
//                 q.pop();

//                 if(curr==result) return true;

//                 for(int i=0;i<curr.size()-1;i++){
//                     string next=curr;
//                     if(curr.substr(i,2)=="XL"){
//                         swap(next[i],next[i+1]);
//                         if(vis.find(next)==vis.end()){
//                             q.push(next);
//                             vis.insert(next);
//                         }
//                     }

//                     next=curr;
//                     if(curr.substr(i,2)=="RX"){
//                         swap(next[i],next[i+1]);
//                         if(vis.find(next)==vis.end()){
//                             q.push(next);
//                             vis.insert(next);
//                         }
//                     }
//                 }


          
//         }
//         return false;
//     }
//     bool canTransform(string start, string result) {
//         return bfs(start,result);
//     }
// };

class Solution {
public:
    bool canTransform(string start, string result) {
        // Remove X's and compare
        string s1 = "", s2 = "";
        for(char c : start) if(c != 'X') s1 += c;
        for(char c : result) if(c != 'X') s2 += c;
        
        if(s1 != s2) return false;
        
        // Check movement constraints
        int i = 0, j = 0;
        int n = start.size();
        
        while(i < n && j < n) {
            while(i < n && start[i] == 'X') i++;
            while(j < n && result[j] == 'X') j++;
            
            if(i == n && j == n) return true;
            if(i == n || j == n) return false;
            
            if(start[i] != result[j]) return false;
            
            // L can only move left (j <= i)
            if(start[i] == 'L' && j > i) return false;
            
            // R can only move right (j >= i)
            if(start[i] == 'R' && j < i) return false;
            
            i++;
            j++;
        }
        
        return true;
    }
};