class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {
        vector<int> res;
        int n = changed.size();
        
        if(n%2 != 0) return {};
        sort(changed.begin(),changed.end());
        unordered_map<int,int>m;
        for(int i: changed){
            if(i % 2 != 0){
                m[i]++;
            }
            else{
                if(m.find(i*2) != m.end()){
                    if(m[i*2]==1) m.erase(i*2);
                    else m[i*2]--;
                    res.push_back(i);
                }
                else if(m.find(i/2) != m.end()){
                    if(m[i/2]==1) m.erase(i/2);
                    else m[i/2]--;
                    res.push_back(i/2);
                }
                else m[i]++;
            }
        }

        if(m.size()>0) return {};
        return res;
    }
};