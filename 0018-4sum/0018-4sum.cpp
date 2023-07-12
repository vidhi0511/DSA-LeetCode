class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;

            for(int j=i+1; j<n; j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                int x = j+1, y = n-1;
                long long sum1 = nums[i] + nums[j];
                while(x<y)
                {
                     long long sum2 = nums[x] + nums[y];
                    if(sum1 == target-sum2) {
                        res.push_back({nums[i], nums[j], nums[x], nums[y]});
                        y--;
                        x++;
                        while(x<y && nums[y] == nums[y+1]) y--;
                        while(x<y && nums[x] == nums[x-1]) x++;
                    }
                    else if (sum1 > target-sum2) y--;
                    else x++;
                }
            }
        }
        return res;
    }
};