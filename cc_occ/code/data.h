#pragma once
#include"global.h"
#include<ctime>

struct Data {
	int value;
	// ɾ??????
	bool deleted;
	std::mutex latch;

	std::time_t commitstamp;
    std::time_t readstamp;
    std::time_t writestamp;
	bool commit;

	Data() {
		value = -1;
		deleted = false;
		readstamp = -1;
		writestamp = -1;
		commitstamp = -1;
	}

	void set(Data* data1, Data* data2) {
		data1->deleted = data2->deleted;
		data1->readstamp = data2->readstamp;
		data1->writestamp = data2->writestamp;
		data1->commitstamp = data2->commitstamp;
		data1->value = data2->value;
	}

	Data& operator = (const Data& d) {
		set(this, (Data*)& d);
		return *this;
	}

	Data(const Data& d) {
		*this = d;
	}
};