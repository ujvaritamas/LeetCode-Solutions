#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    double getMedian(const vector<int> &v, const int& size){
        if(size == 0){
            return 0;
        }
        else{
            if(size%2 == 0){
                return static_cast<double>(v[size/2]+v[size/2-1])/2;
            }
            else{
                return static_cast<double>(v[size/2]);
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int merged_size = (int)nums1.size() + (int)nums2.size();
        vector<int> nums3(merged_size);

        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin());

        return getMedian(nums3, merged_size);
    }
};