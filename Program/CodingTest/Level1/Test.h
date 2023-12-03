#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input;
    cin >> input;
    // vector<int> real = {1, 1 ,2, 2,2, 8};
    input--;
    int count = input * 2;
    for (int i = 0; i < count; ++i)
    {
        int starCount = i % input;
        int spaceCount = input - starCount;
        //left Space
        for (int j = 0; j < spaceCount; ++j)
        {
            cout << '.';
        }

        //StarCount
        for (int j = 0; j < starCount; ++j)
        {
            cout << '*';
        }
    }
    return 0;
}

