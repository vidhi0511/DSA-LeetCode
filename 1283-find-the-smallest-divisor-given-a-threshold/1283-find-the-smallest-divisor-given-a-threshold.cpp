class Solution {
public:
    bool isPossible(vector<int>& nums, int threshold, int m){
        int sum = 0;
        
        for(int i:nums)
        {
            sum += ceil((double)i / (double)(m));
            if(sum > threshold) return false;
        }
        
        return sum <= threshold ;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int l=1, h = *max_element(begin(nums),end(nums));;
        
        while(l<=h)
        {
            int m =l+(h-l)/2;
            bool ans = isPossible(nums,threshold,m);
            
            if(ans)  h = m - 1;
            else l = m + 1;
        }
        
        return l;
    }
};