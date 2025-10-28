#include <iostream>
#include "Solution.cpp" 

int main() {
    using namespace std;
    
    vector<int> nums {-1,0,3,5,9,12};
    int target = 9;

    Solution s;
    int index = s.search(nums, target);
    cout << index << endl;

    return 0;
}