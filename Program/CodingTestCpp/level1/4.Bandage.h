#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Bandage
{
public:
    static void Question()
    {
        std::cout << "Question 4: Bandage" << std::endl;
        std::cout << "_" << std::endl;
        
        vector<int> bandage = {5, 1, 5};
        int health = 30;
        vector<vector<int>> attacks = {{2, 10}, {9, 15}, {10, 5}, {11, 5}};

        // 함수 호출
        int result = solution(bandage, health, attacks);

        // 결과 출력
        if (result != -1) {
            cout << "Remain Health: " << result << endl;
        } else {
            cout << "Character Death." << endl;
        }

        return;
    }
    static int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
        int answer = 0;
        
        int t = bandage[0]; //캐스팅 시간
        int x = bandage[1]; //초당 회복량
        int y = bandage[2]; //추가 회복량

        int charHealth = health;

        for (int i = 0; i < attacks.size(); ++i)
        {
            int damage = attacks[i][1];
            
            //첫번째 인덱스인지 체크
            if (i == 0)
            {
                charHealth -= damage;
                if (charHealth <= 0)
                {
                    return charHealth;
                }
                cout << "i: " << i << "\tdamage: " << damage << "\tcur Health: " << charHealth << endl;
                continue;
            }

            int prevAttackTime = attacks[i][0] - (attacks[i-1][0] + 1);
            int totalHeal = prevAttackTime * x + (prevAttackTime / t * y);
            
            charHealth += totalHeal;
            if (charHealth > health)
            {
                charHealth = health;
            }
            cout << "i: " << i << "\ttotalHeal: " << totalHeal << "\tprevAttackTime: " << prevAttackTime << "\tCur Heal: " << charHealth;
            
            //플레이어 체력이 0인지 체크
            charHealth -= damage;
            if (charHealth <= 0)
            {
                return -1;
            }

            cout << "\tdamage: " << damage << "\tcur Health: " << charHealth << endl;
        }

        return charHealth;
    }   

};
