//https://www.hackerrank.com/challenges/tutorial-intro/problem
#include <bits/stdc++.h>

using namespace std;

int introTutorial(int V, vector <int> arr) {
    for (int i=0; i<arr.size(); i++) {
        if (arr[i] == V)
            return i;
    }
    return -1;
        // Complete this function
}

int main() {
    int V;
    cin >> V;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
        cin >> arr[arr_i];
    }
    int result = introTutorial(V, arr);
    cout << result << endl;
    return 0;
}
