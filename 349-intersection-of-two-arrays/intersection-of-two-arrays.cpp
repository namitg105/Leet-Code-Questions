class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums1Set(nums1.begin(), nums1.end());
        set<int> nums2Set(nums2.begin(), nums2.end());
          set<int> intersection;

    set_intersection(
        nums1Set.begin(), nums1Set.end(),
        nums2Set.begin(), nums2Set.end(),
        inserter(intersection, intersection.begin())
    );
        vector<int> v(intersection.begin(), intersection.end());
        return v;

    }
};