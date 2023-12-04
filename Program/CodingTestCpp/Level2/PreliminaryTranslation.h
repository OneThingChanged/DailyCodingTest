#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/181187
//두 원 사이의 정수 쌍
static class PreliminaryTranslation
{
public:
    
    
    void Question()
    {
        int result2 = solution(2,3);
        cout << result2 << "," << endl;
    }    
    
    long long solution(int r1, int r2) {
        long long answer = 0;

        for (int i = 1; i <= r2; ++i)
        {
            int radius2 = floor(sqrt(pow(r2,2) - pow(i,2)));        
            int radius1;
            if (i < r1)
                radius1 = ceil(sqrt(pow(r1,2) - pow(i,2)));
            else
                radius1 = 0;
            answer += radius2 - radius1 + 1;        
        }
        return answer * 4;
    }
};
