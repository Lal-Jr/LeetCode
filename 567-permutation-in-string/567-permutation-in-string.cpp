class Solution {
public:    
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        vector<int> countS1(26, 0), countS2(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            countS1[s1[i] - 'a']++;
            countS2[s2[i] - 'a']++;
        }
        if (countS1 == countS2) return true;
        for (int i = s1.size(); i < s2.size(); ++i) {
            countS2[s2[i] - 'a']++;
            countS2[s2[i - s1.size()] - 'a']--;
            if (countS1 == countS2) return true;
        }
        return false;
    }
};
