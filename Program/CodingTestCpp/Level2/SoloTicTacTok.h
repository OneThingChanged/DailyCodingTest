#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/160585
//두 원 사이의 정수 쌍
static class SoloTicTacTok
{
public:
    bool CheckWinner(vector<string>& board, char player) {
        // 가로, 세로 확인
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true;  // 가로
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                return true;  // 세로
            }
        }
        
        //대각선 확인
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;  // 왼쪽 위에서 오른쪽 아래로 대각선
        }
    
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;  // 왼쪽 아래에서 오른쪽 위로 대각선
        }
    
        return false;
    }
    
    void Question()
    {
        vector<string> board1 = {"O.X", ".O.", "..X"};
        vector<string> board2 = {"OOO", "...", "XXX"};
        vector<string> board3 = {"...", ".X.", "..."};
        vector<string> board4 = {"...", "...", "..."};

        cout << solution(board1) << endl;  // 1
        cout << solution(board2) << endl;  // 0
        cout << solution(board3) << endl;  // 0
        cout << solution(board4) << endl;  // 1
    }    
    
    int solution(vector<string> board) {
        int countO = 0;
        int countX = 0;
        // "O"와 "X" 개수 세기
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'O') {
                    countO++;
                } else if (board[i][j] == 'X') {
                    countX++;
                }
            }
        }
        
        if (countO - countX < 0 || countO - countX > 1)
            return 0;

        bool XWinner = CheckWinner(board, 'X');
        bool OWinner = CheckWinner(board, 'O');

        if (OWinner && XWinner)
            return 0;

        if (OWinner && countO == countX)
            return 0;
        
        if (XWinner && countO > countX)
            return 0;
        
        return 1;
    }
};
