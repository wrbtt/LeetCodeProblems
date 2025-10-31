#include <iostream>
#include "Solution.cpp"

using namespace std;

int main() {
    vector<int> nums {2,7,11,15};
    int target = 9;

    Solution s;
    vector<int> result = s.twoSum(nums, target);
    
    cout << result[0] << ', ' << result[1] << endl;

    return 0;
}