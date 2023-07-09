class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        if(n<3) return 0;

        vector<int> l(n-2,0),r(n-2,0);

        int lmax=height[0], rmax=height[n-1];

        for(int i=1;i<n-1;i++)
        {
            lmax = max(lmax,height[i]);
            rmax = max(rmax,height[n-1-i]);
            
            l[i-1]+=lmax;
            r[n-2-i]=rmax;
        }
        
        int ans=0;
        for(int i=0;i<n-2;i++){
            ans += min(l[i],r[i])-height[i+1];
        }
        return ans;
    }
};