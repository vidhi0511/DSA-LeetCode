class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>m1,m2;
        int m=s1.length();
        int n=s2.length();
        
        if(m>n) 
            return false;

        for(int i=0;i<m;i++){
            m1[s1[i]]++;
        }
        
        for(int i=0;i<m;i++){
            m2[s2[i]]++;
        }
        
        if(m1==m2) 
            return true;
        
         for(int i=0;i<n-m;i++)
         {
            if(m2[s2[i]] == 1) 
                m2.erase(s2[i]);
            else 
                m2[s2[i]]--;
             
            m2[s2[i+m]]++;
             
            if(m1==m2) 
                return true;
            
        }
        return false;

    }
};