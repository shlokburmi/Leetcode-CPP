class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0; // iterating thorugh whole array , XOR of all elements in array and unqiue value prints
        for(int i:nums){
            ans=ans^i;  // ^ is XOR function n ^ n =0 and n ^ 0 = n 
        }
        return ans;

        
    }
};