#include <iostream>
#include <unistd.h>

#define ROW 1
#define COL 1

//顺时针打印矩阵
void printMatrixInCircle (int *matrix, size_t row, size_t col, int start);

void printMatrixForClockwise(int *matrix, size_t row, size_t col)
{
    if(matrix == NULL)
        return;

    int i = 0;
    for(; i * 2 < row && i * 2 < col; i++)
    {
        printMatrixInCircle(matrix, row, col, i);
    }
    std::cout<<std::endl;
}

void printMatrixInCircle (int *matrix, size_t row, size_t col, int start)
{
    if(matrix == NULL || start < 0 )
        return;

    bool flag = false;
    int i = start;
    //从左到右
    for(; i < col-start; i++)
    {
        std::cout<<matrix[start*col+i]<<" ";
        fflush(stdout);
    }
    //从上到下
    i = start +1;
    for(;i < row-start; i++)
    {
        std::cout<<matrix[i*col+col-1-start]<<" ";
        flag = true;
        fflush(stdout);
    }
    if(flag)
        flag = false;
    else
        return;

    //从右到左
    i = col - 1 - start - 1;
    for(; i >= start; i--)
    {
        std::cout<<matrix[(row-1-start)*col+i]<<" ";
        flag = true;
        fflush(stdout);
    }

    if(flag)
        flag = false;
    else
        return;

    //从下到上
    i = row - 1 - start - 1;
    for(; i > start; i--)
    {
        std::cout<<matrix[i*col+start]<<" ";
        fflush(stdout);
    }

}

int main()
{
    int matrix[ROW][COL];
    int count = 1;
    int i = 0;
    for(; i < ROW; i++)
    {
        int j = 0;
        for(;j < COL; j++)
        {
            matrix[i][j] = count++;
        }
    }

    printMatrixForClockwise ((int*)matrix, ROW, COL);
    //std::cout<<1<<std::endl;


    return 0;
}
