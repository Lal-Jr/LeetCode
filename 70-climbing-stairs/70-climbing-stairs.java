class Solution {
    public int climbStairs(int n) {
        if(n==1)
            return 1;
        int firstSol = 1, secondSol = 2;
        for(int i=3;i<=n;i++)
        {
            int sum = firstSol+secondSol;
            firstSol=secondSol;
            secondSol=sum;
        }
        return secondSol;
    }
}