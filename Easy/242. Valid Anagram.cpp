class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char,int>m1;
        std::unordered_map<char,int>m2;
        
        if(s.size() != t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            m1[s[i]++];
            m2[t[i]++];
        }
        if(m1 == m2) return true;
        return false;

        
    }
};