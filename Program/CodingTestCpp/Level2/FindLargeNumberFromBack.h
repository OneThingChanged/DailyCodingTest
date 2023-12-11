#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <vector>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/154539
//뒤에 있는 큰 수 찾기

static class FindLargeNumberFromBack
{
public:
    
    
    void Question()
    {
        vector<int> numbers1 = {2, 3, 3, 5}; // [3, 5, 5, -1]
        vector<int> numbers2 = {9, 1, 5, 3, 6, 2}; //[-1, 5, 6, 6, -1, -1]

        vector<int> result1 = solution(numbers1);
        vector<int> result2 = solution(numbers2);

        cout << "Result 1: ";
        for (int num : result1) {
            cout << num << " ";
        }
        cout << endl;

        cout << "Result 2: ";
        for (int num : result2) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    vector<int> solution1(vector<int> numbers) {
        vector<int> answer(numbers.size(), -1);
        for (int i = 1; i < numbers.size(); ++i)
            for (int j = i + 1; j < numbers.size(); ++j)
                if (numbers[i] < numbers[j])
                {
                    answer[i] = numbers[j];
                    break;
                }
        return answer;
    }

    vector<int> solution(vector<int> numbers) {
        vector<int> answer(numbers.size(), -1);
        stack<int> s;
        s.push(0);
        for (int i = 1; i < numbers.size(); ++i)
        {
            while (!s.empty() && numbers[s.top()] < numbers[i])
            {
                answer[s.top()] = numbers[i];
                s.pop();
            }
            s.push(i);
        }
            
        return answer;
    }
};
