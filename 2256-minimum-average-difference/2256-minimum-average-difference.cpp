class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long pre=0, total=0;
        int res = INT_MAX, ind=0;
        
        for(int i: nums) total += i;
        
        for(int i=0; i<n; i++){
            pre += nums[i];

            if(i==n-1){
                if(pre/(i+1) < res) return n-1;
                else break;
            }

            int diff = abs((pre/(i+1)) - ((total-pre)/(n-i-1)));

            if(res>diff){
                res = diff;
                ind = i;
            }
        }
        
        return ind;
    }
};