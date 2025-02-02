#include "cPlayList.h"


cPlayList::cPlayList()
{
	this->list = new cSchedule[100];
	
	// +a ) 일정 및 카테고리 Data 구문 By file 입력
	/*
	
	Data 파일 예시

	12						-> &sCount
	1 0 2022 10 12 19 30		-> &sType, &sIsDone, &날짜s
	4 1 2022 10 1 10 30 2022 10 2 11 0	-> 마찬가지 (타입 받아서 분기 코드 쓰면 될 듯)
	*/
	
	/*
	categoryData 파일 예시
	4				-> &cateroryNum
	// 이후 categoryData = new string[num] 해주고
	운동			-> &categoryData[0]		
	취미			-> ~[1]
	공부
	아르바이트
	*/

}


cPlayList::~cPlayList()
{
	// 메모리 반환 :: 일정
	if (this->list != nullptr) {
		delete[] this->list;
		this->list = nullptr;
	}

	// 메모리 반환 :: 카테고리
	if (this->categoryData != nullptr) {
		delete[] this->categoryData;
		this->categoryData = nullptr;
	}
}

void cPlayList::addSchedule()
{
	if (sCount < 100) {
		list[sCount++].makeSchedule();
	}
	else {
		cout << ">> 일정을 더 이상 추가할 수 없습니다.\n";
		Sleep(1000);
	}
}

bool cPlayList::readData(string filename)
{
	return false;
}

bool cPlayList::saveData(string filename)
{
	return false;
}

bool cPlayList::makeCategory()
{
	string fileName = "categoryData.txt";
	ifstream fin(fileName);

	// @ 파일 열기 실패 시 예외처리
	if (!fin.is_open()) {
		cerr << "[Error] categoryData.txt 파일을 열 수 없습니다. 경로를 확인해주세요.\n";
		_getch();
		return false;
	}

	fin >> this->categoryNum;
	this->categoryData = new string[this->categoryNum];

	for (size_t i = 0; i < this->categoryNum; i++)
		fin >> this->categoryData[i];

	return true;
}

void cPlayList::getSetting()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	srand((unsigned)time(NULL));
	// @ 이후 color 설정 등등 필요한 초기 설정
}

void cPlayList::playList()
{
	int sel = 0;
	while (sel != 6) {
		sel = showMenu();
		switch (sel) {
		case 1: {
			addSchedule();
			break;
		}
		case 2: {
			printf("2. 일정삭제");
			break;
		}
		case 3: {
			printf("3. 일정확인");
			break;
		}
		case 4: {
			printf("4. 일정편집");
			break;
		}
		case 5: {
			printf("5. 카테고리 관리");
			break;
		}
		case 6: {
			printf("6. 종료");
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
	cout << "1) 일정 추가 2) 일정 삭제 3) 일정 확인 4) 일정 편집 5) 카테고리 관리 6) 종료\n"
		<< "\n메뉴 번호를 입력해주세요 >> ";
	cin >> sel;

	if ((typeid(sel) != typeid(int)) || sel < 1 || sel > 6) {
		cout << "입력을 다시 입력해주세요.\n";
		sel = -1;
		_getch();
		goto re;
	}

	return sel;
}
