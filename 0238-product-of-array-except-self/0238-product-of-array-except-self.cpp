class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n);

        pre[0] = nums[0];
        suf[n-1] = nums[n-1];

        for(int i=1; i<n; i++)
        {
            if(pre[i-1] != 0) 
                pre[i] = pre[i-1] * nums[i];
            
            if(suf[n-i] != 0) 
                suf[n-i-1] = suf[n-i] * nums[n-i-1];
        }
        
        for(int i=0; i<n; i++)
        {
            if(i==0)
                nums[i] = suf[i+1];
            
            else if(i==n-1)
                nums[i] = pre[i-1];
            
            else 
                nums[i] = pre[i-1] * suf[i+1];
        }
        
        return nums;

    }
};