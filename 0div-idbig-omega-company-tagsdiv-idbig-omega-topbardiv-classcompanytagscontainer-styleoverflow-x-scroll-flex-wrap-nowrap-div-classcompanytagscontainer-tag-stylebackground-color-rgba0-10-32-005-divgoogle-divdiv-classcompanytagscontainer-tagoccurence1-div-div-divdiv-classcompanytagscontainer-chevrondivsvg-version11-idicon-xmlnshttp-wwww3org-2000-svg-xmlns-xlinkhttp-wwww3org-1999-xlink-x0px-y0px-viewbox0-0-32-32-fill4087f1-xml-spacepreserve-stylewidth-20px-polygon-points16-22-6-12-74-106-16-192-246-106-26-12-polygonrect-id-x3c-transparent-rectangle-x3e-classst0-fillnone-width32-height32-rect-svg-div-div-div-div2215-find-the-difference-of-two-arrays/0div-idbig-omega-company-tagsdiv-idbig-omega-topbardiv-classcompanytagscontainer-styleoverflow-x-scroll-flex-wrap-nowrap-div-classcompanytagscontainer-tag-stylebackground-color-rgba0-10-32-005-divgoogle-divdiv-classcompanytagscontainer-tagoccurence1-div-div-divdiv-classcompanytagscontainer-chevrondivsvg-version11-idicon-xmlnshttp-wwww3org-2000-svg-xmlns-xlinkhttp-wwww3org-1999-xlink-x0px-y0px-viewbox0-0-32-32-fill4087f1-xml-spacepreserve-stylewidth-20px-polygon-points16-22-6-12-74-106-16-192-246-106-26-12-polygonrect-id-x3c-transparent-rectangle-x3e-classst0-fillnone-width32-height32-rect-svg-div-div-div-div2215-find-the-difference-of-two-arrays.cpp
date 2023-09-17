class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2;
        vector<vector<int>> res;
        for(int i:nums1){
            if(s1.find(i) == s1.end()) s1.insert(i);
        }
        for(int i:nums2){
            if(s2.find(i) == s2.end()) s2.insert(i);
        }
        vector<int>v1,v2;
        for(auto i:s1){
            if(s2.find(i) == s2.end()){
                v1.push_back(i);
            } 
        }
        res.push_back(v1);
        
        for(int i:s2){
            if(s1.find(i) == s1.end()){
                v2.push_back(i);
            }
            
        }
        res.push_back(v2);
        return res;
    }
};