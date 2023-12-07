#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/178870
//리코쳇 로봇
class RicochatRobot
{
public:

    struct Pos
    {
        int x = 0;
        int y = 0;
        int dist = 0;
    };
    void Question()
    {
        vector<string> board1 = {"...D..R", ".D.G...", "....D.D", "D....D.", "..D...."};
        cout << solution(board1) << endl; // Output: 7

        vector<string> board2 = {".D.R", "....", ".G..", "...D"};
        cout << solution(board2) << endl; // Output: -1
    }    
    
    // board_len은 배열 board의 길이입니다.
    // 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
    int solution(vector<string> board) {
        int n = board.size();
        int m = board[0].size();

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        Pos startPos;
        Pos endPos;
        bool isFoundStartPos = false;
        bool isFoundEndPos = false;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'R') {
                    startPos.x = i;
                    startPos.y = j;
                    isFoundStartPos = true;
                } else if (board[i][j] == 'G') {
                    endPos.x = i;
                    endPos.y = j;
                    isFoundEndPos = true;
                }

                if (isFoundEndPos && isFoundStartPos)
                {
                    break;
                }
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<Pos> q;
        q.push(startPos);
        while (!q.empty())
        {
            Pos cur = q.front();
            q.pop();
            if (cur.x == endPos.x && cur.y == endPos.y)
                return cur.dist;
            for (int i = 0; i < 4; ++i) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                while (AbleToMove(nx + dx[i], ny + dy[i], board))
                {
                    nx = nx + dx[i];
                    ny = ny + dy[i];
                }
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && board[nx][ny] != 'D') {
                    visited[nx][ny] = true;
                    q.push({nx, ny, cur.dist + 1});
                }
            }

            
        }
        return -1;
    }

    bool AbleToMove(int x, int y, vector<string>& board)
    {
        return x < board.size() && y < board[x].size() && board[x][y] != 'D';  
    }
};
