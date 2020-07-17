class Solution {
public:
    double myPow(double x, int n) {
        long long rest;
        if(n<0){
            rest = -1.0 *   n;
            x = 1 / x;
        }
        else{
            rest = n;
        }
        double ret = 1;        
		int temptimes = 1;
        double tempfactor = x;
        
		while(rest>0){
            ret *= tempfactor;
            rest -= temptimes;
            
            if(rest< 2.0 * temptimes){
                tempfactor= x;
                temptimes = 1;
            }
            else{
                tempfactor *= tempfactor;
                temptimes *= 2;    
            }
        }
        return ret;
    }
};
