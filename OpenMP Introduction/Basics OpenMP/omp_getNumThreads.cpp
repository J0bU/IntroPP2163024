#include <bits/stdc++.h>
#include <omp.h>

using namespace std;


int main(){
    
    int n_thread, n_threads;
    #pragma omp parallel private(n_thread, n_threads)
    {
        n_thread = omp_get_thread_num();
        n_threads = omp_get_num_threads();
        cout << "This is the thread: "<< n_thread << " out of " << n_threads << " threads \n";
    }

    return 0;
}