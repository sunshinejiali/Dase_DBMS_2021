#pragma once
#include<iostream>
#include<thread>

using namespace std;

/**
 * ����ֵ����������Ľ�����ͣ�RCOK ��ȷ��ERROR ����
 * NOT_FOUND ��������ڣ� ALREADY_EXIST �������Ѵ���
 */
enum RC { RCOK,  RCERROR, ABORT, WAIT, FINISH, NOT_FOUND, ALREADY_EXIST };

/**
 * �������ֲ������ԣ�LOCK ��������OCC �ֹ۲������ƣ�TO����ʱ���
 */
enum cc_type {CC_LOCK, CC_OCC, CC_TO};

