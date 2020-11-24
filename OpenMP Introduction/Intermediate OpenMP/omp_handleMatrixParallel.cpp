#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

int main(){

    // Serial code
    int A[100];

    //Parallel code
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        // Add value into A
        cout << "This is the thread number: "<<omp_get_thread_num() << "\n";
        A[omp_get_thread_num()] = omp_get_thread_num();

    }

    for(int i = 0; i<4; i++){
        cout << "A["<<i<<"]: "<<A[i];
    }

    return 0;
}