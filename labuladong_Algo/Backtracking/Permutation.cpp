#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& track, vector<bool>& used)
    {
        // base case
        if(track.size()==nums.size())
        {
            res.push_back(track);
            return;
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(used[i])
            {
                // if nums[i] already traversed, skip
                continue;
            }
            // make decision
            track.push_back(nums[i]);
            used[i] = true;
            // traverse to next level
            backtrack(nums, track, used);
            // cancel decision (return back to decision point)
            track.pop_back();
            used[i] = false;
        }

    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        // record the path
        vector<int> track; 
        // record the element in that path is true, avoid duplicate
        vector<bool> used(nums.size(), false);
        backtrack(nums, track, used);
        return res;
    }

    
};