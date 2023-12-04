#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/178870
//연속된 부분 수열의 합
static class SumConsecutive
{
public:
    
    
    void Question()
    {
        vector<int> sequence1 = {1, 2, 3, 4, 5};
        int k1 = 7;
        vector<int> result1 = solution(sequence1, k1);
        cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;

        vector<int> sequence2 = {1, 1, 1, 2, 3, 4, 5};
        int k2 = 5;
        vector<int> result2 = solution(sequence2, k2);
        cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;

        vector<int> sequence3 = {2, 2, 2, 2, 2};
        int k3 = 6;
        vector<int> result3 = solution(sequence3, k3);
        cout << "[" << result3[0] << ", " << result3[1] << "]" << endl;
    }    
    
    vector<int> solution(vector<int> sequence, int k) {
        int size = sequence.size();
        int maxSum = 0;
        int end = 0;
        int range = size;
        vector<int> answer(2);
        for (int i = 0; i < size; ++i)
        {
            while (maxSum < k && end < size)
            {
                maxSum += sequence[end];
                end++;
            }
            if (maxSum == k && end - 1 - i < range)
            {
                answer[0] = i;
                answer[1] = end-1;
                range = end - 1 - i;
            }
            maxSum -= sequence[i];
        }
        return answer;
    }
};
