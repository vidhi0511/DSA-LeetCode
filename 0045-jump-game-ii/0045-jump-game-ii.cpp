class Solution {
public:
    
    int jump(vector<int>& nums) {
        int jump=0, far=0, curr=0;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            far = max(i+nums[i], far);
            
            if(i==curr){
                jump++;
                curr = far;
            }
        }
        return jump;
    }
};