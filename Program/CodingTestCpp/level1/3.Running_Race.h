#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Running_Race
{
public:
    static void Question()
    {
        std::cout << "문제 3: Running_Race" << std::endl;
        std::cout << "_" << std::endl;

        const vector<string> players = {"mumu", "soe", "poe", "kai", "mine"};
        const vector<string> callings = {"kai", "kai", "mine", "mine"};

        const vector<string> result = solution(players, callings);
    
        cout << "Result:" << endl;
        for (const string& player : result) {
            cout << player << endl;
        }
    }

    static  vector<string> solution(vector<string> players, vector<string> callings)
    {
        // 선수의 이름과 위치(인덱스)를 저장하는 맵 초기화
        unordered_map<string, int> nameToIndex;
        for (int i = 0; i < players.size(); i++) {
            nameToIndex[players[i]] = i;
        }

        // 각 calling(추월하는 선수의 이름)을 순회
        for (const string& calling : callings) {
            int idx = nameToIndex[calling];

            // 해당 선수와 그 선수 앞의 선수의 위치를 바꿈
            swap(players[idx], players[idx - 1]);

            // 맵 업데이트
            nameToIndex[players[idx]] = idx;
            nameToIndex[players[idx - 1]] = idx - 1;
        }

        return players;
    }
};
