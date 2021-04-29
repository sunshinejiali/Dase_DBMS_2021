#pragma once
#include "global.h"
#include<queue>
#include<string>
#include<unordered_map>
#include<mutex>
#include<vector>
using namespace std;

// ����Ϣ
struct LockEntry {
    // ������
	lock_t type;
	// �߳�id
	std::thread::id tid;
};

// ������
struct Data {
    // ������ʱ���
	time_t timestamp;
	int value;
	// �������ϵ�ǰ����
	LockEntry owner;
	// ���ȴ��б�
	queue<LockEntry*> waitlist;
	// �Ƿ�ɾ��
	bool deleted;
	std::mutex latch;

	Data();
	
	void set(Data* data1, Data* data2);

	Data& operator = (const Data& d);

	Data(const Data& d);
};

// �洢����
class Engine {
public:
	Engine();

	Engine(cc_type type);

	std::unordered_map<std::string, Data> data_map;  //hash map���洢���ݵĽṹ

private:
	cc_type cc;
};