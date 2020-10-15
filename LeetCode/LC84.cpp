
int largestRectangleArea(vector<int>& height) {
    if (height.empty()) return 0;
    height.push_back(-1);
    int n = height.size();
    stack<int> st;
    int ret = 0;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && height[st.top()] > height[i]) {
            int cur = st.top();
            st.pop();
            if(st.empty()){
                ret = max(ret, height[cur] * i);
            }
            else {
                ret = max(ret, height[cur] * (i - st.top() - 1));
            }
        }
        st.push(i);
    }
    return ret;
}


int largestRectangleArea(vector<int>& height) {
    int n = height.size();
    stack<int> st;
    int ret = 0;
    vector<int> left(n), right(n);
    for(int i = 0; i < n; i++){
        while(!st.empty() && height[i] <= height[st.top()]) st.pop();
        if(st.empty()) left[i] = -1;
        else left[i] = st.top();
        st.push(i);
    }
    st = stack<int>();
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && height[i] <= height[st.top()]) st.pop();
        if(st.empty()) right[i] = n;
        else right[i] = st.top();
        st.push(i);
    }

    for(int i = 0; i < n; i++){
        ret = max(ret, (right[i] - left[i] - 1) * height[i]);
    }
    return ret;
}