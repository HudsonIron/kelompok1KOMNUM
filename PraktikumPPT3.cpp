

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;


double fungsi(int pilihan, double x) {
    switch (pilihan) {
        case 1: return pow(x, 3) - x - 2;
        case 2: return pow(x, 3) - 2*x - 5;
        case 3: return cos(x) - x;
        case 4: return pow(x, 2) - 4;
        case 5: return exp(x) - 3*x;
        case 6: return sin(x) - x/2.0;
        case 7: return pow(x, 4) - x - 10;
        default: return 0;
    }
}


string namaFungsi(int pilihan) {
    switch (pilihan) {
        case 1: return "f(x) = x^3 - x - 2";
        case 2: return "f(x) = x^3 - 2x - 5";
        case 3: return "f(x) = cos(x) - x";
        case 4: return "f(x) = x^2 - 4";
        case 5: return "f(x) = e^x - 3x";
        case 6: return "f(x) = sin(x) - x/2";
        case 7: return "f(x) = x^4 - x - 10";
        default: return "Tidak diketahui";
    }
}


void cetakGaris(char karakter = '-', int panjang = 75) {
    for (int i = 0; i < panjang; i++) cout << karakter;
    cout << endl;
}


void cetakHeaderTabel() {
    cetakGaris('=');
    cout << left
         << setw(5)  << "  i"
         << setw(14) << "  x0"
         << setw(14) << "  x1"
         << setw(14) << "  x2"
         << setw(14) << "  f(x2)"
         << setw(14) << "  |error|"
         << endl;
    cetakGaris('=');
}


void cetakBaris(int i, double x0, double x1, double x2, double fx2, double err) {
    cout << fixed << setprecision(8)
         << "  " << left << setw(3) << i
         << "  " << setw(12) << x0
         << "  " << setw(12) << x1
         << "  " << setw(12) << x2
         << "  " << setw(12) << fx2
         << "  " << setw(12) << err
         << endl;
}


void metodSecant(int pilFungsi, double x0, double x1,
                 double toleransi, int maxIterasi) {

    cout << endl;
    cetakGaris('=');
    cout << "  METODE SECANT - Pencarian Akar Persamaan" << endl;
    cetakGaris('=');
    cout << "  Fungsi     : " << namaFungsi(pilFungsi) << endl;
    cout << "  x0         : " << x0 << endl;
    cout << "  x1         : " << x1 << endl;
    cout << "  Toleransi  : " << toleransi << endl;
    cout << "  Max iterasi: " << maxIterasi << endl;
    cetakGaris();

   
    double fx0 = fungsi(pilFungsi, x0);
    double fx1 = fungsi(pilFungsi, x1);

    cout << "  f(x0) = " << fx0 << endl;
    cout << "  f(x1) = " << fx1 << endl;
    cetakGaris();

   
    cetakHeaderTabel();

    double x2, fx2, error;
    bool konvergen = false;

    for (int i = 1; i <= maxIterasi; i++) {

       
        double penyebut = fx1 - fx0;
        if (fabs(penyebut) < 1e-15) {
            cout << endl;
            cout << "  [!] GAGAL: Pembagi (f(x1) - f(x0)) mendekati nol." << endl;
            cout << "      Coba ubah nilai x0 dan x1." << endl;
            return;
        }

       
        x2  = x1 - fx1 * (x1 - x0) / penyebut;
        fx2 = fungsi(pilFungsi, x2);

       
        error = fabs(x2 - x1);

       
        cetakBaris(i, x0, x1, x2, fx2, error);

       
        if (error < toleransi) {
            konvergen = true;
            
            break;
        }

       
        x0  = x1;
        fx0 = fx1;
        x1  = x2;
        fx1 = fx2;
    }

  
    cetakGaris('=');
    if (konvergen) {
        cout << endl;
        cout << "  [OK] KONVERGEN! Akar ditemukan." << endl;
        cout << endl;
        cout << "  Akar persamaan  : x = " << fixed << setprecision(10) << x2 << endl;
        cout << "  Nilai f(akar)   : f(x) = " << scientific << setprecision(6) << fx2 << endl;
        cout << "  Error akhir     : " << error << endl;
        cout << endl;
    } else {
        cout << endl;
        cout << "  [!] Iterasi maksimum tercapai (" << maxIterasi << " iterasi)." << endl;
        cout << "      Hasil terakhir: x = " << fixed << setprecision(10) << x2 << endl;
        cout << "      Coba tambah iterasi atau ubah toleransi." << endl;
        cout << endl;
    }
    cetakGaris('=');
}


int main() {

    int pilFungsi;
    double x0, x1, toleransi;
    int maxIterasi;
    char ulang;

    do {
       
        cout << endl;
        cetakGaris('*');
        cout << "*                                                                         *" << endl;
        cout << "*          PROGRAM PENCARIAN AKAR PERSAMAAN - METODE SECANT              *" << endl;
        cout << "*                                                                         *" << endl;
        cetakGaris('*');

        
        cout << endl;
        cout << "  PILIH FUNGSI f(x):" << endl;
        cetakGaris();
        cout << "  1. f(x) = x^3 - x - 2" << endl;
        cout << "  2. f(x) = x^3 - 2x - 5" << endl;
        cout << "  3. f(x) = cos(x) - x" << endl;
        cout << "  4. f(x) = x^2 - 4" << endl;
        cout << "  5. f(x) = e^x - 3x" << endl;
        cout << "  6. f(x) = sin(x) - x/2" << endl;
        cout << "  7. f(x) = x^4 - x - 10" << endl;
        cetakGaris();

        cout << "  Masukkan pilihan (1-7): ";
        cin >> pilFungsi;

        
        while (pilFungsi < 1 || pilFungsi > 7) {
            cout << "  Pilihan tidak valid! Masukkan angka 1-7: ";
            cin >> pilFungsi;
        }

        
        cout << endl;
        cout << "  INPUT PARAMETER:" << endl;
        cetakGaris();

        cout << "  Masukkan x0 (tebakan pertama) : ";
        cin >> x0;

        cout << "  Masukkan x1 (tebakan kedua)   : ";
        cin >> x1;

       
        while (x0 == x1) {
            cout << "  [!] x0 dan x1 tidak boleh sama! Masukkan x1: ";
            cin >> x1;
        }

        cout << "  Masukkan toleransi (contoh: 0.0001) : ";
        cin >> toleransi;

       
        while (toleransi <= 0) {
            cout << "  [!] Toleransi harus positif! Masukkan ulang: ";
            cin >> toleransi;
        }

        cout << "  Masukkan iterasi maksimum (contoh: 50): ";
        cin >> maxIterasi;

        
        while (maxIterasi <= 0) {
            cout << "  [!] Iterasi harus > 0! Masukkan ulang: ";
            cin >> maxIterasi;
        }

        
        metodSecant(pilFungsi, x0, x1, toleransi, maxIterasi);

       
        cout << "  Hitung lagi? (y/t): ";
        cin >> ulang;
        cout << endl;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "  Program selesai. Terima kasih!" << endl;
    cout << endl;

    return 0;
}
