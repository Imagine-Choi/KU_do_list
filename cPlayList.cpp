#include "cPlayList.h"


cPlayList::cPlayList()
{
	this->list = new cSchedule[100];
	
	// +a ) ���� �� ī�װ� Data ���� By file �Է�
}


cPlayList::~cPlayList()
{
	delete[] list;
	list = nullptr;
}

void cPlayList::getSetting()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	srand((unsigned)time(NULL));
	// @ ���� color ���� ��� �ʿ��� �ʱ� ����
}

void cPlayList::playList()
{
	int sel = 0;
	while (sel != 6) {
		sel = showMenu();
		switch (sel) {
		case 1: {
			makeSchedule();
			break;
		}
		case 2: {
			printf("2. ��������");
			break;
		}
		case 3: {
			printf("3. ����Ȯ��");
			break;
		}
		case 4: {
			printf("4. ��������");
			break;
		}
		case 5: {
			printf("5. ī�װ� ����");
			break;
		}
		case 6: {
			printf("6. ����");
			break;
		}
		}
	}
}

int cPlayList::showMenu()
{
	int sel;
re:;

	system("cls");
	cout << "1) ���� �߰� 2) ���� ���� 3) ���� Ȯ�� 4) ���� ���� 5) ī�װ� ���� 6) ����\n"
		<< "\n�޴� ��ȣ�� �Է����ּ��� >> ";
	cin >> sel;

	if ((typeid(sel) != typeid(int)) || sel < 1 || sel>6) {
		cout << "�Է��� �ٽ� �Է����ּ���.\n";
		sel = -1;
		_getch();
		goto re;
	}

	return sel;
}
