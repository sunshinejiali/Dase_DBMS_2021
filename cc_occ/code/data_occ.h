#pragma once
#include<thread>
#include<time.h>
#include<mutex>
#include<vector>
#include "global.h"
#include "data.h"
#include "txn.h"

class setEntry {
public:
	setEntry();
	// 事务信息
	txn_man * txn;
	// 集合大小
	int set_size;
	// 新写入的值
	vector<int> values;
	// 读出的数据（原始数据）
	vector<Data *> datalist;
	setEntry * next;
};

class data_occ {
public:
	data_occ();
	void init();
	RC validate(txn_man * txn);

	void set(data_occ* data1, data_occ* data2);

	data_occ& operator = (const data_occ& d);

	data_occ(const data_occ& d);

	// history长度
	int his_len;
	// active长度
	int active_len;

private:
    // 验证两个集合是否有冲突
	bool conflict(setEntry * set1, setEntry * set2);
    // 获取事务的读写集合
	RC get_rw_set(txn_man * txn, setEntry * &rset, setEntry * &wset);
	// 验证两个事务时间上是否有重叠
	bool is_overlap(setEntry * set, time_t start, time_t end);

	// 已经提交事务的写集合，从新到旧
	setEntry * history;
	// 活跃事务的写集合
	setEntry * active;
	mutex latch;
};