#include <iostream>
#include <fstream>

#define Def(FirstNum,SecondNum,Null) FirstNum < SecondNum && FirstNum>=0 ? std::cout<<"true"<<std::endl<<std::endl : std::cout<<"false"<<std::endl<<std::endl
#define Size 5


namespace WTF {//использую неймспейс только для этих ф-ий 
	void MakeMassive(const int& size, float* Mass) {//создаю массив, чтобы были отриц и положительные числа, задаю значения от отрицательного и полюсую единицу
		for (size_t i = 0; i < size; i++)
		{
			Mass[i] = -4.44 + i;
		}
	}
	void PrintMassive(const int& size, float* Mass) {//печать на экран
		std::cout << "Task 1.Massive : ";
		for (size_t i = 0; i < size; i++)
		{
			std::cout << Mass[i] << ",";
		}
		std::cout << std::endl<<std::endl;
	}
	void Check(int size, float* Mass) {//подсчет положительных и отрицательных значений с выводом
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
			//Перепробовал несколько вариантов выполнения свапа через макрос. так и не понял, как реализовать. указатели в дефайн не смог отправить, ссылки тож
			//Можно создать массив, который быдет отдельно дефайн переделывать, по получится громоздко и некрасиво
			//Сложность именно в передаче элементов массива
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

void Task3Funktion() {//ключевая ф-я 3го задания, объединяющая несколько ф-ий(прост для красоты)
	
	int Massive[Size];//дописать ввод от пользователя

	Inicialisation(Massive);
	std::cout << "Your Massive before: ";
	Task3_DeMonstrationFunction(Massive);//вызываем ф-ю которая выводит на экран массив

	BubblesSorting(Massive);//затем функция пузырьковой сортировки
	std::cout << "Your Massive after: ";

	Task3_DeMonstrationFunction(Massive);//снова демонстрация на экран
	std::cout << std::endl;
}
#undef Size 5//сделал просто так, чтобы было



void Task4() {
	struct Worker//Дыва структа
	{
		int id;
		char LevelClass;
		int age;
		int salary;
	};
#pragma pack(push,1)//тот, который упакован прагмапаком
	struct Worker2
	{
		int id;
		char LevelClass;
		int age;
		int salary;
	};
#pragma pack(pop)
	

	int* SizeOfStruct = new int(sizeof(Worker2));//создаём динамическую переменную

	std::cout <<"Size of Struct = " << *SizeOfStruct;//выводим на экран значение

	std::ofstream TheBook("HiThere.txt");//создаё1м текстовый файл и записываем в него
	if (TheBook.is_open())
	{
		TheBook << "Size of Struct = " << *SizeOfStruct;
	}
	
	delete SizeOfStruct;
}
