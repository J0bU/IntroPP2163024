#include<bits/stdc++.h>
#include<stdio.h>
#include <iomanip>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main(){


     // Initializations 
    int n, m, c, d, matrix[10][10];
    int counter = 0;

    // Grab number of rows and colums of the matrix.
    cout << "\nEnter the number of rows and columns of the matrix \n\n" ;

    // Assign this values to m and n.
    cin >> m >> n;


    cout << "\nEnter the " <<m*n<< " elements of the matrix \n\n";

    for(c = 0; c < m; c++)   // to iterate the rows
    {
        for(d = 0; d < n; d++)   // to iterate the columns
        {
            cout << "Enter the position ["<<c<<"]["<<d<<"]: ";
            cin >> matrix[c][d];
            if(matrix[c][d] == 0)
            counter++;  // same as counter=counter +1
        }
    }

     // printing the matrix
    cout << "\n\nThe entered matrix is: \n\n";

    // t1: Create a new point time.
    using clk = high_resolution_clock;
    auto t1 = clk :: now();

    for(c = 0; c < m; c++)   // to iterate the rows
    {
        for(d = 0; d < n; d++)   // to iterate the columns
        {
            cout <<"\t"<< matrix[c][d];
        }
        cout <<"\n"; // to take the control to the next row 
    }

   // t2: Create a second point time.
    
    auto t2 = clk :: now();
    auto diff = duration_cast<microseconds>(t2-t1);

    // checking if the matrix is sparse or not
    if(counter > (m*n)/2)
        cout <<"\n\nThe entered matrix is a sparse matrix\n\n";
    else
        cout <<"\n\nThe entered matrix is not a sparse matrix\n\n";

    cout << "\n\tTime: " <<  diff.count();

    return 0;
}