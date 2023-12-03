#pragma once
#include <iostream>
#include <vector>
using namespace std;

class NumericStrings
{
public:
    void Question()
    {
        cout << solution("one4seveneight") << endl; // 1478
        cout << solution("23four5six7") << endl; // 234567
        cout << solution("2three45sixseven") << endl; // 234567
        cout << solution("123") << endl; // 123

        return;
    }

    int solution(string input)
    {
        const string numbers[] =
        {
            "zero",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine"
        };
        string current_number;
        int result = 0;

        for (char tempChar : input)
        {
            if (isdigit(tempChar))
            {
                result = result




                * 10 + (tempChar - '0');
            }
            else
            {
                current_number += tempChar;
                for (int i = 0; i < 10; i++)
                {
                    if (current_number == numbers[i])
                    {
                        result = result * 10 + i;
                        current_number = ""; // 현재 영단어 초기화
                        break;
                    }
                }
            }
        }

        return result;
    }
};
