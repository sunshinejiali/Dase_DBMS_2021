#pragma once
#include "global.h"
#include<queue>
#include<string>
#include<unordered_map>
#include<mutex>
#include<vector>

#include"data_occ.h"
#include"data.h"
using namespace std;

class Engine {
public:
	Engine();
	Engine(cc_type type);
	// hash_map 存储数据
	std::unordered_map<std::string, Data> data_map;
private:
	cc_type cc;
};