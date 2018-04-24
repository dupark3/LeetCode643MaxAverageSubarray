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

        // n - k + 1 is one past the first element of the last subarray
        for (int i = 0; i != n - k + 1; ++i){
            double subarraySum = 0;
            // i + k is one past the last element of a subarray
            for (int j = i; j != i + k; ++j)
                subarraySum += nums[j];
            double subarrayAvg =  subarraySum / k;
            if (subarrayAvg > maxAvg) maxAvg = subarrayAvg;
        }
        cout << maxAvg << endl;
        return maxAvg;
    }
};

int main(){
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    
    Solution s;
    s.findMaxAverage(nums, k);
    return 0;
}