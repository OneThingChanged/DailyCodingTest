#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <vector>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/176962
//과제 진행하기
static class DoAssignment
{
public:
    
    
    void Question()
    {
        vector<vector<string>> tasks1 = {
            {"korean", "11:40", "30"},
            {"english", "12:10", "20"},
            {"math", "12:30", "40"}
        };
        vector<string> result1 = solution(tasks1);
        for (string task : result1) {
            cout << task << " ";
        }
        cout << endl;
        
        vector<vector<string>> tasks2 = {
            {"music", "12:20", "40"},
            {"computer", "12:30", "100"},
            {"science", "12:40", "50"},
            {"history", "14:00", "30"},
        };
        vector<string> result2 = solution(tasks2);
        for (string task : result2) {
            cout << task << " ";
        }
        cout << endl;
        
        ///bbb
        vector<vector<string>> tasks3 = {
            {"aaa", "12:00", "20"},
            {"bbb", "12:10", "30"},
            {"ccc", "12:40", "10"},
        };
        vector<string> result3 = solution(tasks3);
        for (string task : result3) {
            cout << task << " ";
        }
        cout << endl;
        
        vector<vector<string>> tasks4 = {
            {"A", "10:00", "30"},
            {"B", "10:20", "20"},
            {"C", "10:30", "10"}
        };
        vector<string> result4 = solution(tasks4);
        for (string task : result4) {
            cout << task << " ";
        }
        cout << endl;
    }

    // 과제 정보를 나타내는 구조체
    struct Task {
        string name;
        int start;
        int playtime;

        Task(string _name, int _start, int _playtime)
            : name(_name), start(_start), playtime(_playtime) {}
    };

    // 시각을 분 단위로 변환하는 함수
    int TimeToMinutes(string time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }

    // 비교 함수
    static bool compareTasks(const Task& a, const Task& b) {
        return a.start < b.start;
    }
    
    vector<string> solution(vector<vector<string>> plans) {
        vector<Task> tasks;
        vector<string> answer;
        stack<Task> stack;
        // 입력을 Task 구조체로 변환
        for (const vector<string>& plan : plans) {
            string name = plan[0];
            int start = TimeToMinutes(plan[1]);
            int playtime = stoi(plan[2]);
            tasks.emplace_back(name, start, playtime);
        }

        // 시작 시각 순으로 정렬
        sort(tasks.begin(), tasks.end(), compareTasks);

        int currentTime = 0;  // 현재 시각을 나타내는 변수
        for (int i = 0; i < tasks.size(); ++i)
        {
            while (!stack.empty() && currentTime + stack.top().playtime <= tasks[i].start)
            {
                currentTime += stack.top().playtime;
                answer.push_back(stack.top().name);
                stack.pop();
            }
            if (!stack.empty() && currentTime + stack.top().playtime > tasks[i].start)
            {
                stack.top().playtime -=  tasks[i].start - currentTime;
            }
            currentTime = tasks[i].start;
            stack.push(tasks[i]);
        }
        while (!stack.empty())
        {
            answer.push_back(stack.top().name);
            stack.pop();
        }
        return answer;
    }
};
