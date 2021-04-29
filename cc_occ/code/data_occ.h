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
	// ������Ϣ
	txn_man * txn;
	// ���ϴ�С
	int set_size;
	// ��д���ֵ
	vector<int> values;
	// ���������ݣ�ԭʼ���ݣ�
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

	// history����
	int his_len;
	// active����
	int active_len;

private:
    // ��֤���������Ƿ��г�ͻ
	bool conflict(setEntry * set1, setEntry * set2);
    // ��ȡ����Ķ�д����
	RC get_rw_set(txn_man * txn, setEntry * &rset, setEntry * &wset);
	// ��֤��������ʱ�����Ƿ����ص�
	bool is_overlap(setEntry * set, time_t start, time_t end);

	// �Ѿ��ύ�����д���ϣ����µ���
	setEntry * history;
	// ��Ծ�����д����
	setEntry * active;
	mutex latch;
};