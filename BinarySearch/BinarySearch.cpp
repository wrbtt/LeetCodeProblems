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
    if (left < right) {
        return -1; // Базовый случай: элемент не найден
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearch_recursive(arr, target, mid + 1, right);
    } else {
        return binarySearch_recursive(arr, target, left, mid - 1);
    }
}

// Обертка для удобства
int binarySearch_recursive(const vector<int>& arr, int target) {
    return binarySearch_recursive(arr, target, 0, arr.size() - 1);
}


int binarySearch_r(const vector<int> arr, int target, int left, int right) {
    if (left < right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearch_r(arr, target, mid + 1, right);
    else 
        return binarySearch_r(arr, target, right, left - 1);
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