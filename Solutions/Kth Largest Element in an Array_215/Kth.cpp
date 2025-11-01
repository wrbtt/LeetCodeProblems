#include <bits/stdc++.h>
using namespace std;

// Time Limit Exceeded
class Solution {
    private:
        int partition(vector<int>& nums, int left, int right) {
            int pivot = nums[right];
            int i = left;

            for(int j = left; j < right; j++) {
                if (nums[j] >= pivot) {
                    swap(nums[i], nums[j]);
                    i++;
                }
            }
            swap(nums[i], nums[right]);
            return i;
        }

        int quickSelect(vector<int>& nums, int left, int right, int k) {
            int pivot = partition(nums, left, right);

            if (pivot == k - 1)
                return nums[pivot];
            else if (pivot > k - 1) 
                return quickSelect(nums, left, pivot - 1, k);
            else 
                return quickSelect(nums, pivot + 1, right, k);
        }   

    public:
        int findKthLargest(vector<int>& nums, int k) {
            return quickSelect(nums, 0, nums.size() - 1, k);
        }
};

// Time Limit Exceeded
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int,vector<int>, greater<int>> minHeap;

            for(int num : nums) {
                minHeap.push(num);

                if (minHeap.size() > 1) 
                    minHeap.pop();
            }
            minHeap.top();
        }
};


// Time Limit Exceeded
class Solution {
    private:
        int partition(vector<int>& nums, int left, int right) {
            int pivot = nums[right];
            int i = left;

            for(int j = left; j < right; j++) {
                if (nums[j] >= pivot) {
                    swap(nums[i], nums[j]);
                    i++;
                }
            }
            swap(nums[i], nums[right]);
            return i;
        }

    public:
        int findKthLargest(vector<int>& nums, int k) {
            int left = 0, right = nums.size() - 1;

            while(true) {
                int pos = partition(nums, left, right);

                if (pos == k - 1) 
                    return nums[pos];
                else if (pos > k - 1)
                    right = pos - 1;
                else 
                    left = pos + 1;
            } 
        } 
};





class Solution {
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());

        return nums[k - 1];
    }
};