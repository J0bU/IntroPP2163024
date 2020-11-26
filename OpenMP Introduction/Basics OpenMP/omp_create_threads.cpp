#include <bits/stdc++.h>
#include <omp.h>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){


    using clk = high_resolution_clock;

    double A[100];

    auto t1 = clk :: now();
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        #pragma omp for
        for(int i=0;i<100;i++){
            A[i] = ID;
        }
        // pooh(ID, A);
    }

    auto t2 = clk :: now();
    auto diff = duration_cast<microseconds>(t2-t1);

    for(int i=0;i<100;i++){
        cout << "A["<<i<<"]: "<<A[i]<<"\n";
    }
    cout << "All done\n";
    cout << "Time: "<<diff.count() << "\n";
    return 0;
}