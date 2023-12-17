#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/142085
//디펜스 게임
static class DefenceGame
{
public:
    
    
    void Question()
    {
        int n1 = 7;
        int k1 = 3;
        vector<int> enemy1 = {4, 2, 4, 5, 3, 3, 1}; //5

        int n3 = 7;
        int k3 = 3;
        vector<int> enemy3 = {4, 2, 4, 5, 3, 2}; //5

        int n2 = 2;
        int k2 = 4;
        vector<int> enemy2 = {3, 3, 3, 3};

        cout << solution(n1, k1, enemy1) << endl;  // 5
        cout << solution(n2, k2, enemy2) << endl;  // 4
        cout << solution(n3, k3, enemy3) << endl;  // 5
    }
    
    
    int solution(int n, int k, vector<int> enemy) {
        int answer = 0;
        priority_queue<int, vector<int>, greater<>> pq;

        if (k >= enemy.size())
            return enemy.size();
        
        for (answer = 0; answer < enemy.size(); ++answer)
        {
            pq.push(enemy[answer]);
            if (pq.size() <= k)
                continue;
            
            n -= pq.top();
            pq.pop();
            if (n < 0)
                break;
        }
        return answer;
    }
};
