/*There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxAvailableCandies = 0;
        for(auto it: candies){
            maxAvailableCandies = max(it, maxAvailableCandies);
        }
        vector<bool> ans(candies.size(), 0);
        for(int i =0;i< candies.size();i++){
            if(candies[i] + extraCandies >= maxAvailableCandies){
                ans[i] = true;
            } else{
                ans[i] = false;
            }
        }
        return ans;
    }
};