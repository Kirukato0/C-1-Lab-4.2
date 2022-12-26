#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
#include <random>

int* quantityRet(int** a, int N, int M)
{
    int pos = 0, neg = 0;
    for (int i = 0; i < N; i++)
    {
        if (i > 2)
        {
            for (int j = 0; j < M; j++)
            {
                if (a[i][j] < 0)
                    neg += 1;
                else pos += 1;
            }
        }
    }
    std::cout << "\n";
    int* arrays;
    arrays = new int[2];
    arrays[0] = neg;
    arrays[1] = pos;
    return arrays;
}

int main()
{
    srand(time(0));
    const int N = 6, M = 5;
    int** a;
    a = new int* [N];
    for (int i = 0; i < N; i++)
    {
        a[i] = new int[M];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = rand() % 21 - 10;
            std::cout << a[i][j] << "\t";
        }
        std::cout << "\n";
    }
    int* arrays;
    arrays = new int[2];
    arrays = quantityRet(a, N, M);
    std::cout << "Quantity of negative elements= " << arrays[0] << "\n";
    std::cout << "Quantity of positive elements= " << arrays[1] << "\n";
    return 0;
}