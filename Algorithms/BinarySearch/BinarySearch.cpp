#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// Итеративный подход
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Элемент найден
        } else if (arr[mid] < target) {
            left = mid + 1;  // Ищем в правой половине
        } else {
            right = mid - 1; // Ищем в левой половине
        }
    } 
    return -1; // Элемент не найден
}


// Рекурсивный подход
int binarySearch_recursive(const vector<int>& arr, int target, int left, int right) {
    if (left > right) // Базовый случай
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearch_recursive(arr, target, mid + 1, right);
    else 
        return binarySearch_recursive(arr, target, left, mid - 1);
}

// Обертка
int binarySearch_r(const vector<int>& arr, int target) {
    return binarySearch_recursive(arr, target, 0, arr.size() - 1);
}


// STL
void binarySearch_STL(const vector<int>& arr, int target) {

    // std::binary_search - возвращает bool (true or false);
    bool found = binary_search(arr.begin(), arr.end(), target);

    cout << "Element " << target << (found ? "found" : "not found") << endl;

    // std::lower_bound - возвращает итератор к первому элементу >= target
    auto lower = lower_bound(arr.begin(), arr.end(), target);

    if (lower != arr.end() && *lower == target) {
        int index = lower - arr.begin();
        cout << "Found at index: " << index << endl;
    }
    
    // std::upper_bound - возвращает итератор к первому элементу > target
    auto upper = upper_bound(arr.begin(), arr.end(), target);

    int count = upper - lower; // кол-во вхождений target
    cout << "Count of " << target << ": " << count << endl;
}


// По ответу (для задач оптимизации) 
// Пример: найти минимальный x такой, что f(x) >= target
int binarySearch_answer(int target) {
    int left = 0;
    int right = 1e9; // Достаточно большой верхний предел

    while(left < right) {
        int mid = left + (right - left) / 2;

        if (isValid(mid,target)) {
            right = mid; // Пробуем меньшие значения
        } else {
            left = mid + 1; // Увеличваем границу
        }
    }

    return left;
}

bool isValid(int x, int target) {
    return x * x >= target; // Например, найти минимальный x: x2 >= target
}


int binarySearch(int target) {
    int left = 0, right = 1e9;

    while(left < right) {
        int mid = left + (right - left) / 2;

        if (isValid(mid, target))
            right = mid;
        else 
            left = mid + 1;
    }
    return left;
}

bool isValid(int x, int target) {
    return x * x >= target;
}


/////////////////////////////////////////////////////////////////////////////////
int binSearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else 
            right = mid - 1;
    }

    return -1;
}

/////////////////////////////////////////////////////////////////////////////////

int binSearch_recursive(const vector<int>& arr, int target, int left, int right) {
    if (left < right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binSearch_recursive(arr, target, mid + 1, right);
    else
        return binSearch_recursive(arr, target, left, mid - 1);
}

/////////////////////////////////////////////////////////////////////////////////

void binSearch_STL(const vector<int>& arr, int target) {
    bool found = binary_search(arr.begin(), arr.end(), target);

    auto lower = lower_bound(arr.begin(), arr.end(), target);
    if (lower != arr.end() && *lower == target)
        int index = lower - arr.begin();

    auto upper = upper_bound(arr.begin(), arr.end(), target);
    int count = lower - upper;
}

/////////////////////////////////////////////////////////////////////////////////

int binarySearch_answer(const vector<int>& arr, int target) {
    int left = 0;
    int right = 1e9;

    while(left < right) {
        int mid = left + (right - left) / 2;

        if (isValid(mid, target)) 
            right = mid;
        else 
            left = mid + 1;
    }
    return left;
}

bool isValid(int x, int target) { return x * x >= target; }

/////////////////////////////////////////////////////////////////////////////////





// Поиск первого и последнего вхождения

// Первое вхождение target

int firstOccurence(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Продолжаем искать слева
        } else if (arr[mid] < target) {
            left = mid + 1;
        }  else {
            right = mid - 1;
        }
    }

    return result;
}

 
// Последнее вхождение target 

int lastOccurance(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}



////////////////////////////////////////////////



// Мое решение.

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
            int result = -1;


            // первое вхождение
            while(left <= right) {
                int mid = left + (right - left) / 2;

                if (nums[mid] == target) {
                    result = mid;
                    right = mid - 1; 
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else 
                    right = mid - 1;
            } 

            // Второе 
            while(left <= right) {
                int mid = left + (right - left) / 2;

                if (nums[mid] == target) {
                    result = mid;
                    left = mid + 1;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else 
                    right = mid - 1;

            }
        return {};
        }
};


// Мое решение но с внесением поправок

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
          int first = findBound(nums,target,true);
          int last = findBound(nums,target,false);
          return {first, last};
        }

    private:
        int findBound(vector<int>& nums, int target, bool isFirst) {
            int left = 0, right = nums.size() - 1;
            int result = -1;

            while(left <= right) {
                int mid = left + (right - left) / 2;

                if (nums[mid] == target) {
                    result = mid;
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
            return result;
        }
};


struct Solution {
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums,target,true);
        int last = findBound(nums,target,false);

        return {first,last};
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
                    } else  {
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


class Solution {
    private:
        int findBound(vector<int>& nums, int target, bool isFirst) {
            int left = 0, right = nums.size() - 1;
            int result = -1;

            while(left <= right) {
                int mid = left +(right - left) / 2;

                if (nums[mid] == target) {
                    result = mid;

                    if (isFirst) {
                        right = mid - 1;
                    } else 
                        left = mid + 1;
                } else if (nums[mid] < target)
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
            return result;
        }

    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int first = findBound(nums, target, true);
            int last = findBound(nums, target, false);
            return {first, last};
        }
};

