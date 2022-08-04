class Solution {
public:
    double findPower(double x,int n){
        if(n==0)
            return 1.0;
        double ans=findPower(x,n/2);
            if(n&1) return x*ans*ans;
            else return ans*ans;
    }
    double myPow(double x, int n){
        if(n>0)
            return findPower(x,n);
        else{
            int a=abs(n);
            double r=findPower(x,a);
            double x=1/r;
            return x;
        }
    
    }
};