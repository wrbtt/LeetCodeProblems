#include <algorithm>
using namespace std;

class QuickSort {
    private:
        void Swap(int& a, int& b) {
            int temp = a;
            a = b;
            b = temp;
        }

        int partition(vector<int>& nums, int low, int high) {
            int mid = low + (high - low) / 2;
            int pivot = nums[mid];

            swap(nums[mid], nums[high]);

            int i = low - 1;

            for(int j = low; j < high; j++) {

                if (nums[j] <= pivot) {
                    i++;
                    swap(nums[i], nums[j]);
                }
            }
            swap(nums[i + 1], nums[high]);
            return i + 1;
        }

    public:
        void sort(vector<int>& nums, int low, int high) {
            if (low < high) {
                int pi = partition(nums, low, high);
                sort(nums, low, pi - 1);
                sort(nums, pi + 1, high);
            }
        }
};

// Гибридная быстрая сортировка

class HybridQuickSort {
    private:
        void swap(int& a, int& b) {

            int temp = a;
            a = b;
            b = temp;
        }

        void insertionSort(vector<int>& nums, int low, int high) {
            
            for(int i = low + 1; i <= high; i++) {

                int key = nums[i];
                int j = i - 1;

                while(j >= low && nums[j] > key) {

                    nums[j + 1] = nums[j];
                    j--;
                }
                nums[j + 1] = key;
            }
        }

        int partition(vector<int>& nums, int low, int high) {

            int mid = low + (high - low) / 2;
            int pivot = nums[mid];

            swap(nums[mid], nums[high]);

            int i = low - 1;
            
            for(int j = low; j < high; j++) {

                if (nums[j] <= pivot) {
                    i++;
                    swap(nums[i], nums[j]);
                }
            }
            swap(nums[i + 1], nums[high]);
            return i + 1;
        }

    public:
        void sort(vector<int>& nums, int low, int high) {
            if (high - low < 10) {
                insertionSort(nums, low, high);
                return;
            }

            if (low < high) {
                
                int pi = partition(nums, low, high);
                sort(nums, low, pi - 1);
                sort(nums, pi + 1, high);
            }
        }
};