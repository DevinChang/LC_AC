class Solution {
public:
    const double eps = 1e-8;
    int A, B;

    int get(vector<int>& arr, double mid) {
        int res = 0;
        for (int i = 0, j = 0; i < arr.size(); i ++ ) {
            while ((double)arr[j + 1] / arr[i] <= mid) j ++ ;
            if ((double)arr[j] / arr[i] <= mid) res += j + 1;
            if (fabs((double)arr[j] / arr[i] - mid) < eps) {
                A = arr[j], B = arr[i];
            }
        }
        return res;
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0, r = 1;
        while (r - l > eps) {
            double mid = (l + r) / 2;
            if (get(arr, mid) >= k) r = mid;
            else l = mid;
        }

        get(arr, r);
        return {A, B};
    }
};
