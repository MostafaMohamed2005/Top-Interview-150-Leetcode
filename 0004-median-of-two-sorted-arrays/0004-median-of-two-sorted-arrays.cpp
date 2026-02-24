class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double a=0,b=0;
        int n=nums1.size(),m = nums2.size(),le = n + m;
        int l = 0,r = n-1;
        while(r >= l){
            int mid = (l+r)/2;
            int pos = mid + 1;
            int last = upper_bound(nums2.begin(),nums2.end(),nums1[mid]) - nums2.begin();
            int first = lower_bound(nums2.begin(),nums2.end(),nums1[mid]) - nums2.begin();

            if(pos+first <= (le+2)/2 && pos+last >= (le+2)/2)
            a = nums1[mid];
            if(pos+first <= le/2 && pos+last >= le/2)
            b = nums1[mid];

            if(pos+last >= (le+2)/2)
            r = mid - 1;
            else
            l = mid + 1;
        }

        l = 0,r = m-1;
        while(r >= l){
            int mid = (l+r)/2;
            int pos = mid + 1;
            int last = upper_bound(nums1.begin(),nums1.end(),nums2[mid]) - nums1.begin();
            int first = lower_bound(nums1.begin(),nums1.end(),nums2[mid]) - nums1.begin();

            if(pos+first <= (le+2)/2 && pos+last >= (le+2)/2)
            a = nums2[mid];
            if(pos+first <= le/2 && pos+last >= le/2)
            b = nums2[mid];

            if(pos+last >= (le+2)/2)
            r = mid - 1;
            else
            l = mid + 1;
        }

        if(le%2 == 1)
        return a;
        else
        return (a+b)/2.0;
    }
};