#include <stdio.h>

int getMaiorNumberOfMatriz(int size, int list[][size])
{
    int maior = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (list[i][j] > maior)
            {
                maior = list[i][j];
            }
        }
    }
    return maior;
}
int foundAllCaminhos(int list[], int size)
{
    int found = 1;
    for (int i = 0; i < size; i++)
    {
        if (list[i] == 0)
            found = 0;
    }
    return found;
}
void getVizinho(int size, int list[][size], int start)
{
    int hasProx[size];
    for (int i = 0; i < size; i++)
    {
        hasProx[i] = 0;
    }

    int caminho[size];
    int menorDist;
    int i = start;
    int j = 0;

    int count = -1;

    int found = 0;

    while (foundAllCaminhos(hasProx, size) != 1)
    {
        menorDist = 1 + getMaiorNumberOfMatriz(size, list);

        count++;
        while (j != size)
        {
            if ((i != j) && (hasProx[j] == 0) && (list[i][j] < menorDist))
            {
                menorDist = list[i][j];

                caminho[count] = menorDist;
                found = j;
            }

            j++;
        }
        if (count == size - 2)
            hasProx[start] = 0;
        hasProx[i] = 1;
        i = found;
        hasProx[found] = 1;
        j = 0;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", caminho[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{

    int distanciaGrafoA[5][5] = {
        {0, 7, 6, 10, 7},
        {7, 0, 7, 10, 10},
        {6, 7, 0, 5, 9},
        {10, 10, 5, 0, 6},
        {7, 10, 9, 6, 0}

    };

    int distanciaGrafoB[6][6] = {
        {0, 2, 6, (6 + 2), 1, (1 + 3)},
        {2, 0, 5, 7, (8 + 5), (7 + 4)},
        {6, 5, 0, 2, 8, (8 + 3)},
        {(6 + 2), 7, 2, 0, (4 + 3), 4},
        {1, (8 + 5), 8, (4 + 3), 0, 3},
        {(4 + 7 + 2), (7 + 4), (8 + 3), 4, 3, 0}

    };

    for (int i = 0; i < 5; i++)
    {
        getVizinho(5, distanciaGrafoA, i);
    }
    printf("///////////////////\n");
    for (int i = 0; i < 6; i++)
    {
        getVizinho(6, distanciaGrafoB, i);
    }

    return 0;
}
