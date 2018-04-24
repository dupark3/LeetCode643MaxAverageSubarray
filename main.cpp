#include <algorithm> // accumulate
#include <climits> // INT_MIN
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxAvg = INT_MIN;

        // n - k is the first element of the last subarray
        for (int i = 0; i <= n - k; ++i){
            // i + k is one past the last element of a subarray
            double subarrayAvg = accumulate(nums.begin() + i, nums.begin() + i + k, 0.0) / k;
            if (subarrayAvg > maxAvg) maxAvg = subarrayAvg;
        }
        cout << maxAvg << endl;
    }
};

int main(){
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    Solution s;
    s.findMaxAverage(nums, k);
    return 0;
}