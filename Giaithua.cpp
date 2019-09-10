#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

double factorial(const int& n);     // Tính giai thừa không dùng đệ quy
double factorialRecursive(int n);   // Tính giai thừa dùng đệ quy

int main(){
    // Bắt đầu
    auto start = steady_clock::now();

    cout << "50! = " << setprecision(65) << factorial(50) << endl;
    // Kết thúc
    auto end = steady_clock::now();
    duration<double, nano> elapsed_1 = end - start;
    cout << "time: " << elapsed_1.count() << "ns" << endl;
    return 0;
}

/**
    +> Tính giai thừa không dùng đệ quy
    +> Time: 999.000ns
    +> Result: 30414093201713375576366966406747986832057064836514787179557289984
*/

double factorial(const int& n){
    double result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}
/**
    +> Tính giai thừa dùng đệ quy
    +> Time: 1.007.000ns
    +> Result: 30414093201713375576366966406747986832057064836514787179557289984
*/
double factorialRecursive(int n){
    if(n <= 1){
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

