#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/159993
//미로 탈출
static class MazeEscape
{
public:
    
    void Question()
    {
        vector<string> maps1 = {"SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"};
        cout << "Test Case 1: " << solution(maps1) << endl; // 예시: 16

        vector<string> maps2 = {"LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"};
        cout << "Test Case 2: " << solution(maps2) << endl; // 예시: -1

        vector<string> maps3 = {"SOEOL","XXXXO","OOOOO","OXXXX","OOOOO"};
        cout << "Test Case 3: " << solution(maps3) << endl; // 예상 결과: 6

        vector<string> maps4 = {"SLEOX", "XXXXO", "OOOOO", "OXXXX", "OOOOO"};
        cout << "Test Case 4: " << solution(maps4) << endl; // 예상 결과: 2

        vector<string> maps5 = {"SELOX", "XXXXO", "OOOOO", "OXXXX", "OOOOO"};
        cout << "Test Case 5: " << solution(maps5) << endl; // 예상 결과: 3

        vector<string> maps6 = {"SLXOX", "EXXXO", "OOOOO", "OXXXX", "OOOOO"};
        cout << "Test Case 6: " << solution(maps6) << endl; // 예상 결과: 3

        vector<string> maps7 = {"SXXOX", "EXXXL", "OOXOO", "OXXXX", "OOOOO"};
        cout << "Test Case 7: " << solution(maps7) << endl; // 예상 결과: -1
    }
    struct Pos
    {
        int x;
        int y;
        int curTime;
    };
    bool FindRoot(vector<string> maps, Pos Start, Pos End, int dr[], int dc[], int& value)
    {
        queue<Pos> s;
        Start.curTime = value;
        s.push(Start);
        Pos Goal = End;
        int mapSizeY = maps.size();
        int mapSizeX = maps[mapSizeY - 1].size();
        vector<vector<bool>> visited(mapSizeY, vector<bool>(mapSizeX, false));
        while (!s.empty())
        {
            Pos curPos = s.front();
            s.pop();

            if (curPos.x == Goal.x && curPos.y == Goal.y)
            {
                value = curPos.curTime;
                return true;
            }
            for (int i = 0; i < 4; ++i)
            {
                int nx = curPos.x + dr[i];
                int ny = curPos.y + dc[i];
                if (!(ny < maps.size() && nx < maps[ny].size() && maps[ny][nx] != 'X' && !visited[ny][nx]))
                {
                    continue;
                }
            
                Pos newPos;
                newPos.x = nx;
                newPos.y = ny;
                visited[ny][nx] = true;
                newPos.curTime = curPos.curTime + 1;
                s.push(newPos);
            }
        }
        return false;
    }
    int solution(vector<string> maps) {
        int answer = 0;
        Pos Lever;
        Pos Start;
        Pos End;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for (int i = 0; i < maps.size(); ++i)
        {
            for (int j = 0; j < maps[i].size(); ++j)
            {
                if (maps[i][j] == 'L')
                {
                    Lever.x = j;
                    Lever.y = i;
                    Lever.curTime = 0;
                }
                if (maps[i][j] == 'E')
                {
                    End.x = j;
                    End.y = i;
                    End.curTime = 0;
                }
                if (maps[i][j] == 'S')
                {
                    Start.x = j;
                    Start.y = i;
                    Start.curTime = 0;
                }
            }
        }
    
        if (!FindRoot(maps, Start, Lever, dr, dc, answer))
            return -1;
        if (!FindRoot(maps, Lever, End, dr, dc, answer))
            return -1;
        return answer;
    }
};
