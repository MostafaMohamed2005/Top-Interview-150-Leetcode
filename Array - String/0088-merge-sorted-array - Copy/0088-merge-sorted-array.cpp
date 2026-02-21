class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1,j = n-1, z = n + m - 1;

        while(z >= 0 && i >= 0 && j >= 0){
            if(nums1[i] > nums2[j])
            nums1[z] = nums1[i],i--;
            else
            nums1[z] = nums2[j],j--;
            z--;
        }

        while(j >= 0)
        {
            nums1[j] = nums2[j]; 
            j--;
        }
    }
};