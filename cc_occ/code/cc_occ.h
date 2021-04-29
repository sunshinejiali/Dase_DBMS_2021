#pragma once
#include "global.h"
#include "structure.h"
#include "txn.h"
#include<thread>
using namespace std;

class cc_occ{
public:
	cc_occ();

	// 增加一个数据到事务的写集合
	RC update(string key, int value, txn_man * txn);

	// 增加一个数据到事务的读集合
	RC get(string key, int& value, txn_man * txn);

	// 提交事务
	RC commit(txn_man * txn);

	// 并发控制数据的操作
	data_occ occ_man;

	// 存储引擎
	Engine engine;
};