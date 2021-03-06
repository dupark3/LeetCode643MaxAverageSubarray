#include <algorithm> // accumulate
#include <climits> // INT_MIN
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxSum = INT_MIN;
        double subarraySum = 0;

        // n - k is the first element of the last subarray
        for (int i = 0; i <= n - k; ++i){
            if (i > 0){
                subarraySum = subarraySum - nums[i-1] + nums[i+k-1];
            } else {
                for (int j = i; j != i + k; ++j)
                    subarraySum += nums[j];
            }            
            
            if (subarraySum > maxSum) 
                maxSum = subarraySum;
        }
        cout << maxSum / k << endl;
        return maxSum / k;
    }
};

int main(){
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    
    Solution s;
    s.findMaxAverage(nums, k);
    return 0;
}