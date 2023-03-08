﻿// 結構.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <stdio.h>
#include<stdlib.h>
#define SIZE 4
#define STU 10
void sort(const char** name, int a[][SIZE], int size);
void swap(int* e1Ptr, int* e2Ptr);
void min(int grades[][SIZE], int pupils, int tests);
void max(int grades[][SIZE], int pupils, int tests);
int main(void)
{
    struct student
    {
        char name[STU];
        int stu_id;
        float math;
        float computer;
        float average;
    };
    typedef struct student STUDET;
    STUDET stu, stu_class[STU] = { {"Ian",2,98,72,0},
                               {"Amy",3,76,32,0},
                               {"Max" ,6,98,67,0},
                               {"Dan" ,7,89,32,0},
                               {"Tim" ,8,98,55,0},
                               {"Tony" ,9,89,32,0},
                               {"Terry" ,10,98,65,0},
                               {"Hank" ,11,99,32,0},
                               {"Jim" ,12,98,71,0},
                               {"John",13,76,91,0} };
    int result = 0, i, j;
    

    puts("Data items in original order:");
    for (j = 0; j < 10; j++)
    {
        stu_class[j].average = (stu_class[j].math + stu_class[j].computer) / 2;
    }

    for (j = 0; j < STU; j++)
    {
        printf("%30s", stu_class[j].name);
        printf(" %d", stu_class[j].stu_id);
        printf(" %.2f", stu_class[j].math);
        printf(" %.2f", stu_class[j].computer);
        printf(" %.2f", stu_class[j].average);
        printf("\n");
    }
    /*sort(name, a, stu);
    puts("\nData items in ascending order");

    for (j = 0; j < 10; j++)
    {
        printf("[%d]", j + 1);
        for (i = 0; i < SIZE; ++i) {
            printf("%4d", a[j][i]);
        }
        printf("   %s", &*name[j]);
        printf("\n");
    }
    min(a, stu, SIZE);
    printf("last student name is:%s", &*name[9]);
    max(a, stu, SIZE);
    printf("frist student name is:%s", &*name[0]);*/
}


void sort(const char** name, int a[][SIZE], int size)
{
    const char* ptr;
    int hold, pass, i;
    for (pass = 1; pass < size; ++pass) {
        for (i = 0; i < size - pass; ++i) {
            if (a[i][3] < a[i + 1][3]) {
                ptr = name[i];
                name[i] = name[i + 1];
                name[i + 1] = ptr;
                swap(&a[i][0], &a[i + 1][0]);
                swap(&a[i][1], &a[i + 1][1]);
                swap(&a[i][2], &a[i + 1][2]);
                swap(&a[i][3], &a[i + 1][3]);

            }
        }
    }

}

void swap(int* e1Ptr, int* e2Ptr)
{
    int hold;
    hold = *e1Ptr;
    *e1Ptr = *e2Ptr;
    *e2Ptr = hold;
}
void min(int grades[][SIZE], int pupils, int tests)
{
    int lowgrade = 100;
    int lowst = 0;
    for (int i = 0; i < pupils; i++)
    {
        for (int j = 0; j < tests; ++j)
        {
            if (grades[i][SIZE - 1] < lowgrade)
            {
                lowgrade = grades[i][SIZE - 1];
                lowst = grades[i][0];
            }
        }
    }
    printf("\n\nlow st id is:%d", lowst);
    printf("\nLowest grade:%d\n", lowgrade);
}
void max(int grades[][SIZE], int pupils, int tests)
{
    int highgrade = 0;
    int highst = 0;
    for (int i = 0; i < pupils; i++)
    {
        for (int j = 0; j < tests; ++j)
        {
            if (grades[i][SIZE - 1] > highgrade)
            {
                highgrade = grades[i][SIZE - 1];
                highst = grades[i][0];
            }
        }
    }
    printf("\n\nhigh st id is:%d", highst);
    printf("\nHighest grade:%d\n", highgrade);
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
