#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
using Time = pair<int, int>;

//https://school.programmers.co.kr/learn/courses/30/lessons/155651
//호텔 대실
static class HotelManager
{
public:
    
    
    void Question()
    {
        vector<vector<string>> bookings1 = {{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}};
        vector<vector<string>> bookings2 = {{"09:10", "10:10"}, {"10:20", "12:20"}};
        vector<vector<string>> bookings3 = {{"10:20", "12:30"}, {"10:20", "12:30"}, {"10:20", "12:30"}};

        cout << solution(bookings1) << endl;  // 출력: 3
        cout << solution(bookings2) << endl;  // 출력: 1
        cout << solution(bookings3) << endl;  // 출력: 3
    }    
    int TimeToMinutes(string time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }

    // 비교 함수
    static bool CompareTasks(const Time& a, const Time& b) {
        return a.first < b.first;
    }
    
    int solution2(vector<vector<string>> book_time) {
        int answer = 0;
        vector<Time> time;
        for (int i = 0; i < book_time.size(); ++i)
        {
            Time temp;
            temp.first = TimeToMinutes(book_time[i][0]);
            temp.second = TimeToMinutes(book_time[i][1])+ 10;
            time.push_back(temp);
        }

        sort(time.begin(), time.end(), CompareTasks);
        int curTime;
        vector<int> room;
        for (int i = 0; i < time.size(); ++i)
        {
            bool hasRoom = false;
            int minTime = numeric_limits<int>::max();
            int roomIndex = -1;
            for (int r = 0; r < room.size(); ++r)
            {
                if (room[r] <= time[i].first && minTime > room[r] - time[i].first)
                {
                    minTime = room[r] - time[i].first;
                    hasRoom = true;
                    roomIndex = r;
                }
            }
            if (hasRoom)
            {
                room[roomIndex] = time[i].second;
           
            }
            else
            {
                room.push_back(time[i].second);
                answer++;
            }
        }
        
        return answer;
    }

    int solution(vector<vector<string>> book_time) {
        int answer = 0;
        vector<pair<int, int>> time;
        for (int i = 0; i < book_time.size(); ++i)
        {
            Time temp;
            time.emplace_back(TimeToMinutes(book_time[i][0]), 1);
            time.emplace_back(TimeToMinutes(book_time[i][1]) + 10, -1);
        }
        sort(time.begin(),time.end());
        int cur = 0;
        for (int i = 0; i < time.size(); ++i)
        {
            cur += time[i].second;
            answer = max(answer, cur); 
        }
        
        return answer;
    }
};
