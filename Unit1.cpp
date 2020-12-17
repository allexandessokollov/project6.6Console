//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void fillArrKeyboard(int *arr[], int nSize, int mSize);
void fillArrRandomly(int *arr[], int nSize, int mSize);
bool alreadyExist(int arr[], int arrSize, int value);

const int MAX_MATRIX_SIZE = 7;
int main()
{

        int nValue, mValue, userChoice, tmpArrSize, counter = 0;

        printf("Enter matrix size N x M\n");
        scanf("%d %d", &nValue, &mValue);

        while (nValue < 0 || mValue < 0)
        {
            printf("N and M should be more than 0. Enter again");
            scanf("%d %d", nValue, mValue);
        }
        while(nValue > MAX_MATRIX_SIZE || mValue > MAX_MATRIX_SIZE)
        {
            printf("\nmaximum size is 7 x 7\n");

            nValue =  MAX_MATRIX_SIZE;
            mValue =  MAX_MATRIX_SIZE;

        }


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

        tmpArrSize =  (nValue) * (mValue);
        int *tmpArr = new int[tmpArrSize];

        int toInitialize = -99999;
        for(int j = 0; j < mValue; j++)
        {
            tmpArr[j] = toInitialize;
        }



        for(int i = 0; i < nValue; i++)
        {
            for(int j = 0; j < mValue; j++)
            {
                int temp = arr[i][j];

                if(alreadyExist(tmpArr, tmpArrSize, temp))
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
    


        printf("\n\npress any int number to close");
        int close;
        scanf("%d", &close);


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

    const int forRandomCorrection = -25,
    forRandom = 50;
    for(int i = 0; i < nSize; i++)
    {
        for(int j = 0; j < mSize; j++)
        {
            arr[i][j] = random(forRandom) + forRandomCorrection;
        }
    }
}


bool alreadyExist(int arr[], int arrSize, int value)
{
       for(int i = 0; i < arrSize; i++)
       {
            if(arr[i] == value)
            {
                return true;
            }
       }
       
       return false;
}


