#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include <array>
#include <map>
#include <vector>
using namespace std;
using Pair = pair<int, int>;

//https://school.programmers.co.kr/learn/courses/30/lessons/152996
//호텔 대실
static class SeesawPartner
{
public:
    void Question()
    {
        vector<int> weights = {100, 180, 360, 100, 270}; //4
        int result = solution(weights); 
        cout << "Result: " << result << endl;
        
        vector<int> weights2 = {100, 180, 360, 100, 270, 200}; //6
        int result2 = solution(weights2);
        cout << "Result: " << result2 << endl;
        
        vector<int> weights1 = {100, 180, 360, 100, 270, 100, 200}; //9
        int result1 = solution(weights1);
        cout << "Result: " << result1 << endl;
        
        vector<int> weights3 = {100, 200, 400}; //2
        int result3 = solution(weights3);
        cout << "Result: " << result3 << endl;

        vector<int> weights4 = {100, 100, 100, 150, 150, 200, 300}; //18
        int result4 = solution(weights4);
        cout << "Result: " << result4 << endl;
    }    

    long long solution1(vector<int> weights) {
        long long answer = 0;
        sort(weights.begin(), weights.end());
        map<double, long long> m;
        double dx[] {1.0, 2.0, 1.0, 3.0};
        double dy[] {1.0, 3.0, 2.0, 4.0};
        for (auto i : weights){
            for (int j = 0; j < 4; ++j)
            {
                double temp = (i * dx[j]) / dy[j];
                if (m.find(temp) != m.end())
                    answer += m[temp]; 
            }                
            m[(i*1.0)] = m[(i*1.0)] + 1;
        }
        return answer;
    }

    long long solution(vector<int> weights) {
        long long answer = 0;
        vector<int> allWeights(4001, 0);
        vector<int> realWeights(1001, 0);
        for(int i = 0; i < weights.size();i++){
            for(int j = 2; j < 5; j++){
                answer += allWeights[weights[i] * j];
                allWeights[weights[i] * j]++;
            }
            answer -= realWeights[weights[i]] * 2;
            realWeights[weights[i]]++;
        }
        return answer;
    }
};
