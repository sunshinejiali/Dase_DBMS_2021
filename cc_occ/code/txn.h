#pragma once
#include"global.h"
#include"data.h"
#include<thread>
#include<ctime>
#include<vector>

class updateEntry {
public:
    // 原始数据
	Data * data;
	// 新写入的值
	int value;
};

// 事务信息
class txn_man {
public:
	txn_man() {
		start_ts = INT64_MAX;
		end_ts = INT64_MAX;
		commit_ts = INT64_MAX;
		tid = this_thread::get_id();

		// 写、读操作个数
		rd_cnt = 0;
		wr_cnt = 0;
	}

	// 读阶段开始时间戳
    std::time_t start_ts;

	// 读阶段结束时间戳
    std::time_t end_ts;

    // 事务提交时间戳
    std::time_t commit_ts;

	thread::id tid;

	// 缓存写操作更新的数据
	vector<updateEntry*> wr_list;

	// 读操作的记录
	vector<Data*> rd_list;

	// 读操作个数
	int rd_cnt;

	// 写操作个数
	int wr_cnt;
};