#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class Player
{
	string name;
public:
	void setName(string name) { this->name = name; } //멤버변수이름과 매개변수이름을 동일하게 선언하기위해 this를 사용함
	string getName() { return name; } //name값 반환
};

class GamblingGame
{
	Player *p;
public:
	void game()
	{
		string name1, name2;
		string null;
		p = new Player[2]; //플레이어정보를 배열로 만들어서 p에 저장
		srand((unsigned)time(0)); //난수 초기화

		cout << "***** 겜블링 게임을 시작합니다. *****" << endl;

		cout << "첫번째 선수 이름 >>";
		cin >> name1;
		p[0].setName(name1);
		cout << "두번째 선수 이름 >>";
		cin >> name2;
		p[1].setName(name2);

		while (true)
		{
			for (int i = 0; i < 1; i++)
			{
				int num[3];
				for (int i = 0; i < 2; i++)
				{
					cout << p[i].getName() << ":<Enter>";
					getline(cin, null, '\n'); //엔터가 입력되면 입력받는것을 종료
					cout << '\n';

					for (int i = 0; i < 3; i++) //난수를 3번 생성하기 위한 반복문
					{
						num[i] = rand() % 2; //난수 생성
						cout << num[i] << '\t';
					}
					if (num[0] == num[1]) //첫번째 난수값과 두번째 난수값이 같은경우
					{
						if (num[1] == num[2]) //두번째 난수값과 세번째 난수값이 같은 경우
						{
							cout << p[i].getName() << "님 승리!!" << endl;
							return;
						}
						else
							cout << "아쉽군요!" << endl;
					}
					else
						cout << "아쉽군요!" << endl;

				}
			}


		}
	}
};

int main()
{
	GamblingGame start;
	start.game();
}
