# Dynamic-Echelon C++


## Sample C++ 14
```c++
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
    // Mat compute_echelon(Mat &a, bool print_steps = false,bool round_off_zeros= true)
    Mat b =compute_echelon(a, true, true);
    std::cout<<b;
    return 0;
}



```

```c++

****** Matrix Echelon (Gaussian Elimination) ******
****** Round off Zero : true ******
****** Inputted Matrix  ******

|  9 10 11 |
| 12 13 14 |
| 15 16 17 |


|  9        10        11 |
|  0   -0.3333   -0.6667 |
| 15        16        17 |


| 9        10        11 |
| 0   -0.3333   -0.6667 |
| 0   -0.6667    -1.333 |


| 9        10          11 |
| 0   -0.3333     -0.6667 |
| 0         0   3.553e-15 |


****** Round off Zero : true ******
***** Final Echelon Form *****

| 0        10        11 |
| 0   -0.3333   -0.6667 |
| 0         0         0 |

| 0        10        11 |
| 0   -0.3333   -0.6667 |
| 0         0         0 |

Process finished with exit code 0

```
