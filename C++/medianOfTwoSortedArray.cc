#include <vector>
#include <math>
#include <iostream>

using namespace std;

class Solution {
public:
    double getMedian(vector<int> &v){
        auto size = v.size();
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
        vector<int> nums3((int)nums1.size() + (int)nums2.size());

        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin());

        for (auto it : nums3) {
            cout << it << " ";
        }

        cout << endl;
        return getMedian(nums3);
    }
};