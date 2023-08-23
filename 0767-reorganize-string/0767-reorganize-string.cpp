class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        for(char c: s){
            m[c]++;
        }
        
        priority_queue<pair<int,char>> p;
        
        for(auto c: m){
            p.push(make_pair(c.second,c.first)); 
        }
        
        string res = "";
        
        while(!p.empty()){
            auto f1 = p.top();
            p.pop();
            
            if(res == "" || res.back() != f1.second){
                res += f1.second;
                
                if(--f1.first > 0){
                    p.push(f1);
                }
            }
            else{
                if(p.empty()) return "";
                auto f2 = p.top();
                p.pop();
                
                res += f2.second;
                
                if(--f2.first > 0){
                    p.push(f2);
                }
                
                p.push(f1);
            }
        }
        return res;
    }
};