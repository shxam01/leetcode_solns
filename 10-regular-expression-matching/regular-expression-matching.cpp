class Solution {
public:
    int n,m;
    bool helper(string s,string p){
        if(p.length()==0){
            if(s.length()==0) return true;
            return false;
        }

        bool first_char_matched=false;

        if(s.length()>0 && (p[0]==s[0] || p[0]=='.')){
            first_char_matched=true;
        }

        if(p[1]=='*'){
            bool not_take=helper(s,p.substr(2));

            bool take= (first_char_matched && helper(s.substr(1),p));

            return take | not_take;
        }else{

            return (first_char_matched && helper(s.substr(1),p.substr(1)));
        }
        return false;
    }
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        return helper(s,p);
    }
};