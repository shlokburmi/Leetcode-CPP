class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        for(int val:nums){  // for each element in the array nums
            int freq=0;     // declaring the variable to count the frequency
        
        for(int el:nums){   // initiated to check the equivalnece of the elements
            if(el == val){  // conditional is applied to check the equivalence of the elements with the value of the element in the array
                freq++;     //
            }
        }
        if(freq > n/2){     // if frequency is greater than half the size of array then the value of the element is returned as the majority element
            return val;
        }
        
    }
    return -1;
}
 
};