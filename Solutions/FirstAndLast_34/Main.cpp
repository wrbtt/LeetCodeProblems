#include <iostream>
#include "Solution.cpp" 


int main() {
    using namespace std;

    vector<int> nums {5,7,7,8,8,10};
    int target = 0;

    cin >> target;

    Solution s;
    vector<int> result = s.searchRange(nums, target);
    cout << result[0] << ", " << result[1] << endl;

    return 0;
}