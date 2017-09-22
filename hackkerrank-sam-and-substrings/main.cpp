//https://www.hackerrank.com/challenges/sam-and-substrings?h_r=next-challenge&h_v=zen

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std;

string input;
int length;

long long int totalSum(void) {
    int MOD = pow(10, 9) +7;
    long long int sum = 0;
    long long int multiply = 1;
    for (int i=length-1; i>=0; i--) {
        sum = (sum + (input[i]-'0')*(i+1)*multiply) %MOD;
        multiply = (multiply*10 +1) % MOD;
    }

    return sum ;
}

int main(void) {
    cin >> input;
    //reverse(input.begin(), input.end());
    length = input.size();
    printf("%lld", totalSum());

    return 0;
}
