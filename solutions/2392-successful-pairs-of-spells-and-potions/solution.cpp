class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Sort the potions array as we will use binary search here...
        sort(potions.begin(),potions.end());
        
        // Declaring the answer array...
        vector<int> ans(spells.size(),0);
        
        for(int i = 0; i < spells.size(); i++){
            long long n = spells[i];
            
            // the required element can be calculated as follows...
            long long int req = (success/n) + (success%n != 0);
            
            // if the required element is found then all the elements greater than "req" will satisfy the condition...
            int indx = lower_bound(potions.begin(),potions.end(),req) - potions.begin();
            
            // taking all elements greater than  and equal to "req"...
            ans[i] = potions.size() - indx;
            
        }
        
        return ans;
        
    }
};
