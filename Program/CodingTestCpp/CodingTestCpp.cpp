
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
#include "Level2/ConvertNumber.h"
#include "Level2/DefenceGame.h"
#include "Level2/DesertIslandTrip.h"
#include "Level2/DoAssignment.h"
#include "Level2/FindLargeNumberFromBack.h"
#include "Level2/HotelManager.h"
#include "Level2/MagicElevator.h"
#include "Level2/MazeEscape.h"
#include "Level2/Minecraft.h"
#include "Level2/PreliminaryTranslation.h"
#include "Level2/RicochatRobot.h"
#include "Level2/SeesawPartner.h"
#include "Level2/SoloTicTacTok.h"
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

        // DoAssignment antiMissile;
        // antiMissile.Question();

        // Minecraft antiMissile;
        // antiMissile.Question();

        // RicochatRobot antiMissile;
        // antiMissile.Question();
        
        // SoloTicTacTok antiMissile;
        // antiMissile.Question();

        // MazeEscape antiMissile;
        // antiMissile.Question();

        // HotelManager antiMissile;
        // antiMissile.Question();

        // DesertIslandTrip antiMissile;
        // antiMissile.Question();

        // FindLargeNumberFromBack antiMissile;
        // antiMissile.Question();
        
        // ConvertNumber antiMissile;
        // antiMissile.Question();

        // SeesawPartner antiMissile;
        // antiMissile.Question();

        // MagicElevator antiMissile;
        // antiMissile.Question();

        DefenceGame antiMissile;
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

