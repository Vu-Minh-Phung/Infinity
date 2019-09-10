#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long Fibonacci(const int& n);
long long FibonacciRecursive(int n);

int main()
{
    //Bát đầu
    auto start = steady_clock::now();

    cout << "f50" << " = " << Fibonacci(50) << endl;    /** Thay thế */

    //Kết thúc
    auto end = steady_clock::now();
    duration<double, ratio<1, 1000>> time = end - start;

    cout << "time: " << time.count() << "ms" << endl;
    return 0;
}

/**
    +> Fibanacci không dùng đệ quy
    +> Time: 2ms
    +> Result: 20365011074
*/
long long Fibonacci(const int& n){
    long long f1 = 1,
        f2 = 1;
    for(int i = 2; i <= n; i++){
        long long temp = f1;
        f1 = f1 + f2;
        f2 = temp;
    }
    return f1;
}
/**
    +> Fibanacci dùng đệ quy
    +> Time: 119.838ms
    +> Result: 20365011074
*/
long long FibonacciRecursive(int n){
    if( n <= 1 ){
        return 1;
    }
    return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}
