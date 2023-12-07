#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/172927
//광물 캐기
static class Minecraft
{
public:
    
    
    void Question()
    {
        vector<int> picks1 = {1, 3, 2};
        vector<string> minerals1 = {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"};
        cout << solution(picks1, minerals1) << endl;  // Output: 12
        
        vector<int> picks2 = {0, 1, 1};
        vector<string> minerals2 = {"diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"};
        cout << solution(picks2, minerals2) << endl;  // Output: 50

        vector<int> picks3 = {0, 0, 1};
        vector<string> minerals3 = {"stone", "stone", "stone", "stone", "stone", "diamond"};
        cout << solution(picks3, minerals3) << endl;  // Output: 5
    }

    static bool Compare(const vector<int>& a, const vector<int>& b) {
        return a[3] > b[3];
    }

    static bool InverseCompare(const vector<int>& a, const vector<int>& b) {
        return a[3] < b[3];
    }
    
    int solution(vector<int> picks, vector<string> minerals) {
        int answer = 0;
        vector<vector<int>> list;
        vector<int> size(4);
        int count = 0;
        int pickCount = picks[0] + picks[1] + picks[2];
        int mineralsSize = minerals.size() > pickCount * 5 ? pickCount * 5 : minerals.size();
        for (int i = 0; i < mineralsSize; ++i)
        {
            int val;
            if (minerals[i] == "diamond")
                val = 0;
            else if (minerals[i] == "iron")
                val = 1;
            else
                val = 2;
            size[val]++;
            count++;
            if (count == 5)
            {
                size[3] = size[0] * 25 + size[1] * 5 + size[2];
                list.push_back(size);
                size = vector<int>(4);
                count = 0;
            }
        
            if (i == mineralsSize - 1)
            {
                size[3] = size[0] * 25 + size[1] * 5 + size[2];
                list.push_back(size);
            }
        }
        // 비교 함수를 사용하여 list 벡터를 정렬
        sort(list.begin(), list.end(), Compare);
        
        for (int i = 0; i < list.size(); ++i)
        {
            if (picks[0] > 0)
            {
                answer += list[i][0] + list[i][1] + list[i][2];
                picks[0]--;
            }else if (picks[1] > 0)
            {
                answer += list[i][0] * 5 + list[i][1] + list[i][2];
                picks[1]--;
            }
            else if (picks[2] > 0)
            {
                answer += list[i][0] * 25 + list[i][1] * 5 + list[i][2];
                picks[2]--;
            }
            else
            {
                break;
            }
        }
        return answer;
    }
};


static bool Compare(const vector<int>& a, const vector<int>& b) {
    return a[3] > b[3];
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<vector<int>> list;
    vector<int> size(4);
    int count = 0;
    int pickCount = picks[0] + picks[1] + picks[2];
    int mineralsSize = minerals.size() > pickCount * 5 ? pickCount * 5 : minerals.size();
    for (int i = 0; i < mineralsSize; ++i)
    {
        int val;
        if (minerals[i] == "diamond")
            val = 0;
        else if (minerals[i] == "iron")
            val = 1;
        else
            val = 2;
        size[val]++;
        count++;
        if (count == 5)
        {
            size[3] = size[0] * 25 + size[1] * 5 + size[2];
            list.push_back(size);
            size = vector<int>(4);
            count = 0;
        }
        
        if (i == mineralsSize - 1)
        {
            size[3] = size[0] * 25 + size[1] * 5 + size[2];
            list.push_back(size);
        }
    }
    // 비교 함수를 사용하여 list 벡터를 정렬
    sort(list.begin(), list.end(), Compare);
        
    for (int i = 0; i < list.size(); ++i)
    {
        if (picks[0] > 0)
        {
            answer += list[i][0] + list[i][1] + list[i][2];
            picks[0]--;
        }else if (picks[1] > 0)
        {
            answer += list[i][0] * 5 + list[i][1] + list[i][2];
            picks[1]--;
        }
        else if (picks[2] > 0)
        {
            answer += list[i][0] * 25 + list[i][1] * 5 + list[i][2];
            picks[2]--;
        }
        else
        {
            break;
        }
    }
    return answer;
}