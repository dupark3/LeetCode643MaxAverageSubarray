#include <climits>
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
            double subarraySum = 0;

            // i + k - 1 is the last element of a subarray
            for(int j = i; j <= i + k - 1; ++j)
                subarraySum += nums[j]; 
            
            // update maxAvg with new average if it is greater
            double subarrayAvg = subarraySum / k;
            if (subarrayAvg > maxAvg) 
                maxAvg = subarrayAvg;
        }
        cout << maxAvg << endl;
    }
};

int main(){
    vector<int> nums;
    for(int i = 0; i != 30000; ++i)
        nums.push_back(10000);
    int k = 5;
    Solution s;
    s.findMaxAverage(nums, k);
    return 0;
}