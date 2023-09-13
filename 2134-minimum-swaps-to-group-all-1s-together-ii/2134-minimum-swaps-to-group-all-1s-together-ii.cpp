class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int window = 0;
        int n = nums.size();
        int zero = 0;
        
        for(int i:nums) if(i==1) window++;
        
        for(int i=0;i<window;i++) if(nums[i]==0) zero++;
        
        int ans = zero;
        
        for(int i=window; i<n+window; i++){
            
            int j = (i-window) % n;
            
            if(nums[j]==0) 
                zero--;
            if(nums[i%n]==0) 
                zero++;
            
            ans = min(ans,zero);
        }
        return ans;
    }
};