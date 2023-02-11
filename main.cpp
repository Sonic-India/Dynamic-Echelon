#include <iostream>
#include "Echelon.h"

int main()
{
    Mat a(3,3);//number of Rows,number of size
    int temp =9;
    // Writing Matrix
    for (int i = 0; i < a.rows(); ++i)
    {
        for (int j = 0; j < a.cols(); ++j)
        {
            a[i][j] = temp++;
        }
    }
    Mat b =compute_echelon(a, true, true);
    std::cout<<b;
    return 0;
}
