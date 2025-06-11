#include<iostream>
#include<limits.h>
using namespace std;

int getSmallest(int numbers[],int n) {
    int largest = INT_MAX;
    for(int i = 0;i < n;i++) {
        if(numbers[i] < largest) {
            largest = numbers[i];
        }
    }
    return largest;
}

int main() {
    int numbers[] = {1,2,3,4,5,6};
    int n = 6;
    cout << "The Largest Element is " << getSmallest(numbers,n) << endl; 
}