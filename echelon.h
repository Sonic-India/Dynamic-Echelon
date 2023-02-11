//
// Created by Onkar Ingale on 11-02-2023.
//

#ifndef DYNAMIC_ECHELON_ECHELON_H
#define DYNAMIC_ECHELON_ECHELON_H

#include "Matrix.h"

bool is_zero(double num)
{
    std::string temp =std::to_string(num);
    std::size_t count=0;
    for (int i = 2; i < temp.length(); ++i)
    {
        if (temp[i] != '0')
            break;
        ++count;
    }
    if ((temp.length()-2) ==count)
        return true;
    return false;
}


Mat compute_echelon(Mat &a, bool print_steps = false,bool round_off_zeros= true)
{

    long unsigned int m = a.rows(), n = a.cols();

    long int i, j, r, k, c, d, x;
    long double temp;


    Mat b = a;


    if (print_steps)
    {
        std::cout << "\n****** Matrix Echelon (Gaussian Elimination) ******";
        if (round_off_zeros)
            std::cout << "\n****** Round off Zero : true ******";
        std::cout << "\n****** Inputted Matrix  ******\n";
        std::cout << b<<"\n";
    }


    for (c = 0; c < (m - 1); c++)
    {
        if (b[c][c] == 0)
        {
            for (d = 0; d < (m - c - 1); d++)
            {
                if (b[c + d + 1][c] != 0)
                {
                    for (j = 0; j < n; j++)
                    {
                        temp = b[c + d + 1][j];
                        b[c + d + 1][j] = b[c][j];
                        b[c][j] = temp;
                    }
                } else
                    continue;
                break;
            }
        }

        for (r = 0; r < m; r++)
        {
            for (k = 0; k < n; k++)
            {
                a[r][k] = b[r][k];
            }
        }

        for (d = 0; d < (m - c - 1); d++)
        {
            if (a[c + d + 1][c] != 0)
            {
                for (j = 0; j < n; j++)
                {
                    a[c + d + 1][j] = (b[c + d + 1][j]) - ((b[c + d + 1][c] / b[c][c]) * b[c][j]);
                }
            }

            for (r = 0; r < m; r++)
            {
                for (k = 0; k < n; k++)
                {
                    b[r][k] = a[r][k];
                }
            }

            if (print_steps)
            {
                std::cout << b<<"\n";
            }

        }
    }

    for (int i1 = 0; i1 < b.rows(); ++i1)
    {
        for (int j1 = 0; j1 < b.cols(); ++j1)
        {
            if (is_zero(b[i1][j1]))
            {
                b[i1][j1] = 0;
            }
        }
    }

    //Final Printing of Matrix
    if (print_steps)
    {
        if (round_off_zeros)
            std::cout << "\n****** Round off Zero : true ******";
        std::cout << "\n***** Final Echelon Form *****\n";
        std::cout << b;
    }



    return b;
}


#endif //DYNAMIC_ECHELON_ECHELON_H
