#include<iostream>
using namespace std;

void Merge(int arr[],int s,int e) {
    int mid = (s + e) / 2;
    //main yahan tk aaya toh mera do sorted array break ho chuka h 
    int lenLeft = mid - s + 1;// maine yaha left ki lenght nikal li h 
    int lenRight = e - mid; // maine yaha right ki length nikal li h 
    
    //toh ab main do left aur right naam ka array banaoonga jisme main numbers ko store karoonga
    int *left = new int[lenLeft];
    int *right = new int[lenRight];
    //  ab main array ke numbers ko utha ki jo maine naya array banaya h usme add kroonga
    
    //main array pe traverse karne ke liye main int k banaoonga
    int k = s;
    for(int i = 0;i < lenLeft;i++) {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for(int i = 0;i < lenRight;i++) {
        right[i] = arr[k];
        k++;
    }
    
    //ab mera yaha se main logic start hoga
    int leftIndex = 0;
    int rightIndex = 0;

    //ab main main array pe traverse krne ke liye main ek variable define karoonga
    int MainArrayIndex = s;
    while(leftIndex < lenLeft && rightIndex < lenRight) {
        if(left[leftIndex] < right[rightIndex]) {
            arr[MainArrayIndex] = left[leftIndex];
            MainArrayIndex++;
            leftIndex++;
        }
        else {
            arr[MainArrayIndex] = right[rightIndex];
            MainArrayIndex++;
            rightIndex++;
        }
    }
    //2 more cases samlbhalna h 
    while(leftIndex < lenLeft) {
        arr[MainArrayIndex] = left[leftIndex];
        MainArrayIndex++;
        leftIndex++;
    }
    //right wala index bacha hua h toh 
    while(rightIndex < lenRight) {
        arr[MainArrayIndex] = right[rightIndex];
        MainArrayIndex++;
        rightIndex++;
    }
    delete[] left;
    delete[] right;
}

void MergeSort(int arr[],int s,int e) {
    //main pehle base case likhoonga
    if(s > e) {
        return;
    }

    if(s == e) {
        return; 
    }
    //break karoonga main
    int mid = (s + e) / 2;
    //ab main recursion ko boolaoonga 
    MergeSort(arr,s,mid);
    MergeSort(arr,mid + 1,e);
    //ab main merge karoonga dono sorted array ko 
    Merge(arr,s,e);
}
int main() {
    int arr[] = {2,1,6,9,4,5};
    int size = 6;
    int s = 0;
    int e = size - 1;
    cout << "Before MergeSort" << endl;
    for(int i = 0;i < size;i++) {
        cout << arr[i] << endl;
    }
    cout << endl;
    MergeSort(arr,s,e);
    cout << "After Merge Sort" << endl;
    for(int i = 0;i < size;i++) {
        cout << arr[i] << endl;
    }
    cout << endl;
}