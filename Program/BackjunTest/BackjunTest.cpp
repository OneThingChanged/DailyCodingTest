#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <string>
// #include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int x;
    cin>>x;
    int i = 1;
    while (x > i) {
        x -= i;
        i++;
    }

    if (i % 2 == 1) {
        cout << i + 1 - x << '/' << x << endl;
    }
    else {
        cout << x << '/' << i + 1 - x << endl;
    }
    cin>>x;
    return 0;
}

