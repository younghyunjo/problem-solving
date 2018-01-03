//https://www.hackerrank.com/challenges/insertionsort1/problem

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> a) {
    for (auto i : a) {
        printf("%d ", i);
    }
    printf("\n");
}

void insertionSort1(int n, vector <int> arr) {
    if (arr.size() == 1) {
        return;
    }

    int V = arr[arr.size()-1];
    int index = arr.size()-2;

    while (index >= 0) {
        if (arr[index] > V) {
            arr[index + 1] = arr[index];
            index--;
            printVector(arr);
        }
        else {
            arr[index+1] = V;
            printVector(arr);
            break;
        }
    }
    if (arr[0] > V) {
        arr[0] = V;
        printVector(arr);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
        cin >> arr[arr_i];
    }
    insertionSort1(n, arr);
    return 0;
}
