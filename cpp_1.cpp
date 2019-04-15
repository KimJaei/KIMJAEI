#include <iostream>
#include <string>
using namespace std;

class Circle
{
	int radius; //원의 반지름 값
	string name; // 원의 이름
public:
	void setCircle(string name, int radius) { this->name = name; this->radius = radius; } //멤버변수이름과 매개변수이름을 동일하게 선언하기위해 this를 사용함
	double getArea() { return 3.14 * radius * radius; } //getArea에 3.14 * radius * radius 값 반환
	string getName() { return name; } //getName()에 name 값 반환
};

class CircleManager
{
	Circle *p; //Circle 배열에 대한 포인터
	int size; //배열의 크기
public:
	CircleManager(int size) //size 크기의 배열을 동적 생성. 사용자로부터 입력 완료
	{ 
		string name; //name(이름)을 string으로 정의
		int radi; //radi(반지름)을 int형으로 정의
		p = new Circle[size]; //객체 배열을 동적으로 생성
		this->size = size; //멤버변수이름과 매개변수이름을 동일하게 선언하기위해 this 사용
		for (int i = 0; i < size; i++) //입력받은 원의 개수의 수만큼 반복문 실행
		{
			cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
			cin >> name >> radi; //이름과 반지름을 입력 받음
			p[i].setCircle(name, radi); //입력받은 이름과 반지름을 배열에 저장
		}

	}

	~CircleManager() { }
	void searchByName()
	{
		string name; //name(이름)을 string으로 정의
		cout << "검색하고자 하는 원의 이름 >> ";
		cin >> name; //이름을 입력 받음
		for (int i = 0; i < size; i++) //원의 개수의 수만큼 반복문 실행
		{
			if (p[i].getName() == name) //입력받은 이름과 배열에 저장된 이름이 같을 경우
			{
				cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl; //이름과 면적을 출력
			}
		}
	}
	void searchByArea()
	{

		int minarea; //minarea(최소 면적)을 int형으로 정의
		cout << "최소 면적을 정수로 입력하세요 >> ";
		cin >> minarea; //최소 면적을 입력 받음
		cout << minarea << "보다 큰 원을 검색합니다." << endl;
		for (int i = 0; i < size; i++) //원의 개수의 수만큼 반복문 실행
		{
			if (minarea < p[i].getArea()) //배열에 저장된 면적보다 입력받은 면적이 작을 때
			{
				cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ","; //이름과 면적을 출력
			}
		}
	}
};

int main()
{
	int n;

	cout << "원의 개수 >> ";
	cin >> n;
	if (n <= 0) return 0; //원의 개수가 0과 같거나 작으면 종료
	else //원의 개수가 0보다 크면 실행
	{
		CircleManager *p = new CircleManager(n); //생성자 CircleManager(size)를 호출
		p->searchByName(); //searchByName() 실행
		p->searchByArea(); //searchByArea() 실행
 		delete p; //동적 할당받은 객체 반환
	}
}