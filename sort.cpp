#include <iostream>
#include <time.h>

template <typename T>

// ���������� ������� Bubble Sort
void bubbleSort(T arr [], int size_arr)
{
	// ����������� �� ����� �������
	for (int i = 0; i < size_arr; i++) 
	{
		for (int j = 0; j < size_arr - 1; j++)
		{
			// ��������� ����� ����� ��� �������� ����� - ���� ��� ��������� �����������, ��� �������� ������ j ������, ��� �������� ������ j + 1, �� �� ������ �������� ���� ����� �������
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j]; // �������� �������������� ���������� 
				// ��� ������ ���. ���������� ������ �������� ����� ������� ���, ��� ������� �������� ������ �� ������ j, ������� - �� ������ j+1
				arr[j] = arr[j + 1]; 
				arr[j + 1] = temp; 
			}
		}
	}
	// ����� ���������������� �������
	std::cout << "��������������� ������ ������� BubbleSort: ";
	for (int i = 0; i < size_arr; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>

// ���������� ������� Selection Sort
void selectionSort(T arr[], int size_arr)
{
	// �������� �������������� ����������: pos_min - ����� ������, � ������� ��������� ����������� �������, temp - ��� ������������ �������� �������
	int pos_min, temp;
	// ���������� ������� ����������� � ���������� ������� � ������� ��� ����
	for (int i = 0; i < size_arr - 1; i++)
	{
		pos_min = i; // ������������� pos_min �� ������� ������ �������

		// ���������� 'j' �������� ����� ������ � ������� ��������, ��������, ��� 'min'.
		for (int j = i + 1; j < size_arr; j++) // ���� �� ������ 'j' ��������� � ������� 'i', �� 'min' ����������� �� � ����� �����, ��������, � ���� ��� �������������
		{
			if (arr[j] < arr[pos_min]) // ���� ����� �������� �������, ������ ��������
				pos_min = j;
		}
		// ���� pos_min ������ �� ����� i, ���������� ������ ������� ��������, ������� ���������� ������������ �������� �������
		if (pos_min != i)
		{
			temp = arr[i];
			arr[i] = arr[pos_min];
			arr[pos_min] = temp;
		}
		// ������� ������ i �������������, ������ �� 1 � �.�., �������� �����������
	}
	// ����� ���������������� �������
	std::cout << "��������������� ������ ������� SelectionSort: ";
	for (int i = 0; i < size_arr; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>

// ���������� ������� Insertion Sort
void insertionSort(T arr[], int size_arr) {
	// ������������, ��� ������ ������� ������� ��� ������������
	for (int step = 1; step < size_arr; step++) {
		int key = arr[step]; // ������� ��������� ������� ������� � ����� ������� ��� �������� ������ key
		int j = step - 1;

		while (key < arr[j] && j >= 0) { // ��������� key c ���������� ��������� ������� - ���� ���������� ������, ��� key, �� key ���������� ����� ���������� ���������
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
		// ��� ������� "�������" ���������� ������� ������� �� ����� ����������� � ���������� �� �����, � ������ ���������
	}
	// ����� ���������������� �������
	std::cout << "��������������� ������ ������� InsertionSort: ";
	for (int i = 0; i < size_arr; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	// ��������� �������� ����� � ������� ������� setlocale
	setlocale(LC_ALL, "Russian");

	// ���� ���������� size_arr (����������� �������) � ����������
	int size_arr;
	std::cout << "������� ����������� �������: ";
	std::cin >> size_arr;
	std::cout << std::endl;

	// �������� ������� (��������� ������������ ������, �.�. ����������� �������� � ����������)
	int* arr = new int[size_arr];

	// ���������� ������� ���������� ������� � ��������� �� 0 �� 999 ������������
	srand(time(NULL)); // �������, ���������������� "���������" ��������� ����� - ��� ������ ������� time ���������� ������ �����
	std::cout << "�������� ������: ";
	for (int i = 0; i < size_arr; i++)
	{
		arr[i] = rand() % 1000;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	// ����� ������� ���������� - Bubble Sort, Selection Sort, Insertion Sort
	bubbleSort(arr, size_arr);
	selectionSort(arr, size_arr);
	insertionSort(arr, size_arr);

	// �������� ������� ��� ������������ ������
	delete[]arr;
	return 0;
}