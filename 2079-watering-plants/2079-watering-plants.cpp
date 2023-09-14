class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0, c = capacity;
        
        for(int i=0; i<plants.size(); i++){
            if(plants[i] <= c) {
                steps++; 
            }
            else{
                steps += i*2 + 1;
                c = capacity;
            }
            c-=plants[i];
        }
        
        return steps;
    }
};