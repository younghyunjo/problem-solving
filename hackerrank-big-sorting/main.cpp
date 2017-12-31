//https://www.hackerrank.com/challenges/big-sorting/problem

#include <bits/stdc++.h>

using namespace std;

bool compare(string& s1, string& s2) {
    if (s1.length() < s2.length()) {
        return true;
    }
    else if (s1.length() > s2.length()) {
        return false;
    }
    else {
        for (int i=0; i<s1.length(); i++) {
            if (s1[i] < s2[i])
                return true;
            else if (s1[i] > s2[i])
                return false;
        }
    }
    return false;
}
vector <string> bigSorting(vector <string> arr) {
    sort(arr.begin(), arr.end(), compare);
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
