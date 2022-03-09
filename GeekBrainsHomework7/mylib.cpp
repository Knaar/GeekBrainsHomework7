#include <iostream>
#include <fstream>

#define Def(FirstNum,SecondNum,Null) FirstNum < SecondNum && FirstNum>=0 ? std::cout<<"true"<<std::endl<<std::endl : std::cout<<"false"<<std::endl<<std::endl
#define Size 5


namespace WTF {//��������� ��������� ������ ��� ���� �-�� 
	void MakeMassive(const int& size, float* Mass) {//������ ������, ����� ���� ����� � ������������� �����, ����� �������� �� �������������� � ������� �������
		for (size_t i = 0; i < size; i++)
		{
			Mass[i] = -4.44 + i;
		}
	}
	void PrintMassive(const int& size, float* Mass) {//������ �� �����
		std::cout << "Task 1.Massive : ";
		for (size_t i = 0; i < size; i++)
		{
			std::cout << Mass[i] << ",";
		}
		std::cout << std::endl<<std::endl;
	}
	void Check(int size, float* Mass) {//������� ������������� � ������������� �������� � �������
		int Minus{ 0 }, Plus{ 0 };

		for (size_t i = 0; i < size; i++)
		{
			Mass[i] < 0 ? Minus++ : Plus++;
		}
		std::cout << "Task 1.Negative numbers : " << Minus << std::endl << "       Positive numbers : " << Plus<<std::endl;
		std::cout << std::endl;
	}

}

void Task2Function() {
	
	int FirstNum, SecondNum;
	std::cout << "Task 2. Which your First number? ";
	std::cin >> FirstNum;
	std::cout << "And Second?";
	std::cin >> SecondNum;

	Def(FirstNum, SecondNum);
	
}

void Inicialisation(int *arr) {
	std::cout << "Task 3. Consecutively enter 5 values :"<<std::endl;
	for (size_t i = 0; i < Size; i++)
	{
		int n;
		std::cin >> n;
		arr[i] = n;
	}

}
void Task3_DeMonstrationFunction(int *arr) {
	for (size_t i = 0; i < Size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void BubblesSorting(int* arr) {
	for (size_t i = 0; i < Size; i++)
	{
		for (size_t i = 0; i <Size-1; i++)
		{
			//������������ ��������� ��������� ���������� ����� ����� ������. ��� � �� �����, ��� �����������. ��������� � ������ �� ���� ���������, ������ ���
			//����� ������� ������, ������� ����� �������� ������ ������������, �� ��������� ��������� � ���������
			//��������� ������ � �������� ��������� �������
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

void Task3Funktion() {//�������� �-� 3�� �������, ������������ ��������� �-��(����� ��� �������)
	
	int Massive[Size];//�������� ���� �� ������������

	Inicialisation(Massive);
	std::cout << "Your Massive before: ";
	Task3_DeMonstrationFunction(Massive);//�������� �-� ������� ������� �� ����� ������

	BubblesSorting(Massive);//����� ������� ����������� ����������
	std::cout << "Your Massive after: ";

	Task3_DeMonstrationFunction(Massive);//����� ������������ �� �����
	std::cout << std::endl;
}
#undef Size 5//������ ������ ���, ����� ����



void Task4() {
	struct Worker//���� �������
	{
		int id;
		char LevelClass;
		int age;
		int salary;
	};
#pragma pack(push,1)//���, ������� �������� �����������
	struct Worker2
	{
		int id;
		char LevelClass;
		int age;
		int salary;
	};
#pragma pack(pop)
	

	int* SizeOfStruct = new int(sizeof(Worker2));//������ ������������ ����������

	std::cout <<"Size of Struct = " << *SizeOfStruct;//������� �� ����� ��������

	std::ofstream TheBook("HiThere.txt");//�����1� ��������� ���� � ���������� � ����
	if (TheBook.is_open())
	{
		TheBook << "Size of Struct = " << *SizeOfStruct;
	}
	
	delete SizeOfStruct;
}
