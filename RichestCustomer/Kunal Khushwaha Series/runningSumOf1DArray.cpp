/*Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.*/
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i =0 ;i<nums.size();i++){
            if(i >= 1 ){
                ans[i]= ans[i-1] + nums[i];
            }else{
                ans[i]= nums[i];
            }
        }
        
        return ans;
    }
};