#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//접미사배열

static class SuffixArray
{
public:
    static void Answer()
    {
        std::string my_string = "Banana";
        std::vector<std::string> answer;
        for (int i = 0; i < my_string.length(); i++)
        {
            auto temp =  my_string.substr(i);
            answer.push_back(temp);
        }
   
        sort(answer.begin(), answer.end());

        for (int i = 0; i < my_string.length(); i++)
        {
            std::cout << my_string[i] << std::endl;
        }
    }
};
