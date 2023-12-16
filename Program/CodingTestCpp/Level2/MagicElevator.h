#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
using Time = pair<int, int>;

//https://school.programmers.co.kr/learn/courses/30/lessons/148653
//마법의 엘리베이터
static class MagicElevator
{
public:
    void Question()
    {
        int storey1 = 16;
        int storey2 = 2554;
        int storey3 = 6554;
        int storey4 = 15;
        int storey5 = 95;
        int storey6 = 45;
        cout << solution(storey1) << endl; // 6
        cout << solution(storey2) << endl; // 16
        cout << solution(storey3) << endl; // 17
        cout << solution(storey4) << endl; // 6
        cout << solution(storey5) << endl; // 6
        cout << solution(storey6) << endl; // 9
    }

    int solution(int num)
    {
        if (num < 10)
            return min(num, 10 - num + 1);
        int a = num % 10;
        int b = 10 - num % 10;
        return min(solution((num - a) / 10) + a, solution((num + b) / 10) + b);
    }

    int solution1(int storey)
    {
        int answer = 0;
        vector<int> d;
        while (storey > 0)
        {
            int remainder = storey % 10;
            d.push_back(remainder);
            storey = storey / 10;
        }
        if (d[0] == 5 && d[1] >= 5)
            d[1] += 1;

        bool addOne = false;
        for (int i = 0; i < d.size(); ++i)
        {
            d[i] += addOne ? 1 : 0;
            if (d[i] > 5)
            {
                answer += 10 - d[i];
                addOne = true;
            }
            else
            {
                answer += d[i];
                addOne = false;
            }
        }
        answer += addOne ? 1 : 0;
        return answer;
    }

    int solution2(int storey)
    {
        int answer = 0;
        int temp;

        while(storey > 0){    
            temp = storey % 10;
            storey = storey / 10;
            if(temp > 5 || (temp == 5 && storey % 10 >= 5)){
                answer += 10 - temp;
                storey++;
            }else{
                answer += temp;
            }
        }

        return answer;
    }
};
