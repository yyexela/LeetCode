typedef unordered_map<int, int> int_map;
#define int_pair make_pair<int, int>

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Create hash map
        int_map map; 

        // Store running sum
        int sum = 0;
        
        // Effective "0" mod
        map.insert({0, -1});
        
        for (int i = 0; i < nums.size(); i++){
            // Get mod
            sum += nums[i];
            int mod = sum % k;
            
            // Check if it already exists
            if(map.count(mod)){
                int idx = map.at(mod);
                if(i - idx >= 2){return true;}
            }
            
            // Add to map (index, mod)
            map.insert({mod, i});
        }
        
        return false;
    }
};