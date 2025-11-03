#include <algorithm>
using namespace std;


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
};



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
                sort(nums, low, pi - 1);
                sort(nums, pi + 1, high);
            }
        }
};  





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






// Заучить!

// Подход Разделяй и властвуй
class ArraySum {
    private:
        int sumRecursive(vector<int>& nums, int left, int right) {

            // Базовый случай
            if (left == right)
                return nums[left];

            // Базовый случай
            if (left > right)
                return 0;

            // разделяем массив пополам
            int mid = left + (right - left) / 2;

            // рекурсивно вычисляем суммы половин
            int leftSum = sumRecursive(nums, left, mid);
            int rightSum = sumRecursive(nums, mid + 1, right);

            // Объединяем результаты
            return leftSum + rightSum;
        }

    public:
        int sum(vector<int>& nums) {
            return sumRecursive(nums, 0, nums.size() - 1);
        }
};

// Более читаемая версия
class SimpleArraySum {
    private:
        int sumHelper(vector<int>& nums, int start, int end) {

            //  Базовый случай: один элемент
            if (start == end) {
                return nums[start];
            }

            int mid = (start + end) / 2;

            // Рекурсивно суммируем обе половины и объединяем
            return sumHelper(nums, start, mid) + sumHelper(nums, mid + 1, end);
        }
};
//////////////////////////////////

class ListCounter {
    public:
        // Простая рекурсия - уменьшаем задачу на 1 элемент
        int countLinear(vector<int>& nums) {
            return countLinearHelper(nums, 0);
        }

        // Разделяй и властвуй - делим пополам
        int countDivideConquer(vector<int>& nums) {
            return countDCHelper(nums, 0, nums.size() - 1);
        }

    private:
        // Линейный рекурсивный подход
        int countLinearHelper(vector<int>& nums, int index) {

            // Базовый случай: дошли до конца списка
            if (index == nums.size()) 
                return 0;

            // Рекурсивный случай: 1 + кол-во оставшихся элементов
            return 1 + countLinearHelper(nums, index + 1);
        }

        // Разделяй и властвуй
        int countDCHelper(vector<int>& nums, int left, int right) {

            // Базовый случай: пустой диапазон
            if (left > right) {
                return 0;
            }

            // Базовый случай: один элемент
            if (left == right) {
                return 1;
            }

            // разделяем пополам
            int mid = left + (right - left) / 2;

            // рекурсивно считаем в каждой половине
            int leftCount = countDCHelper(nums, left, mid);
            int rightCount = countDCHelper(nums, mid + 1, right);

            // Объединяем результаты
            return leftCount + rightCount;
        }
};

// Для LinkedList

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} 
};

class LinkedListCounter {
    public:
        int count(ListNode* head) {
            // Базовый случай: пустой список
            if (head == nullptr) {
                return 0;
            }

            // Рекурсивный случай: 1 + кол-во в оставшемся списке
            return 1 + count(head -> next);
        }
};

// с Использованием хвостовой рекурсии

class TailRecursionCounter {
    private:
        int countTailHelper(vector<int>& nums, int index, int accumulator) {
            // Базовый случай: дошли до конца
            if (index == nums.size()) 
                return accumulator;

            // Хвостовая рекурсия: накапливаем результат
            return countTailHelper(nums, index + 1, accumulator + 1);
        }
};
///////////////////////////////////////////////////////////

























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