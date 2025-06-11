#include<iostream>
using namespace std;

void ReverseArray(int arr[], int n) {
    int i = 0;
    int j = n - 1;
    while(i <= j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    ReverseArray(arr, n);  // Call the function to reverse the array

    cout << "The reversed array is: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
