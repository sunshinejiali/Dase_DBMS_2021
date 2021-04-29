#include"global.h"
#include"structure.h"

Engine::Engine()  {
    cc = CC_LOCK;
}

Engine::Engine(cc_type type)  {
    cc = type;
}

Data::Data()  {
    value = -1;
    owner.type=LOCK_NONE;
    deleted = false;
}

void Data::set(Data *data1, Data *data2)  {
    data1->deleted = data2->deleted;
    data1->owner = data2->owner;
    data1->timestamp = data2->timestamp;
    data1->value = data2->value;
    data1->waitlist = data2->waitlist;
    data1->waitlist = data2->waitlist;
}

Data &Data::operator=(const Data &d)  {
    set(this, (Data*)&d);
    return *this;
}

Data::Data(const Data &d) {
    *this = d;
}
