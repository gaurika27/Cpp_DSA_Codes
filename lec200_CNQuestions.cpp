//Largest element in an array
//1)Brute force method
#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    if(n<=0){
        return -1;
    }

    sort(arr.begin(), arr.end());
    return arr[n - 1];   
    }

//2)Optimized method
#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int max = arr[0];
    for (int i = 0; i < n; i++) {
      if (max < arr[i]) {
        max = arr[i];
      }
    }
    return max;
}

