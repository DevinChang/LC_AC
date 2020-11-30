class Solution {
public:
        int search(vector<vector<int>>& matrix, int target,int n)
    {
        //先从数组左下角元素开始,代表了从当前位置到右上角元素的矩形区域是还没有遍历的区间
        int row = n - 1 ,col = 0;
        int count = 0;
        while(row >=0 && col < n)
        {
            //如果这个当前数组元素小于目标值，说明这个元素以及同列的上方元素都小于目标值。
            //那么count加上row + 1,因为这一列已经遍历过了所以同时把col + 1，
            if(matrix[row][col] <= target)
            {
                count += row + 1;
                col ++;
            }else{//如果当前数组元素大于目标值，则这个元素以及同行的右方元素都大于目标值，
              //因为这一行已经遍历过了，所以col-1
                row --;
            }
        }
        return count;
    }
  int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0],right = matrix[n - 1][n - 1];
        //数组元素小于等于target的个数大于等于k的最小target，二分模板二
        //值域上的二分搜索
        while(left < right)
        {
            int mid = (left + right)/2;
            int count = search(matrix,mid,n);
            if(count >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
  }
};