

int compareVersion(string version1, string version2) {
    int n1 = version1.size(), n2 = version2.size();
    for(int i = 0, j = 0; i < n1 || j < n2; i++, j++){
        int nums1 = 0, nums2 = 0;
        while(i < n1 && version1[i] != '.') {
            nums1 = nums1*10 + version1[i]-'0';
            i++;
        }
        while(j < n2 && version2[j] != '.') {
            nums2 = nums2*10 + version2[j]-'0';
            j++;
        }
        if(nums1 < nums2) return -1;
        else if (nums1 > nums2) return 1;
    }
    return 0;
}