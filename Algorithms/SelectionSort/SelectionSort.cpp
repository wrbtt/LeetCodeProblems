#include <vector>
#include <algorithm>

using namespace std;

class SelectionSort {
    private:
        void swap(int& a, int& b) {
            int temp = a;
            a = b;
            b = temp;
        }

    public:
        void sort(vector<int>& nums) {
            int n = nums.size();

            for(int i = 0; i < n - 1; i++) {
                int min_index = i;

                for(int j = i + 1; j < n; j++) {
                    if (nums[j] < nums[min_index]) {
                        min_index = j;
                    }
                }

                swap(nums[i], nums[min_index]);
            }
        }
};

class SolutionSort {
    private:
        void swap(int& a, int& b) {
            int temp = a;
            a = b;
            b = temp;
        }

    public:
        void sort(vector<int>& nums) {
            int n = nums.size();

            for(int i = 0; i < n - 1; i++) {
                int min_index = i;

                for(int j = i + 1; j < n; j++) {
                    if (nums[j] < nums[min_index]) {
                        min_index = j;
                    }
                }
                swap(nums[i], nums[min_index]);
            }
        }
};

   

// Selection Sort делает ровно n-1 обменов

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int nonZeroPos = 0;

            for(int i = 0; i < nums.size(); i++) {
                if (nums[i] != 0) {
                    swap(nums[nonZeroPos++], nums[i]);
                }
            }
        }
};


// 

class Solution {
    public: 
        int findKthLargest(vector<int>& nums, int k) {
            // Можно решить модифицированным selection sort

            for(int i = 0; i < k; i++) {
                int maxIndex = i;

                for(int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] > nums[maxIndex]) {
                        maxIndex = j;
                    }
                }
                swap(nums[i], nums[maxIndex]);
            }
            return nums[k-1];
        }
};

// O(n log n)

// Сортировка интервалов

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if (intervals.empty()) return {};

            sort(intervals.begin(), intervals.end());

            vector<vector<int>> merged;
            for(auto interval : intervals) {
                if (merged.empty() || merged.back()[1] < interval[0]) {
                    merged.push_back(interval);
                } else {
                    merged.back()[1] = max(merged.back()[1], interval[1]);
                }
            }
            return merged;
        }
};

// partition 
// Использует трехстороннюю partition из quick sort
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int low = 0;
            int mid = 0;
            int high = nums.size() - 1;

            while(mid <= high) {
                if (nums[mid] == 0) {
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                } else if (nums[mid] == 1) {
                    mid++;
                } else {
                    swap(nums[mid], nums[high]);
                    high--;
                }
            }
        }
};

// Quick Select

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