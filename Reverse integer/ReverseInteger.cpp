class Solution {
public:
    int reverse(long x) {
        
    int k = 1;
    vector<long> new_x;
    bool is_negative = false;
    
    
        is_negative = (x < 0) ? true : false;
        x = abs(x);

        while(x > 0){
            new_x.push_back(x % 10);
            x /= 10;
        }
        for(int i=new_x.size()-1; i>=0; i--){
            x += k*new_x[i];
            k *= 10;
        }

        x = (is_negative) ? -x : x;
    
    if(abs(x) >= pow(2,31))
        x = 0;
    
    return x;
        
    }
};