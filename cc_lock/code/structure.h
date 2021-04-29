#pragma once
#include "global.h"
#include<queue>
#include<string>
#include<unordered_map>
#include<mutex>
#include<vector>
using namespace std;

// 锁信息
struct LockEntry {
    // 锁类型
	lock_t type;
	// 线程id
	std::thread::id tid;
};

// 数据项
struct Data {
    // 数据项时间戳
	time_t timestamp;
	int value;
	// 数据项上当前的锁
	LockEntry owner;
	// 锁等待列表
	queue<LockEntry*> waitlist;
	// 是否被删除
	bool deleted;
	std::mutex latch;

	Data();
	
	void set(Data* data1, Data* data2);

	Data& operator = (const Data& d);

	Data(const Data& d);
};

// 存储引擎
class Engine {
public:
	Engine();

	Engine(cc_type type);

	std::unordered_map<std::string, Data> data_map;  //hash map，存储数据的结构

private:
	cc_type cc;
};