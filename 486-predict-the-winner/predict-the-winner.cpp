class Solution {
public:
    int solve(vector<int>& nums,int l, int r){
        //base case
        if(l == r)
            return nums[l];

        int pickLeft = nums[l] - solve(nums, l+1, r);
        int pickRight = nums[r] - solve(nums, l, r-1);
        return max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int left=0, right= nums.size()-1;

        if(solve(nums, left, right) >= 0)
            return true;
        return false;
    }
};