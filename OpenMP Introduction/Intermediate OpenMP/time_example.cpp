#include <chrono>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void delay_function(int count) {

    for (int i = 0; i < count; i++)
    {
        cout << i << "\n";
    }
    
};

int main(){

    using clk = chrono::high_resolution_clock;
    auto t1 = clk::now();

    int count = 100;

    delay_function(count);


    auto t2 = clk::now();
    auto diff = duration_cast<microseconds>(t2-t1);

    cout << "Time= "<<diff.count()<<" microseconds" << "\n";
    return 0;
}