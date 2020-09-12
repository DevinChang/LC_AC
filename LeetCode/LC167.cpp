

vector<int> twoSum(vector<int> &numbers, int target) {
    int n = numbers.size();
    vector<int> ret;
    for(int i = 0, j = n-1; i < j; i++) {
        while(numbers[i] + numbers[j] > target) j--;
        if(numbers[i] + numbers[j] == target){
            ret.push_back(i+1);
            ret.push_back(j+1);
            break;
        }
    }
    return ret;
}