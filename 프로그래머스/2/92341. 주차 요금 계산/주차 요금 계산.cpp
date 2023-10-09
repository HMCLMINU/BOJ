#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> m_for_record;
    map<string, int> m_for_calc_time;
    int max_time = 23*60 + 59;
    double base_time = fees[0];
    double base_fee = fees[1];
    double unit_time = fees[2];
    double unit_fee = fees[3];
    double total_fee;
    
    for (auto i : records) {
        int time = stoi(i.substr(0, 2))*60 + stoi(i.substr(3, 2));
        string v_num = i.substr(6, 4);
        string in_or_out = i.substr(11);
        
        if (in_or_out == "IN") {
            // 입차 시간 기록
            m_for_record[v_num] = time; 
            if (time == 0) m_for_record[v_num] = -1; // 00:00에 들어온 경우 특수 케이스
        }
        else {
            // OUT 인 경우 총 시간 계산 및 m_for_record 초기화
            m_for_calc_time[v_num] += (time - m_for_record[v_num]);
            m_for_record[v_num] = 0; // 출차
        }
    }
    // 출차 하지 않은 차량 총 시간 계산
    for (auto i : m_for_record) {
        if (i.second || i.second == -1) {
            // 출차 하지 않은 경우 또는 특수 케이스는 23:59로 출차
            if (i.second == -1)
                m_for_calc_time[i.first] += max_time;
            else 
                m_for_calc_time[i.first] += (max_time - i.second);
        }
    }
    // 요금 계산
    for (auto i : m_for_calc_time) {
        // 기본 시간 이하
        if (i.second <= base_time) {
            answer.push_back(base_fee); // 기본 요금
        }
        else {
            total_fee = base_fee + ceil((i.second - base_time) / unit_time) * unit_fee;
            answer.push_back(total_fee);
        }
    }
    
    return answer;
}