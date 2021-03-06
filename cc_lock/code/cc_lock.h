#pragma once
#include "global.h"
#include "structure.h"

class cc_lock {
public:
	cc_lock();
	//??ȡ??
	RC lock_get(lock_t type, thread::id tid, Data &data);

	//?ͷ???
	RC lock_release(lock_t type, thread::id tid, Data &data);

	//???²???
	RC update(string key, int value, thread::id tid);

	//ɾ??????
	RC delete_(string key, thread::id tid);

	//????????
	RC insert(string key, int value, thread::id tid);

	//??????
	RC get(string key, int& value, thread::id tid);

	Engine engine;
private:
	//?ж????????Ƿ???ͻ
	bool conflict_lock(LockEntry lock1, LockEntry lock2);
};

