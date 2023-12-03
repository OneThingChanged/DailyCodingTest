#pragma once
#include <iostream>
#include <vector>

class Templars_Weapon
{
public:
    static void Question()
    {
        std::cout << "문제 2: Templars_Weapon" << std::endl;
        std::cout << "_" << std::endl;
        std::cout << Answer(5, 3, 2) << std::endl;  // 10
        std::cout << Answer(10, 3, 2) << std::endl; // 21
    }
    static int Answer(int number, int limit, int power) {
        std::vector<int> divisorsCount(number + 1, 0);
    
        for(int i = 1; i <= number; i++) {
            for(int j = i; j <= number; j += i) {
                divisorsCount[j]++;
            }
        }
    
        int totalIron = 0;
        for(auto count : divisorsCount) {
            if(count > limit) {
                totalIron += power;
            } else {
                totalIron += count;
            }
        }
    
        return totalIron;
    }
};
