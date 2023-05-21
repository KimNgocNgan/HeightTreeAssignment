// Khai báo các thư viện cần dùng
#include <cstdlib> // Thư viện sử dụng hàm rand() để tạo số nguyên ngẫu nhiên
#include <fstream> // Thư viện sử dụng nhập xuất file dữ liệu từ các tệp tin
#include <chrono> // Thư viện sử dụng để tạo số ngẫu nhiên với phân phối đồng đều
#include <random> // Thư viện sử dụng để tạo số ngẫu nhiên với phân phối đồng đều
#include <unordered_set> // Thư viện sử dụng để lưu danh sách các số nguyên không trùng nhau

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

int main() {  
    uniform_int_distribution<int> randomN(990000, 1000000); 
    uniform_int_distribution<int> randomNumber(10000, 10000000); 
    ofstream fo("logN_and_145logN.txt");
    for (int i = 1; i <= 10; i++) {
        string name = "Data" + to_string(i) + ".inp"; // Tạo 10 file input 
        ofstream file(name);
        int N = randomN(rd); 
        file << N <<'\n';
        unordered_set<int> uniqueNumbers;
        while (uniqueNumbers.size() < N) {
            uniqueNumbers.insert(randomNumber(rd));
        }
        for (const int& num : uniqueNumbers) {
            file << num << ' ';
        }
        fo << log2(N) << ' ' << 1.45*log2(N) << endl;
        file.close();
    }
    return 0;
}