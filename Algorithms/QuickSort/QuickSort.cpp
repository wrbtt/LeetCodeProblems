#include <algorithm>
#include <cstdlib>
#include <chrono>
using namespace std;


// Базовая быстрая сортировка
class QuickSort {
    private:
        void swap(int& a, int& b) {
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
                sort(nums, pi + 1, high);
                sort(nums, low, pi - 1);
            }
        }
};


// Методы оптимизации
// 1.

class QuickSort {
    private:
        void swap(int& a, int& b) {
            int temp = a;
            a = b;
            b = temp;
        }

        int partition(vector<int>& nums, int low, int high) {
            int randomIndex = low + rand() % (high - low + 1);
            int pivot = nums[randomIndex];

            swap(nums[randomIndex], nums[high]);
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

        void sort(vector<int>& nums) {
            if (!nums.empty())
                sort(nums, 0, nums.size() - 1);
        }
};


// 2. 
class QuickSort {
    private:
        void swap(int& a, int& b) {
            int temp = a; 
            a = b;
            b = temp;
        }

        int partition(vector<int>& nums, int low, int high) {
            int mid = low + (high - low) / 2;

            // Медиана трех: сортируем first, middle, last
            if (nums[low] > nums[mid]) swap(nums[low], nums[mid]);
            if (nums[low] > nums[high]) swap(nums[low], nums[high]);
            if (nums[mid] > nums[high]) swap(nums[mid], nums[high]);

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
    public: 
        void sort(vector<int>& nums, int low, int high) {
            // Оптимизация: для маленьких массивов используем insertion sort 
            if (high - low < 16) {
                insertionSort(nums, low, high);
                return;
            }

            if (low < high) {
                int pi = partition(nums, low, high);
                sort(nums, low, pi - 1);
                sort(nums, pi + 1, high);
            }
        }

        void sort(vector<int>& nums) {
            if (!nums.empty()) {
                sort(nums, 0, nums.size() - 1);
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