class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int pre = 1, suf = 1;
        int maxpro = INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(pre==0) pre=1;
            if(suf==0) suf=1;
             
            pre *= nums[i];
            suf *= nums[n-i-1];
            maxpro = max(maxpro,max(pre,suf));
        }

    
        return maxpro;
    }
};