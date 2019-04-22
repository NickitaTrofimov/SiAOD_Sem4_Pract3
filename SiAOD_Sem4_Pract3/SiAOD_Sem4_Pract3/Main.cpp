#include <iostream>
using namespace std;
//функция обмена
void Swap(int *Mas, int i)
{
	int temp;
	temp = Mas[i];
	Mas[i] = Mas[i - 1];
	Mas[i - 1] = temp;
}
//функция шейкерной сортировки
void ShakerSort(int *Mas, int Start, int N)
{
	int Left, Right, i;
	Left = Start;
	Right = N - 1;
	while (Left <= Right)
	{
		for (i = Right; i >= Left; i--)
			if (Mas[i - 1] < Mas[i]) Swap(Mas, i);
		Left++;
		for (i = Left; i <= Right; i++)
			if (Mas[i - 1] < Mas[i]) Swap(Mas, i);
		Right--;
	}
}

// Функция сортировки прямым выбором
void selectionSort(int *num, int size)
{
	int min, temp; // для поиска минимального элемента и для обмена
	for (int i = 0; i < size - 1; i++)
	{
		min = i; // запоминаем индекс текущего элемента
		// ищем минимальный элемент чтобы поместить на место i-ого
		for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
		{
			if (num[j] < num[min]) // если элемент меньше минимального,
				min = j;       // запоминаем его индекс в min
		}
		temp = num[i];      // меняем местами i-ый и минимальный элементы
		num[i] = num[min];
		num[min] = temp;
	}
}

// Функция сортировки прямыми включениями
void inclusionSort(int *num, int size)
{
	// Для всех элементов кроме начального
	for (int i = 1; i < size; i++)
	{
		int value = num[i]; // запоминаем значение элемента
		int index = i;     // и его индекс
		while ((index > 0) && (num[index - 1] > value))
		{   // смещаем другие элементы к концу массива пока они меньше index
			num[index] = num[index - 1];
			index--;    // смещаем просмотр к началу массива
		}
		num[index] = value; // рассматриваемый элемент помещаем на освободившееся место
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");

	//Шейкер сортировка
	cout << "Шейкер сортировка" << endl;

	int n, k;
	cout << "Размер массивов > ";
	cin >> n;
	cout << endl;

	int *A = new int[n];

	for (k = 0; k < n; k++)
	{
		cout << "a[" << k + 1 << "] = ";
		cin >> A[k];
	}
	cout << endl;

	ShakerSort(A, 1, n);
	cout << "Результирующий массив: ";

	for (k = 0; k < n; k++)
		cout << " " << A[k];
	cout << endl;

	//-----------------------------------------------------------------------------------------------------------------//
	//Сортировка прямым выбором
	cout << "Сортировка прямым выбором" << endl;

	int *a = new int[n];

	cout << "Введите значения элементов:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i+1 << "] = ";
		cin >> a[i];
	}
	cout << endl;

	selectionSort(a, n);  // вызываем функцию сортировки

	// Выводим отсортированные элементы массива
	cout << "Результирующий массив: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	//-----------------------------------------------------------------------------------------------------------------//
	//Сортировка пузырьком
	cout << "Сортировка пузырьком" << endl;

	int temp;
	int *arr = new int[n];

	cout << "Введите значения элементов:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> arr[i];
	}
	cout << endl;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// меняем элементы местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	//-----------------------------------------------------------------------------------------------------------------//
	//Сортировка прямым включением
	cout << "Сортировка прямым включением" << endl;

	int *r = new int[n];

	cout << "Введите значения элементов:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> r[i];
	}

	inclusionSort(a, n);

	cout << "Результирующий массив: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	//-----------------------------------------------------------------------------------------------------------------//
	//Нахождение количества наименьших элементов
	cout << "Нахождение количества наименьших элементов" << endl;

	int *TPac = new int[n];

	cout << "Введите значения элементов:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> TPac[i];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (TPac[j] > TPac[j + 1]) {
				// меняем элементы местами
				temp = TPac[j];
				TPac[j] = TPac[j + 1];
				TPac[j + 1] = temp;
			}
		}
	}

	int min;
	int counter = 1;
	min = TPac[0];

	for (int i = 0; i < n - 1; i++) {
		if (min == TPac[i + 1]) {
			counter++;
		}
		else if (min != TPac[i + 1]) {
			break;
		}
	}
	cout << "Количчество минимальных элементов в массиве = " << counter << endl;

	system("pause");
}
