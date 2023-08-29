class Solution {
public:
    int bestClosingTime(string customers) {
        int p = 0;
        int res;
        int h=0;
        
        for(int i=0; i<customers.size(); i++)
            if(customers[i] == 'Y') p++;
        
        res = p;
        
        for(int i=0; i<customers.size(); i++)
        {
            if(customers[i] == 'Y') {
                p--;
                if(p < res){
                    res = p;
                    h = i+1;
                }
            }
            else p++;
        }
        return h;
    }
};