class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length()-1;
        while(s[n]==' ')
            n--;
        int wordStart = n;
        for(; n>=0; n--)
            if(s[n]==' ')
                break;
        return wordStart-n;
    }
};