#include<iostream>
using namespace std;

int kthLargest(int arr[], int n, int k){
    // For ignoring the Pass by refrence 
    int temp[n];
    for(int i = 0; i < n ; i++){
        temp[i] = arr[i];
    }
    // Step 1 : Sort the Entire arr into Dec order
    // Using Bubble Sort
    for(int i = 1 ; i <= n - 1; i++){
        bool isSorted = true;
        for(int j = 0; j < n - 1; j++){

            // If Current Element is greater than the Next Element 
            if(temp[j] > temp[j + 1]){
                int val = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = val;
                isSorted = false;
            }
        }
        if(isSorted) break;
    }

    // Step 2 : Return the (n-k)th element
    int idx = k % n; 
    return temp[idx - 1];
}   

void display(int arr[], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {4,7,8,1,2,3};
    int k = 8;
    // By Default array is Passed by refrenced : There is Nothing we can do
    display(arr, 6);
    cout << kthLargest(arr, 6, k) << endl;
    display(arr, 6);
    return 0;
}