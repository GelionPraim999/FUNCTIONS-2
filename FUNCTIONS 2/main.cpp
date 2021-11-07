#include<iostream>
#include<ctime>	
using namespace std;
#define delimiter "\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
const unsigned int ROWS = 4;
const unsigned int COLS = 5;
void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxRand = 100);	//Заполняет массив случайными числами
void FillRand(double arr[], const unsigned int n, int minRand = 0, int maxRand = 100);	//Заполняет массив случайными числами
template<typename T>void Print(T arr[], const unsigned int n);
template<typename T>void Print(T arr[ROWS][COLS], const unsigned int ROWS, const unsigned int COLS);
template<typename D>void ReversePrint(D arr[], const unsigned int n); 
template<typename S>S Sum(S arr[], const unsigned int n);
template<typename A>A Avg(A arr[], const unsigned int n);
template<typename M>M minValueIn(M arr[], const unsigned int n, int min);
template<typename MA>MA maxValueIn(MA arr[], const unsigned int n, int max);
template<typename V>void Sort(V arr[], const unsigned int n);
void main()
{
	setlocale(LC_ALL, "");
	const unsigned int n = 5;
	int arr[n];
	int minRand, maxRand;
	//cout << "Введите минимальное случайное число: "; cin >> minRand;
	//cout << "Введите максимальное случайное число: "; cin >> maxRand;

	FillRand(arr, n, 200, 300);
	Print(arr, n);
	cout << delimiter << endl;
	double brr[n];
	FillRand(brr, n);
	Print(brr, n);
	int min = 0;
	int max = 0;
	cout << delimiter << endl;
	cout << "Выводит массив в обратном направлении: \t";ReversePrint(arr, n);
	cout << delimiter << endl;
	cout << "Сумма элементов массива : \t"<< Sum(arr, n) << endl;
	cout << delimiter << endl;
	cout << "Среднее арефметическое элементов массива :\t" << Avg(arr, n) << endl;
	cout << delimiter << endl;
	cout << "Минимальное значение массива : \t " << minValueIn(arr, n, min) << endl;
	cout << delimiter << endl;
	cout << "Максимальное значение массива : \t" << maxValueIn(arr, n, max) << endl;
	cout << delimiter << endl;
	cout << "Массив в порядке возрастания :\t"; Sort(arr, n);
	cout << delimiter << endl;

	int i_arr_2[ROWS][COLS] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	Print(i_arr_2, ROWS, COLS);
	cout << delimiter << endl;
	double d_arr_2[ROWS][COLS] =
	{
	{ 2.5, 3.14,8,3 },
	{ 4.2, 7.3, 9.4 },
	{.25}
};
	Print(d_arr_2, ROWS, COLS);
}

void FillRand(int arr[], const unsigned int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(double arr[], const unsigned int n, int minRand , int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
	}
}
template<typename T>
void Print(T arr[], const unsigned int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>
void Print(T arr[ROWS][COLS], const unsigned int ROWS, const unsigned int COLS)
{
	for (int i = 0; i <  ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

}
template<typename D>
void ReversePrint(D arr[], const unsigned int n) 
{
	for (int i = n - 1; i >= 0; --i)
	{
		cout << arr[i] << "  \t";
	}
	cout << endl;
}
template<typename S>S Sum(S arr[], const unsigned int n)
{
	S sum = S();
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
template<typename A>A Avg(A arr[], const unsigned int n)
{
	return (double)Sum(arr, n) / n;
}
template<typename M>M minValueIn(M arr[], const unsigned int n, int min)
{
	min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min ;
}
 template<typename MA> MA maxValueIn(MA arr[], const unsigned int n, int max)
 {
	 max = arr[0];
	 for (int i = 0; i < n; i++)
	 {
		 if (max < arr[i]) max = arr[i];
	 }
	 return max;
 }
 template<typename V> void Sort(V arr[], const unsigned int n)
 {
	 for (int i = 0; i < n; i++)
	 {

		 for (int j = n - 1; j > i; j--)
		 {
			 if (arr[j] < arr[j - 1])
			 {
				 int temp = arr[j];
				 arr[j] = arr[j - 1];
				 arr[j - 1] = temp;
			 }
		 }
	 }
	 for (int i = 0; i < n; i++)
	 {
		 cout << arr[i] << "\t";
	 }
	 cout << endl;
 }