#include <stdio.h>
#include <string.h>
int arrLeapyear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int arrNotLeapyear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int year, fday, month;
    scanf("%d %d %d", &year, &fday, &month);
    if (fday == 0)
    {
        fday = 7;
    }
    // find how many days before the month
    int totalD = 0, flag;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0 && year % 100 == 0)
    {
        for (int i = 0; i < month - 1; i++)
        {
            totalD = totalD + arrLeapyear[i];
            flag = 1;
        }
    }
    else
    {
        for (int i = 0; i < month - 1; i++)
        {
            totalD = totalD + arrNotLeapyear[i];
            flag = 0;
        }
    }
    // find the exact day after the fday
    while (totalD - 7 > 0)
    {
        totalD = totalD - 7;
    }
    int exactD;
    if (fday + totalD - 7 < 0)
    {
        exactD = fday + totalD;
    }
    else
    {
        exactD = fday + totalD - 7;
    }
    int dateArr[6][7];
    memset(dateArr, '\0', sizeof(dateArr));
    int count = 1;
    for (int i = 0; i < 6; i++)
    {
        if (flag == 1 && count == arrLeapyear[month - 1] + 1)
        {
            break;
        }
        if (flag == 0 && count == arrNotLeapyear[month - 1] + 1)
        {
            break;
        }
        for (int j = 0; j < 7; j++)
        {
            if (i == 0 && j < exactD)
            {
                continue;
            }
            else
            {
                dateArr[i][j] = count;
                count++;
            }
            if (flag == 1 && count == arrLeapyear[month - 1] + 1)
            {
                break;
            }
            if (flag == 0 && count == arrNotLeapyear[month - 1] + 1)
            {
                break;
            }
        }
    }
    switch (month)
    {
    case 1:
        printf("January %d\n", year);
        break;
    case 2:
        printf("February %d\n", year);
        break;
    case 3:
        printf("March %d\n", year);
        break;
    case 4:
        printf("April %d\n", year);
        break;
    case 5:
        printf("May %d\n", year);
        break;
    case 6:
        printf("June %d\n", year);
        break;
    case 7:
        printf("July %d\n", year);
        break;
    case 8:
        printf("August %d\n", year);
        break;
    case 9:
        printf("September %d\n", year);
        break;
    case 10:
        printf("October %d\n", year);
        break;
    case 11:
        printf("November %d\n", year);
        break;
    case 12:
        printf("December %d\n", year);
        break;
    }
    char *p[] = {
        "Sun",
        "Mon",
        "Tue",
        "Wed",
        "Thu",
        "Fri",
        "Sat"};
    printf("%8s%8s%8s%8s%8s%8s%8s\n", p[0], p[1], p[2], p[3], p[4], p[5], p[6]);
    char *x = " ";
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (dateArr[i][j] == '\0')
            {
                printf("%8s", x);
            }
            else
            {
                printf("%8d", dateArr[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
