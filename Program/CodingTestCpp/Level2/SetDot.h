#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <array>
#include <map>
#include <vector>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/140107
//점찍기
static class SetDot
{
public:
    void Question()
    {
        // int k1 = 2;
        // int d1 = 4;
        // int result1 = solution(k1, d1); 
        // cout << "Result: " << result1 << endl; //6

        int k2 = 1;
        int d2 = 5;
        int result2 = solution(k2, d2); 
        cout << "Result: " << result2 << endl; //26
    }    

    long long solution1(int k, int d) {
        long long answer = d/k + 1; //x축 위의 해당점들
        long long tempK = 1ll * d * d; //1ll은 long long 변환을 위해 곱해줌
        for (long long i = 0; i < d; i += k)
            answer += (long long)sqrt(tempK - i * i)/k;
        return answer;
    }

    long long solution(int k, int d) {
        long long answer = 0;
        int maxMultiply = d / k;
        long long maxVal = 1ll * d * d;
        long long tempK = 1ll * k * k;
        for (long long i = 0; i <= maxMultiply; ++i)
        {
            long long poweri = i*i;
            for (long long j = 0; j <= maxMultiply; ++j)
            {
                if (d < sqrt(tempK * poweri + tempK * j*j))
                    break;
                else
                    answer++;
            }
        }
        return answer;
    }
};
