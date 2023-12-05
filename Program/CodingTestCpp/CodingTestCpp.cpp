
#include <iostream>
#include <string>

#include "level1/1.SuffixArray.h"
#include "level1/2.Templars_Weapon.h"
#include "level1/3.Running_Race.h"
#include "level1/4.Bandage.h"
#include "level1/5.NumericStrings.h"
#include "Level2/AIOven.h"
#include "Level2/Clock.h"
#include "Level2/OilDrilling.h"
#include "Level2/AntiMissileSystem.h"
#include "Level2/DoAssignment.h"
#include "Level2/PreliminaryTranslation.h"
#include "Level2/SumConsecutive.h"

class MainClass
{
    int Level = 2;

public:
    void Run()
    {
        switch (Level)
        {
        case 2:
            Level2();
            break;
        }
        // AIOven quest;
        // quest.Question();
    }

    void Level1()
    {
        // SuffixArray::Answer();
        // Templars_Weapon::Question();
        // Running_Race::Question();
        // Bandage::Question();
        // Clock quest;
        // quest.Question();
    }

    void Level2()
    {
        // AntiMissileSystem antiMissile;
        // antiMissile.Question();

        // PreliminaryTranslation antiMissile;
        // antiMissile.Question();
        //
        // SumConsecutive antiMissile;
        // antiMissile.Question();

        DoAssignment antiMissile;
        antiMissile.Question();
    }
};
int main(int argc, char* argv[])
{
    MainClass main; 
    main.Run();

    // 사용자 입력을 기다립니다.
    std::cout << "Please Click enter to close program" << std::endl;
    std::cin.get();

    return 0;
}

