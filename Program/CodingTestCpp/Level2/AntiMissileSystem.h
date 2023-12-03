#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/181188
static class AntiMissileSystem
{
public:
    
    
    void Question()
    {
        vector<vector<int>> targets = {{4, 5}, {4, 8}, {10, 14}, {11, 13}, {5, 12}, {3, 7}, {1, 4}};
        int result2 = solution(targets);
        cout << result2 << "," << endl;
    }
    
int solution(vector<vector<int>> targets) {
    int answer = 0;

    //시작점 s를 기준으로 정렬
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    int size = targets.size();
    int max_e = -1;
    for (int i = 0; i < size; ++i)
    {
        int cur_s = targets[i][0];
        int cur_e = targets[i][1];

        if (cur_s >= max_e)
        {
            max_e = cur_e;
            answer++;
        }
    }
    
    return answer;
}
};
