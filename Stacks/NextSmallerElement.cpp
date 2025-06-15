#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NextSmallerElement(int arr[], int size, vector<int>& ans) {
    stack<int> st;
    st.push(-1); // Sentinel value

    for(int i = size - 1; i >= 0; i--) {
        int curr = arr[i];
        while(st.top() >= curr) {
            st.pop();
        }
        ans[i] = st.top(); // Store next smaller
        st.push(curr);
    }

    return ans;
}

int main() {
    int arr[5] = {8, 4, 6, 2, 3};
    int size = 5;
    vector<int> ans(size);
    ans = NextSmallerElement(arr, size, ans);

    for(int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
