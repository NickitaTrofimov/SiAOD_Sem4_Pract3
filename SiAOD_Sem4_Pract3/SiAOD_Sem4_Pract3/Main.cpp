#include <iostream>
using namespace std;
//������� ������
void Swap(int *Mas, int i)
{
	int temp;
	temp = Mas[i];
	Mas[i] = Mas[i - 1];
	Mas[i - 1] = temp;
}
//������� ��������� ����������
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

// ������� ���������� ������ �������
void selectionSort(int *num, int size)
{
	int min, temp; // ��� ������ ������������ �������� � ��� ������
	for (int i = 0; i < size - 1; i++)
	{
		min = i; // ���������� ������ �������� ��������
		// ���� ����������� ������� ����� ��������� �� ����� i-���
		for (int j = i + 1; j < size; j++)  // ��� ��������� ��������� ����� i-���
		{
			if (num[j] < num[min]) // ���� ������� ������ ������������,
				min = j;       // ���������� ��� ������ � min
		}
		temp = num[i];      // ������ ������� i-�� � ����������� ��������
		num[i] = num[min];
		num[min] = temp;
	}
}

// ������� ���������� ������� �����������
void inclusionSort(int *num, int size)
{
	// ��� ���� ��������� ����� ����������
	for (int i = 1; i < size; i++)
	{
		int value = num[i]; // ���������� �������� ��������
		int index = i;     // � ��� ������
		while ((index > 0) && (num[index - 1] > value))
		{   // ������� ������ �������� � ����� ������� ���� ��� ������ index
			num[index] = num[index - 1];
			index--;    // ������� �������� � ������ �������
		}
		num[index] = value; // ��������������� ������� �������� �� �������������� �����
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");

	//������ ����������
	cout << "������ ����������" << endl;

	int n, k;
	cout << "������ �������� > ";
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
	cout << "�������������� ������: ";

	for (k = 0; k < n; k++)
		cout << " " << A[k];
	cout << endl;

	//-----------------------------------------------------------------------------------------------------------------//
	//���������� ������ �������
	cout << "���������� ������ �������" << endl;

	int *a = new int[n];

	cout << "������� �������� ���������:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i+1 << "] = ";
		cin >> a[i];
	}
	cout << endl;

	selectionSort(a, n);  // �������� ������� ����������

	// ������� ��������������� �������� �������
	cout << "�������������� ������: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	//-----------------------------------------------------------------------------------------------------------------//
	//���������� ���������
	cout << "���������� ���������" << endl;

	int temp;
	int *arr = new int[n];

	cout << "������� �������� ���������:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> arr[i];
	}
	cout << endl;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// ������ �������� �������
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
	//���������� ������ ����������
	cout << "���������� ������ ����������" << endl;

	int *r = new int[n];

	cout << "������� �������� ���������:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> r[i];
	}

	inclusionSort(a, n);

	cout << "�������������� ������: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	//-----------------------------------------------------------------------------------------------------------------//
	//���������� ���������� ���������� ���������
	cout << "���������� ���������� ���������� ���������" << endl;

	int *TPac = new int[n];

	cout << "������� �������� ���������:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> TPac[i];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (TPac[j] > TPac[j + 1]) {
				// ������ �������� �������
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
	cout << "����������� ����������� ��������� � ������� = " << counter << endl;

	system("pause");
}
