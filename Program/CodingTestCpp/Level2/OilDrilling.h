#pragma once
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
static class OilDrilling
{
public:
    
    
    void Question()
    {
        std::cout << "Level2, Question :1 OilDrilling" << std::endl;
        std::cout << "_" << std::endl;
        vector<vector<int>> land1 = {{0, 0, 0, 1, 1, 1, 0, 0},
                                         {0, 0, 0, 0, 1, 1, 0, 0},
                                         {1, 1, 0, 0, 0, 1, 1, 0},
                                         {1, 1, 1, 0, 0, 0, 0, 0},
                                         {1, 1, 1, 0, 0, 0, 1, 1}};

        vector<vector<int>> land2 = {{1, 0, 1, 0, 1, 1},
                                      {1, 0, 1, 0, 0, 0},
                                      {1, 0, 1, 0, 0, 1},
                                      {1, 0, 0, 1, 0, 0},
                                      {1, 0, 0, 1, 0, 1},
                                      {1, 0, 0, 0, 0, 0},
                                      {1, 1, 1, 1, 1, 1}};

        int result1 = solution(land1);
        int result2 = solution(land2);

        cout << "Result 1: " << result1 << endl;  // 예상 결과: 9
        cout << "Result 2: " << result2 << endl;  // 예상 결과: 16
    }
    
    int solution(vector<vector<int>> land) {
        
        int n = land.size();  // 세로 길이
        int m = land[0].size();  // 가로 길이
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        
        vector<vector<int>> visit(n, vector<int>(m, 0));
        
        unordered_map<int, int> totalOil;
        
        int oilIndex = 0;
        int maxOil = 0;  // 최대 석유 양
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                //새로운 석유매장 검색
                if (land[i][j] == 0 || visit[i][j] > 0)
                    continue;
        
                oilIndex++;
                int oilSize = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                visit[i][j] = oilIndex;

                
                while (!q.empty()) {
                    int curn = q.front().first;
                    int curm = q.front().second;
                    q.pop();
                    oilSize++;
                    
                    for (int k = 0; k < 4; ++k) {
                        int newn = curn + dr[k];
                        int newm = curm + dc[k];
                        
                        if (newn >= 0
                            && newn < n
                            && newm >= 0
                            && newm < m
                            && land[newn][newm] == 1
                            && visit[newn][newm] == 0)
                        {
                            q.push({newn, newm});
                            visit[newn][newm] = oilIndex;
                        }
                    }
                }
                totalOil.insert({oilIndex, oilSize});
            }
        }

        for (int j = 0; j < m; ++j)
        {
            unordered_map<int, int> tempOilVisit;
            int totalOilSize = 0;
            for (int i = 0; i < n; ++i)
            {
                int index = visit[i][j];
                if (index > 0 && tempOilVisit.find(index) == tempOilVisit.end())
                {
                    tempOilVisit.insert({index, 0});
                    totalOilSize += totalOil[index];
                }
            }
            maxOil = max(maxOil, totalOilSize);
        }
        
        return maxOil;
    }
};
