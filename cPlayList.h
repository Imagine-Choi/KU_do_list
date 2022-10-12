#pragma once
#include "cSchedule.h"

class cPlayList
	:public cSchedule
{
private:
	// @ ���� ������ �迭
	cSchedule* list;
	
	// @ ���� ����
	int count = 0;

	// @ Data Files	:: ���� ���� ���
	string dataSchedule = "data.txt";
	string dataCategory = "dataCategory.txt";
public:
	cPlayList();
	~cPlayList();

	// @ ȯ�� Set
	void getSetting();

	// @ play �Լ�
	void playList();

	// @ showMenu
	int showMenu();

};

