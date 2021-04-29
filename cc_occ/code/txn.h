#pragma once
#include"global.h"
#include"data.h"
#include<thread>
#include<ctime>
#include<vector>

class updateEntry {
public:
    // ԭʼ����
	Data * data;
	// ��д���ֵ
	int value;
};

// ������Ϣ
class txn_man {
public:
	txn_man() {
		start_ts = INT64_MAX;
		end_ts = INT64_MAX;
		commit_ts = INT64_MAX;
		tid = this_thread::get_id();

		// д������������
		rd_cnt = 0;
		wr_cnt = 0;
	}

	// ���׶ο�ʼʱ���
    std::time_t start_ts;

	// ���׶ν���ʱ���
    std::time_t end_ts;

    // �����ύʱ���
    std::time_t commit_ts;

	thread::id tid;

	// ����д�������µ�����
	vector<updateEntry*> wr_list;

	// �������ļ�¼
	vector<Data*> rd_list;

	// ����������
	int rd_cnt;

	// д��������
	int wr_cnt;
};