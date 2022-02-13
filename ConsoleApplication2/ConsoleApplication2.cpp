#include<iostream>

using namespace std;

void Show(int** arr, int m, int n)//функция вывода матрицы обычной
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Sum_Row(int ** arr, int m, int n){//функция вывода суммы четных строк матрицы, подсчет последней строки, подсчет суммы каждой парной строки
    int i, j, counter = -1, sum = 0;
    cout << "\nFinding Sum of each row:\n\n";
// нахождение суммы строки
for (i = 0; i < m; ++i) {
    for (j = 0; j < n; ++j) {
        sum = sum + arr[i][j];
    }
        //вывод парных строк
    if (i % 2 == 0 && i > i - 2) {
        cout << "Sum of the row " << i << " = " << sum << endl;
    }
    sum = 0;   // обнуление счетчика суммы
    counter++; // счетчик последней строки
}

if (counter % 2 == 0) { // подсчет последней строки. Если строка не делится на 2, отнимается единица, если делится - выводится последнее значение
    cout << "\n\n" << counter << "  Is last pair line" << endl;
}
else cout << "\n\n" << counter - 1 << " Is the last pair line" << endl;

}

int main()
{
    int i, j, m, n, * u, v;
    srand(time(NULL)); 
    cout << "Amounts of rows m = "; // ввод кол-ва рядков
    cin >> m;
    cout << "Amount of columns n = "; // ввод кол-во столбцов
    cin >> n;
    int** arr = new int* [m];
    for (i = 0; i < m; i++)
        arr[i] = new int[n];

    cout << "1) Random numbers \n2) Input by hands" << endl;
    cin >> v; // При вводе единицы рандомизированно вводит значения в матрицу
    if (v == 1)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0, u = &arr[i][0]; j < n; j++, u++)
            {
                *u = rand() % (100 - 0) + 0;
            }
        }
    }
    else // ввод значений матрицы вручную 
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0, u = &arr[i][0]; j < n; j++, u++)
            {
                cout << "arr[" << i << "]" << "[" << j << "] = ";
                cin >> *u;
            }
        }
    }
    cout << "Normal matrix: " << endl;
    
    Show(arr, m, n); 
    Sum_Row(arr, m, n);

    return 0; 
}