/*Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

*/
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr(nums.size(), 0);
        for(int i =0, j= 0;i<n;i++){
            arr[j] = nums[i];
            arr[j+1] =nums[i+n];
            j+=2;
        }
        
        return arr;
    }
};
