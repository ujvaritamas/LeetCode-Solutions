#include <vector>
#include <iostream>

#include <unordered_map>

using namespace std;

//time complexity: O(n^2))
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;

        for(auto i = 0; i < nums.size(); i++) {
            for(auto j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }

        return ret;
    }
};

//optimalized solution (O(n))
class Solution2 {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ret;

        for(auto i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if(m.count(diff)){
                ret.push_back(m[diff]);
                ret.push_back(i);
                return ret;
            }
            m[nums[i]] = i;
        }
        return ret;
    }
};