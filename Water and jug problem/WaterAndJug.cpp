class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        bool can_measure = false;
        
        if(!x && !y){
            if(!z)
                can_measure = true;
        }
        else if(z > x + y){
            can_measure = false;
        }
        else if(min(x,y) == 0){
            if(z%max(x,y) == 0)
                can_measure = true;
        }
        else{
                while(min(x,y)){
                    int mod_val = max(x,y)%min(x,y);
                    if(z % min(x,y)== mod_val)
                        can_measure = true;

                    if(x == max(x,y))
                        x = mod_val;
                    else
                        y = mod_val;
                }

        }
        return can_measure;
    }
};