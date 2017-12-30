//https://www.hackerrank.com/challenges/big-sorting/problem

#include <bits/stdc++.h>

using namespace std;


int stringCompare(string s1, string s2) {
    if (s1.length() < s2.length()) {
        return -1;
    }
    else if (s1.length() > s2.length()) {
        return 1;
    }
    else {
        for (int i=0; i<s1.length(); i++) {
            if (s1[i] < s2[i])
                return -1;
            else if (s1[i] > s2[i])
                return 1;
        }
    }
    return 0;
}

void merge(vector<string>& arr, int l, int m, int r) {
    vector<string> left;
    left.assign(arr.begin()+l, arr.begin()+m+1);

    vector<string> right;
    right.assign(arr.begin()+m+1, arr.begin()+r+1);

    int lIndex = 0;
    int rIndex = 0;
    int copyIndex = l;

    while (lIndex <= left.size()-1 && rIndex <= right.size()-1) {
        if (stringCompare(left[lIndex], right[rIndex]) < 0) {
            arr[copyIndex] = left[lIndex];
            copyIndex++;
            lIndex++;
        }
        else {
            arr[copyIndex] = right[rIndex];
            copyIndex++;
            rIndex++;
        }
    }

    while(lIndex <= left.size()-1)
        arr[copyIndex++] = left[lIndex++];

    while(rIndex <= right.size()-1)
        arr[copyIndex++] = right[rIndex++];
}

void mergesort(vector<string>& arr, int l, int r) {
    if (l >= r)
        return;

    int m = (l+r)/2;
    mergesort(arr, l, m);
    mergesort(arr, m+1, r);
    merge(arr, l, m, r);
}

vector <string> bigSorting(vector <string> arr) {
    mergesort(arr, 0, arr.size()-1);
    return arr;
}

int main() {
#if 1
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
#else
    int n = 3;
    vector<string>arr = {"6", "1", "3"};
#endif
    vector <string> result = bigSorting(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
