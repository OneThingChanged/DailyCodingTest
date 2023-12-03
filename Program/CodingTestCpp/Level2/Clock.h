#pragma once
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

static class Clock
{
public:
    void Question()
    {
        std::cout << "Level2, Question :1 OilDrilling" << std::endl;
        std::cout << "_" << std::endl;

        // 예제 1
        int h1 = 0, m1 = 5, s1 = 30, h2 = 0, m2 = 7, s2 = 0;
        int result1 = solution(h1, m1, s1, h2, m2, s2);
        cout << "Result 1: " << result1 << endl; // 예상 결과: 2

        // 예제 2
        h1 = 12, m1 = 0, s1 = 0, h2 = 12, m2 = 0, s2 = 30;
        int result2 = solution(h1, m1, s1, h2, m2, s2);
        cout << "Result 2: " << result2 << endl; // 예상 결과: 1
        
        // 예제 3
        h1 = 0, m1 = 6, s1 = 1, h2 = 0, m2 = 6, s2 = 6;
        int result3 = solution(h1, m1, s1, h2, m2, s2);
        cout << "Result 3: " << result3 << endl; // 예상 결과: 0
        
        // 예제 4
        h1 = 11, m1 = 59, s1 = 30, h2 = 12, m2 = 0, s2 = 0;
        int result4 = solution(h1, m1, s1, h2, m2, s2);
        cout << "Result 4: " << result4 << endl; // 예상 결과: 1
        
        // 예제 5
        h1 = 11, m1 = 58, s1 = 59, h2 = 11, m2 = 59, s2 = 0;
        int result5 = solution(h1, m1, s1, h2, m2, s2);
        cout << "Result 5: " << result5 << endl; // 예상 결과: 1
        
        // 예제 6
        h1 = 1, m1 = 5, s1 = 5, h2 = 1, m2 = 5, s2 = 6;
        int result6 = solution(h1, m1, s1, h2, m2, s2);
        cout << "Result 6: " << result6 << endl; // 예상 결과: 2
        
        // // 예제 7
        // h1 = 0, m1 = 0, s1 = 0, h2 = 23, m2 = 59, s2 = 59;
        // int result7 = solution(h1, m1, s1, h2, m2, s2);
        // cout << "Result 7: " << result7 << endl; // 예상 결과: 2852
    }

    bool areAnglesEqual(double prevSecAngle, double angle1, double angle2)
    {
        if (angle1 == 0 )
        {
            angle1 = 360;
        }
        return prevSecAngle <= angle2 && angle2 <= angle1;
    }

    int solution(int h1, int m1, int s1, int h2, int m2, int s2)
    {
        int alarmCount = 0;

        int h = h1;
        int m = m1;
        int s = s1;

        while (!(h == h2 && m == m2 && s == s2))
        {
            int prevSec = s;
            s++;
            if (s == 60)
            {
                s = 0;
                m++;
            }

            if (m == 60)
            {
                m = 0;
                h++;
            }

            // 초침, 분침, 시침의 각도 계산
            double prevSecondAngle = prevSec * 360.0 / 60;
            double secondAngle = s  * 360.0 / 60;
            double minuteAngle = (m * 60 + s) * 360.0 / 3600;
            double hourAngle = (h % 12 * 3600 + m * 60 + s) * 360.0 / 43200;

            if (m == 0 && s == 0 && h == 12)
            {
                alarmCount++;
                continue;
            }
            
            // cout << h << ":" <<  m << ":" << s << ": " << secondAngle << "|" << minuteAngle << "|" << hourAngle << endl; // 예상 결과: 2852
            // 초침과 분침이 겹치거나 초침과 시침이 겹칠 때 알람 울림
            if (areAnglesEqual(prevSecondAngle, secondAngle, minuteAngle))
            {
                alarmCount++;
            }

            if (areAnglesEqual(prevSecondAngle, secondAngle, hourAngle))
            {
                alarmCount++;
            }
        }

        if (m == 0 && s == 0)
        {
            alarmCount++;
        }

        return alarmCount;
    }
};
