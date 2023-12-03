#pragma once
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

static class AIOven
{
public:
    static void Question()
    {
        // ios::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int input;
        cin >> input;
        // vector<int> real = {1, 1 ,2, 2,2, 8};
        input--;
        int count = input;
        for (int i = 0; i < count; ++i)
        {
            int starCount = i % input;
            int spaceCount = input - starCount;
            //left Space
            for (int j = 0; j < spaceCount; ++j)
            {
                cout << " ";
            }
            starCount = starCount*2 + 1;
            //StarCount
            for (int j = 0; j < starCount; ++j)
            {
                cout << "*";
            }
            cout << "\n";
        }

        for (int j = 0; j < input * 2 + 1; ++j)
        {
            cout << "*";
        }
        cout << "\n";
        for (int i = count - 1; i >= 0; --i)
        {
            int starCount = i % input;
            int spaceCount = input - starCount;
            //left Space
            for (int j = 0; j < spaceCount; ++j)
            {
                cout << " ";
            }
            starCount = starCount*2 + 1;
            //StarCount
            for (int j = 0; j < starCount; ++j)
            {
                cout << "*";
            }
            cout << "\n";
        }
        int asd;
        cin >> asd;
    }
};
