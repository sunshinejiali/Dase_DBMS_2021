#include "data_occ.h"

setEntry::setEntry()  {
    txn = NULL;
    set_size = 0;
    next = NULL;
}

data_occ::data_occ()
{
	his_len = 0;
	active_len = 0;
	history = NULL;
	active = NULL;
}

void data_occ::init()
{
	his_len = 0;
	active_len = 0;
	history = NULL;
	active = NULL;
}

void data_occ::set(data_occ *data1, data_occ *data2)  {
    data1->his_len = data2->his_len;
    data1->history = data2->history;
    data1->active_len = data2->active_len;
    data1->active = data2->active;
}

data_occ &data_occ::operator=(const data_occ &d) {
    set(this, (data_occ*)& d);
    return *this;
}

data_occ::data_occ(const data_occ &d) {
    *this = d;
}

/*
 * 1. 获取结束时间戳end_ts，以及历史提交列表history，当前活跃事务列表active，并把当前事务加入active
 * 2. 对当前事务的读写集进行验证，判断是否有冲突
 *      2.1 验证当前事务的读集合是否与history中事务的写集合有重叠
 *      2.2 验证当前事务的读集合和写集合是否与active中事务的写集合有重叠
 * 3. 基于2中的验证结果，有以下两种情况
 *      3.1 若有冲突，则abort掉当前事务，并从active中移出
 *      3.2 若无冲突，则将当前事务的写操作更新到数据库中
 * 4. 将当前事务从active中移出并加入history
 */
RC data_occ::validate(txn_man * txn)
{

}

/*
 * 验证两个集合是否有冲突
 */
bool data_occ::conflict(setEntry * set1, setEntry * set2)
{

}

/*
 * 验证两个事务是否时间上有重合，参考ppt p7中关于时间的判定条件
 */
bool data_occ::is_overlap(setEntry * set, time_t start, time_t end)
{

}

/*
 * 获取当前事务的读写集
 */
RC data_occ::get_rw_set(txn_man * txn, setEntry * &rset, setEntry * &wset)
{
	wset->set_size = txn->wr_cnt;
	rset->set_size = txn->rd_cnt;
	wset->txn = txn;
	rset->txn = txn;
	for (int i = 0; i < txn->wr_cnt; i++) {
	    // 原始数据
		wset->datalist.push_back(txn->wr_list[i]->data);
		// 新写入的值
		wset->values.push_back(txn->wr_list[i]->value);
	}
	for (int j = 0; j < txn->rd_cnt; j++) {
	    // 读出的数据
		rset->datalist.push_back(txn->rd_list[j]);
	}
	return RCOK;
}


