class Solution {
private:
    void solve(string digits,vector<string>& ans,string output,int index,string keypadArr[]){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }        
        
        int digit = digits[index] - '0';
        string keys = keypadArr[digit];
        
        for(int i=0;i<keys.length();i++){
            output.push_back(keys[i]);
            solve(digits,ans,output,index+1,keypadArr);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() <=0) return ans;
        string output;
        string keypadArr[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits,ans,output,0,keypadArr);
        return ans;
    }
};