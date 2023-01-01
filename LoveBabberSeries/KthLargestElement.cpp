class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for(auto it: nums){
            heap.push(it);
        }
        while(k != 1){
            heap.pop();
            k--;
        }
        return heap.top();
    }
};

// As the heap store the largest element at the top. Pop the top ke times and return.

