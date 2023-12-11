#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
using Time = pair<int, int>;

//https://school.programmers.co.kr/learn/courses/30/lessons/154540
//무인도 여행
static class DesertIslandTrip
{
public:
    
    
    void Question()
    {
        vector<string> maps1 = {"X591X","X1X5X","X231X", "1XXX1"};
        vector<string> maps2 = {"XXX","XXX","XXX"};

        vector<int> result1 = solution(maps1);
        for (int days : result1) {
            cout << days << " ";
        }
        cout << endl; //1 1 27

        vector<int> result2 = solution(maps2);
        for (int days : result2) {
            cout << days << " ";
        }
        cout << endl; //0
    }


    int BFS(vector<string> maps, vector<vector<bool>>& visited, int y, int x)
    {
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        q.emplace(x, y);
        visited[x][y] = true;
        int countDay = 0;
        while (!q.empty())
        {
            pair<int, int> temp = q.front();
            q.pop();
            countDay += maps[temp.second][temp.first] - '0';
            for (int index = 0; index < 4; ++index)
            {
                int nx = temp.first + dr[index];
                int ny = temp.second + dc[index];
                if (ny >= maps.size() || ny < 0 || nx >= maps[ny].size() || nx < 0) 
                    continue;
                if (visited[nx][ny] || maps[ny][nx] == 'X')
                    continue;
                
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
        return countDay;
    }

    vector<int> solution(vector<string> maps) {
        vector<int> answer;
        vector<vector<bool>> visited(maps[0].size(), vector<bool>( maps.size(), false));
        for (int y = 0; y < maps.size(); ++y)
        {
            for (int x = 0; x < maps[y].size(); ++x)
            {
               
                //바다임
                if (maps[y][x] == 'X' || visited[x][y])
                    continue;
                
                answer.push_back(BFS(maps, visited, y, x));
            }
        }
        if (answer.empty())
            answer.push_back(-1);
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
