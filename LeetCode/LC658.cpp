class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (x <= arr[mid])
                r = mid;
            else
                l = mid + 1;
        }
        l--;
        while (r - l - 1 < k && (l >= 0 || r < n)) {
            if (l >= 0 && r < n) {
                if (x - arr[l] <= arr[r] - x)
                    l--;
                else
                    r++;
            }
            else if (l >= 0)
                l--;
            else
                r++;
        }

        vector<int> ans;
        for (int i = l + 1; i < r; i++)
            ans.push_back(arr[i]);
        return ans;
    }

    vector<int> findClosestElements_heap(vector<int>& arr, int k, int x) {
        typedef pair<int,int> PII;
        priority_queue<PII> heap;
        for(auto &a : arr){
            heap.push({abs(a-x), a});
            if(heap.size() > k) heap.pop();
        }
        vector<int> res;
        while(heap.size()) res.push_back(heap.top().second), heap.pop();
        sort(res.begin(), res.end());
        return res;
    }
};