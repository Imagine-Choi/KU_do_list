// ****** cSchedule.cpp ******
#include "cSchedule.h"



cSchedule::cSchedule()
{
}


cSchedule::~cSchedule()
{
	// @ ���� �Ҵ��� �޸� ��ȯ
	if (this->categoryData != nullptr) {
		delete[] this->categoryData;
		this->categoryData = nullptr;
	}
}

// getchar �Լ� �ٽ� ���� �� �Է¹��� ���� �غ���
void cSchedule::makeSchedule()
{
	int sel = -1;
	string name, category;

	while (1) {
	re:;
		system("cls");
		cout << "<���� �߰�>\n\n";

		// 1. ���� �̸�
		_getch();
		cout << "������ �̸��� �Է����ּ��� >> ";
		while (getchar() != '\n') {
			cin >> name;
		}

		if (name.size() > 20) {
			cout << ">> 20�� ���Ϸ� �Է����ּ���.";
			system("pause");
			goto re;
		}
		else if (name.empty()) {
			cout << ">> ���� �Է� �Ұ�. �ٽ� �Է����ּ���.";
			system("pause");
			goto re;
		}
		else {
			this->sName = name;
		}

		// 2. ���� ī�װ�
		cout << "������ ī�װ��� �Է����ּ��� >> ";
		while (getchar() != '\n') {
			cin >> category;
		}
		/*	// ī�װ� Ȯ�� ����
		for (size_t i = 0; i < categoryNum; i++) {
			if (category.compare(categoryData[i])) {
				this->sCategory = category;
			}
			else {
				cout << ">> �ش� ī�װ��� �������� �ʽ��ϴ�.";
				system("pause");
				goto re;
			}
		}
		*/

		// 3. ���� �ݺ� ���
		cout << "������ �ݺ� ����� �������ּ��� 1)�� �ݺ� 2)�� �ݺ� 3)���� �ݺ� 4)�ݺ� ���� >> ";
		while (getchar() != '\n') {
			cin >> sel;
		}
		if (!(sel == 1 || sel == 2 || sel == 3 || sel == 4)) {
			cout << ">> �ùٸ� �Է��� ���ּ���.";
			system("pause");
			goto re;
		}
		else
			this->sType = sel;

		// 4. ���� �� ���� ��¥ �Է�
		cout << "������ ���� ��¥ �� �ð��� �Է����ּ��� [ex) 2022 02 03 00 30] >> ";
		while (getchar() != '\n') {
			cin >> sYear >> sMonth >> sDay >> sHour >> sMin;
		}
		// ����ó�� ���� ����

		if (sel == 4) {
			cout << "������ ���� ��¥ �� �ð��� �Է����ּ��� [ex) 2022 02 07 15 30] >> ";
			while (getchar() != '\n') {
				cin >> eYear >> eMonth >> eDay >> eHour >> eMin;
			}
			// ����ó�� ���� ����
		}
		else {
			// ���� ��¥ ����ؼ� �ݺ� �ֱ� �����ϱ�
		}
		cout << "\n\"" << sName << "\" ���� �߰��� �Ϸ�Ǿ����ϴ�.";
		_getch();
		break;
	}
}

bool cSchedule::makeCategory()
{
	string fileName = "categoryData.txt";
	ifstream fin(fileName);

	// @ ���� ���� ���� �� ����ó��
	if (!fin.is_open()) {
		cerr << "[Error] categoryData.txt ������ �� �� �����ϴ�. ��θ� Ȯ�����ּ���.\n";
		_getch();
		return false;
	}

	fin >> this->categoryNum;
	this->categoryData = new string[this->categoryNum];

	for (size_t i = 0; i < this->categoryNum; i++) 
		fin >> this->categoryData[i];

	return true;
}

bool cSchedule::readData(string filename)
{
	return false;
}

bool cSchedule::saveData(string filename)
{
	return false;
}

// # ����ó�� �Լ� :: ���� �̸�
int cSchedule::isRightSchedule(string name)
{
	return 0;
}

// # ����ó�� �Լ� :: �ݺ� Ÿ��
int cSchedule::isRightSchedule(int type)
{
	return 0;
}

// # ����ó�� �Լ� :: ���� ��¥ �� �ð�
int cSchedule::isRightSchedule(int year, int month, int day, int hour, int min)
{
	return 0;
}
