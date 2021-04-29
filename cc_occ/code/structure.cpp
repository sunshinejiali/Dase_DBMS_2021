#include<iostream>
#include<unordered_map>
#include<string>

#include"global.h"
#include"structure.h"
Engine::Engine()  {
    cc = CC_LOCK;
}

Engine::Engine(cc_type type)  {
    cc = type;
}

