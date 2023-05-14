#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>
using namespace std;

// функция с алгоритмом двоичного поиска 
int Search_Binary (int arr[], int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;
		
		if (key < arr[midd])       // если искомое меньше значения в ячейке
			right = midd - 1;      // смещаем правую границу поиска
		else if (key > arr[midd])  // если искомое больше значения в ячейке
			left = midd + 1;	   // смещаем левую границу поиска
		else                       // иначе (значения равны)
			return midd;           // функция возвращает индекс ячейки

		if (left > right)          // если границы сомкнулись 
			return -1;
	}
}

//вывод массива на экран
void showArr(int arr[], int arrSize)
{
	if (arrSize <= 10000)
	{
		for (int i = 0; i < arrSize; i++)
			{
			cout << setw(4) << arr[i];
			if ((i + 1) % 10 == 0)
				cout << endl;
			}
	cout << endl << endl;
	}
	
}

//линейный поиск
int linSearch(int arr[], int requiredKey, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == requiredKey)
			return i;
	}
	return -1;
}


int main()
{
	int arrSize;
	int requiredKey = 0; // искомое значение
	int nElement = 0; // номер элемента массива
	int st_el;

	cout << "Ukazhite s kakogo chisla nachinaetsya massiv: ";
	cin >> st_el;

	cout << "Ukazhite razmer massiva: ";
	cin >> arrSize;

	cout << arrSize << endl;

	int arr[arrSize];

	//запись чисел в массив
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = st_el;
		st_el++;
	}
 
	showArr(arr, arrSize);

	cout << "Iskomoe chislo? ";
	cin >> requiredKey; // ввод искомого числа

	//поиск искомого числа и запись номера элемента
	cout << "Linery Search" << endl;
	clock_t start = clock();
	nElement = linSearch(arr, requiredKey, arrSize);
	clock_t end = clock();
  	double seconds = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
  	cout << "The time: " << seconds << " milliseconds" << endl;

	if (nElement != -1)
	{
		//если в массиве найдено искомое число - выводим индекс элемента на экран
		cout << "Znachenie " << requiredKey << " nahoditsya v yacheike s indeksom: " << nElement << endl;
	}
	else
	{
		//если в массиве не найдено искомое число
		cout << "Dannoe znachenie otsutstvuet" << endl;
	}
    cout << "--------------------------------------------------------------------------------------------" << endl;

	int index = 0; // индекс ячейки с искомым значением

	cout << "Binary Search" << endl;
	clock_t start2 = clock();
	index = Search_Binary (arr, 0, arrSize, requiredKey);
	clock_t end2 = clock();
  	double seconds2 = (double)(end2 - start2) / (CLOCKS_PER_SEC / 1000);
  	cout << "The time Binary Search: " << seconds2 << " milliseconds" << endl;

	if (index >= 0) 
		cout << "Ukazannoe chislo nahoditsya v yacheike: " << index << "\n\n";
	else
		cout << "V massive net takogo chisla!\n\n";
	return 0;
}
