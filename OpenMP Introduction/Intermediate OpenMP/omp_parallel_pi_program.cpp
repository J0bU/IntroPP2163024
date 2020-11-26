#include <bits/stdc++.h>
#include <omp.h>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

static long num_steps = 100000;
int A[100000];
double step;

int main(){

    int i;
    double x, pi, sum = 0.0;
    step = 1.0 / (double)num_steps;

    using clk = high_resolution_clock;
    auto t1 = clk :: now();

    #pragma omp parallel 
    {
        // Parallel code here!
        int thread = omp_get_thread_num(); 
        cout << "Thread number: "<< thread << "\n";
        #pragma omp for
            for (int i=0;i<num_steps;i++){
                x = (i + 0.5) * step;
                sum = sum + 4.0 / (1.0 + x * x);
                // A[i] = thread;
            }

    }

    pi = step * sum;

    auto t2 = clk :: now();
    auto diff = duration_cast<microseconds>(t2-t1);

    // for(int i = 0; i<4; i++){
    //     cout << "A["<<i<<"]: "<<A[i]<<"\n";
    // }
    cout << pi << "\n";
    cout <<"Parallel time: "<< diff.count();
    return 0;
}