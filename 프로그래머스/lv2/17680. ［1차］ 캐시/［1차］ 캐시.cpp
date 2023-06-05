#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

class LRU {
	// 데이터를 저장할 list
	list<string> LRUList;

	// 참조를 저장할 map
	unordered_map<string, list<string>::iterator> LRUMap;

	// 최대 용량
	int LRUMaxSize; 
    int time = 0;
    
public:
	LRU(int);
	void refer(string);
	void display();
    int calc_time();
};

// 클래스가 생성될 때 크기를 선언함.
LRU::LRU(int n)
{
	LRUMaxSize = n;
}

// 요소 x를 참조하는 함수 refer
void LRU::refer(string x)
{
	// 캐시 내에 없을 경우
	if (LRUMap.find(x) == LRUMap.end()) {
		// 캐시가 꽉 찼을 경우
		if (LRUList.size() == LRUMaxSize) {
			string last = LRUList.back();

			// 리스트에서 가장 오래 사용되지 않은 요소 pop
			LRUList.pop_back();

			// 참조도 함께 삭제
			LRUMap.erase(last);
		}
        time += 5;
	}

	// 캐시 내에 있을 경우 해당 요소 삭제
	else {
        LRUList.erase(LRUMap[x]);
        time += 1;
    }
		
	// 새로운 요소 x를 맨 앞에 push, 참조도 update
	LRUList.push_front(x);
	LRUMap[x] = LRUList.begin();
}

int LRU::calc_time() 
{ 
    return time;
}
// 요소 x를 참조하는 함수 refer
void LRU::display()
{
	for (auto it = LRUList.begin(); it != LRUList.end(); it++) {
		cout << (*it) << " ";
	}

	cout << endl;
}

int cache_miss = 5;
int cache_hit = 1;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    LRU lru(cacheSize);
    if (cacheSize == 0) {
        return cities.size() * cache_miss;
    }
    
    for (int i=0; i < cities.size(); i++) {
        for (int j=0; j<cities[i].size(); j++) {
            cities[i][j] = tolower(cities[i][j]);
        }
        lru.refer(cities[i]);
    }

    return lru.calc_time();
}