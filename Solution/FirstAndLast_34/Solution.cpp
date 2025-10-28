#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            
            int first = findBound(nums, target, true);
            int last = findBound(nums, target, false);

            return {first, last};
        }

    private:
        int findBound(vector<int>& nums, int target, bool isFirst) {
            int left = 0, right = nums.size() - 1;
            int bound = -1;

            while(left <= right) {
                int mid = left + (right - left) / 2;

                if (nums[mid] == target) {
                    bound = mid;

                    if (isFirst) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return bound;
        }
};