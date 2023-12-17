#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#include <queue>
#include <vector>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/138476
//귤 고르기
static class ChooseOrange
{
public:
    
    
    void Question()
    {
        int k1 = 6;
        vector<int> tangerine1 = {1, 3, 2, 5, 4, 5, 2, 3};

        int k2 = 4;
        vector<int> tangerine2 = {1, 3, 2, 5, 4, 5, 2, 3};

        int k3 = 2;
        vector<int> tangerine3 = {1, 1, 1, 1, 2, 2, 2, 3};

        cout << solution(k1, tangerine1) << endl;  // 3
        cout << solution(k2, tangerine2) << endl;  // 2
        cout << solution(k3, tangerine3) << endl;  // 1
    }
    
    int solution(int k, vector<int> tangerine) {
        int answer = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < tangerine.size(); ++i)
            m[tangerine[i]]++;
        
        vector<pair<int,int>> vec( m.begin(), m.end() );
        sort(vec.begin(), vec.end(),
            [](const pair<int,int>& a, const pair<int,int>& b){
            return a.second > b.second;
        });
 
        for (int i = 0; i < vec.size(); ++i)
        {
            if (k <= 0)
                break;
            k -= vec[i].second;
            answer++;
        }
        return answer;
    }
};
