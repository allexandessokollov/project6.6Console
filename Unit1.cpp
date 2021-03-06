//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

const int MAX_MATRIX_SIZE = 7;
int const MAX_RANDOM_VALUE = 100;
int const MIN_RANDOM_VALUE = -100;

void fillArrKeyboard(int *arr[], int nSize, int mSize);
void fillArrRandomly(int *arr[], int nSize, int mSize);
bool alreadyExist(int arr[], int countOfElemToCheck, int value);

int main()
{
        int nValue, mValue, userChoice;

        do
        {
            printf("Enter matrix size N x M\nN and M should be more than 0 and less than 7\n!");

            scanf("%d %d", &nValue, &mValue);

        } while (nValue < 0 ||
         mValue < 0 ||
         nValue > MAX_MATRIX_SIZE ||
         mValue > MAX_MATRIX_SIZE);

        int **arr = new int*[nValue];
        for(int i = 0; i < nValue; i++)
        {
            arr[i] = new int[mValue];
        }

        printf("Enter 1 to fill array using keyboard and 2 for random\n");
        scanf("%d", &userChoice);

        switch(userChoice)
        {
            case 1:
                fillArrKeyboard(arr, nValue, mValue);
                break;
            case 2:
                fillArrRandomly(arr, nValue, mValue);
                break;
        }

        for(int i = 0; i < nValue; i++)
        {
            for(int j = 0; j < mValue; j++)
            {
                printf("%d  ", arr[i][j]);
            }

            printf("\n");
        }

        printf("\n\n");

        int tmpArrSize =  (nValue) * (mValue);
        int *tmpArr = new int[tmpArrSize];
 
        int counter = 0;

        for(int i = 0; i < nValue; i++)
        {
            for(int j = 0; j < mValue; j++)
            {
                int temp = arr[i][j];

                if(alreadyExist(tmpArr, counter, temp))
                {
                    continue;
                }
                else
                {
                    tmpArr[counter] = temp;
                    counter++;
                }
            }
        }

        printf("\n\nanswer is: %d \n\n", counter);

        puts("\n\n\nPress any key ... ");
        getch();
        getch();

        for(int i = 0; i < mValue; i++)
        {
            delete []arr[i];
        }
        delete []arr;
        delete []tmpArr;

        return 0;
}

void fillArrKeyboard(int *arr[], int nSize, int mSize)
{
    for(int i = 0; i < nSize; i++)
    {
        for(int j = 0; j < mSize; j++)
        {
            printf("Enter element %d %d \n", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

}


void fillArrRandomly(int *arr[], int nSize, int mSize)
{
    for(int i = 0; i < nSize; i++)
    {
        for(int j = 0; j < mSize; j++)
        {
            arr[i][j] = random(MAX_RANDOM_VALUE - MIN_RANDOM_VALUE) + MIN_RANDOM_VALUE;
        }
    }
}


bool alreadyExist(int arr[], int countOfElemToCheck, int value)
{
       for(int i = 0; i < countOfElemToCheck; i++)
       {
            if(arr[i] == value)
            {
                return true;
            }
       }

       return false;
}


