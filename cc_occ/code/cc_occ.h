#pragma once
#include "global.h"
#include "structure.h"
#include "txn.h"
#include<thread>
using namespace std;

class cc_occ{
public:
	cc_occ();

	// ����һ�����ݵ������д����
	RC update(string key, int value, txn_man * txn);

	// ����һ�����ݵ�����Ķ�����
	RC get(string key, int& value, txn_man * txn);

	// �ύ����
	RC commit(txn_man * txn);

	// �����������ݵĲ���
	data_occ occ_man;

	// �洢����
	Engine engine;
};