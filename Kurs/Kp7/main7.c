
#include <stdio.h>
#include <malloc.h>
int main()
{
    unsigned n1, m1, n2, m2;
    scanf("%i %i %i %i", &n1, &m1, &n2, &m2);
    if (m1 != n2)
    {
        printf("Multiplication is impossible\n");
    }
    else
    {
        int* CIP1 = (int*)malloc(sizeof(int) * n1), *PI1 = (int*)malloc(sizeof(int)), *YE1 = (int*)malloc(sizeof(int)), 
        real_size_of_PI1 = 0, memory_size_of_PI1 = 1, element;
        for (int i = 0; i < n1; i++)
        {
            CIP1[i] = -1;
            for (int j = 0; j < m1; j++)
            {
                scanf("%d", &element);
                if (element != 0)
                {
                    if (CIP1[i] == -1)
                    {
                        CIP1[i] = real_size_of_PI1;
                    }
                    if (real_size_of_PI1 == memory_size_of_PI1)
                    {
                        memory_size_of_PI1 *= 2;
                        PI1 = (int*)realloc(PI1, sizeof(int) * memory_size_of_PI1);
                        YE1 = (int*)realloc(YE1, sizeof(int) * memory_size_of_PI1);  
                    }
                    PI1[real_size_of_PI1] = j;
                    YE1[real_size_of_PI1] = element;
                    real_size_of_PI1++;
                }
            }
            if (real_size_of_PI1 == memory_size_of_PI1)
            {
                memory_size_of_PI1 *= 2;
                PI1 = (int*)realloc(PI1, sizeof(int) * memory_size_of_PI1);
                YE1 = (int*)realloc(YE1, sizeof(int) * memory_size_of_PI1);
            }
            PI1[real_size_of_PI1] = -1;
            real_size_of_PI1++;
        }
        if (!real_size_of_PI1)
        {
            PI1[0] = -1;
            real_size_of_PI1++;
        }
        int** second_matrix = (int**)malloc(sizeof(int*) * m2);
        for (int i = 0; i < m2; i++)
        {
            second_matrix[i] = (int*)malloc(sizeof(int) * n2);
        }
        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                scanf("%d", &second_matrix[j][i]);
            }
        }
        int* CIP2 = (int*)malloc(sizeof(int) * m2), * PI2 = (int*)malloc(sizeof(int)), * YE2 = (int*)malloc(sizeof(int)),
        real_size_of_PI2 = 0, memory_size_of_PI2 = 1;
        for (int i = 0; i < m2; i++)
        {
            CIP2[i] = -1;
            for (int j = 0; j < n2; j++)
            {
                if (second_matrix[i][j] != 0)
                {
                    if (CIP2[i] == -1)
                    {
                        CIP2[i] = real_size_of_PI2;
                    }
                    if (real_size_of_PI2 == memory_size_of_PI2)
                    {
                        memory_size_of_PI2 *= 2;
                        PI2 = (int*)realloc(PI2, sizeof(int) * memory_size_of_PI2);
                        YE2 = (int*)realloc(YE2, sizeof(int) * memory_size_of_PI2);
                    }
                    PI2[real_size_of_PI2] = j;
                    YE2[real_size_of_PI2] = second_matrix[i][j];
                    real_size_of_PI2++;
                }
            }
            if (real_size_of_PI2 == memory_size_of_PI2)
            {
                memory_size_of_PI2 *= 2;
                PI2 = (int*)realloc(PI2, sizeof(int) * memory_size_of_PI2);
                YE2 = (int*)realloc(YE2, sizeof(int) * memory_size_of_PI2);
            }
            PI2[real_size_of_PI2] = -1;
            real_size_of_PI2++;
            free(second_matrix[i]);
        }
        if (!real_size_of_PI2)
        {
            PI2[0] = -1;
            real_size_of_PI2++;
        }
        free(second_matrix);
        bool diagonal = true;
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                if ((CIP1[i] == -1) || (CIP2[j] == -1))
                {
                    printf("%d ", 0);
                }
                else
                {
                    unsigned counter1 = CIP1[i], counter2 = CIP2[j];
                    int S = 0;
                    while ((PI1[counter1] != -1) && (PI2[counter2] != -1))
                    {
                        if (PI1[counter1] == PI2[counter2])
                        {
                            S += YE1[counter1] * YE2[counter2];
                            counter1++;
                        }
                        else if (PI1[counter1] < PI2[counter2])
                        {
                            counter1++;
                        }
                        else
                        {
                            counter2++;
                        }
                    }
                    if ((diagonal) && (S != 0) && (i != j))
                    {
                        diagonal = false;
                    }
                    printf("%d ", S);
                }
            }  
            printf("\n");
        }
        if ((n1 != m2) || (!diagonal))
        {
            printf("Matrix isn't diagonal\n");
        }
        else
        {
            printf("Matrix is diagonal\n");
        }
        free(CIP1);
        free(CIP2);
        free(PI1);
        free(PI2);
        free(YE1);
        free(YE2);
    }
    return 0;
}

