#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
using Time = pair<int, int>;

//https://school.programmers.co.kr/learn/courses/30/lessons/154540
//숫자변환하기
static class ConvertNumber
{
public:
    
    
    void Question()
    {
        int x1 = 10, y1 = 40, n1 = 5;
        int x2 = 10, y2 = 40, n2 = 30;
        int x3 = 2, y3 = 5, n3 = 4;

        int result1 = solution(x1, y1, n1);
        int result2 = solution(x2, y2, n2);
        int result3 = solution(x3, y3, n3);

        cout << "Result 1: " << result1 << endl; // 출력: 2
        cout << "Result 2: " << result2 << endl; // 출력: 1
        cout << "Result 3: " << result3 << endl; // 출력: -1
    }


    int solution(int x, int y, int n) {
        queue<pair<int, int>> q;
        q.emplace(y, 0);
        while (!q.empty())
        {
            pair<int,int> temp = q.front();
            q.pop();
            
            if (temp.first == x)
                return temp.second;
            
            if (temp.first % 2 == 0 && temp.first / 2 >= x)
                q.emplace(temp.first / 2, temp.second + 1);
            if (temp.first % 3 == 0 && temp.first / 3 >= x)
                q.emplace(temp.first / 3, temp.second + 1);
            if (temp.first - n >= x)
                q.emplace(temp.first - n, temp.second + 1);
        }
        return -1;
    }
};
