#include <iostream>
const float phi = 3.14;
using namespace std;

int main()
{
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|   Program Menghitung Volume dan Luas Permukaan Bangun   |" << endl;
    cout << "|---------------------------------------------------------|" << endl;

    int pilihan, a, b, c, d;
    float volume, luas;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << endl;
        cout << "|----------------------------|" << endl;
        cout << "|         Pilih Menu         |" << endl;
        cout << "|----------------------------|" << endl;
        cout << "| 1 | Kubus                  |" << endl;
        cout << "| 2 | Balok                  |" << endl;
        cout << "| 3 | Bola                   |" << endl;
        cout << "| 4 | Limas Segi Empat       |" << endl;
        cout << "| 5 | Tabung                 |" << endl;
        cout << "| 6 | Kerucut                |" << endl;
        cout << "| 7 | Prisma Tegak Segitiga  |" << endl;
        cout << "| 8 | Keluar                 |" << endl;
        cout << "|----------------------------|" << endl;
        cout << "Masukkan Angka Pilihan Anda : ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan)
        {
            case 1:
                cout << "|-----------|" << endl;
                cout << "|   Kubus   |" << endl;
                cout << "|-----------|" << endl;
                cout << "Panjang Rusuk Kubus : ";
                cin >> a;
                cout << "-------------------------" << endl;
                volume = a * a * a;
                luas = a * a * 6;
                cout << "Volume Kubus " << volume << endl;
                cout << "Luas Kubus " << luas << endl;
                break;

            case 2:
                cout << "|-----------|" << endl;
                cout << "|   Balok   |" << endl;
                cout << "|-----------|" << endl;
                cout << "Panjang Balok : ";
                cin >> a;
                cout << "Lebar Balok : ";
                cin >> b;
                cout << "Tinggi Balok : ";
                cin >> c;
                cout << "-------------------------" << endl;
                volume = a * b * c;
                luas = 2 * (a * b + b * c + c * a);
                cout << "Volume Balok " << volume << endl;
                cout << "Luas Balok " << luas << endl;
                break;

            case 3:
                cout << "|----------|" << endl;
                cout << "|   Bola   |" << endl;
                cout << "|----------|" << endl;
                cout << "Panjang Jari-Jari : ";
                cin >> a;
                cout << "-------------------------" << endl;
                volume = 4/3 * phi * a * a * a;
                luas = 4 * phi * a * a;
                cout << "Volume Bola " << volume << endl;
                cout << "Luas Bola " << luas << endl;
                break;

            case 4:
                cout << "|------------------------|" << endl;
                cout << "|    Limas Segi Empat    |" << endl;
                cout << "|------------------------|" << endl;
                cout << "Panjang Limas Segi Empat : ";
                cin >> a;
                cout << "Lebar Limas Segi Empat : ";
                cin >> b;
                cout << "Tinggi Limas Segi Empat : ";
                cin >> c;
                cout << "--------------------------------" << endl;
                volume = (a * b * c * 1/3);
                luas = 2 * ((a + b) * c) + (a * b);
                cout << "Volume Limas Segi Empat " << volume << endl;
                cout << "Luas Limas Segi Empat " << luas << endl;
                break;

            case 5:
                cout << "|------------|" << endl;
                cout << "|   Tabung   |" << endl;
                cout << "|------------|" << endl;
                cout << "Panjang Jari-Jari Alas Tabung : ";
                cin >> a;
                cout << "Lebar Tabung : ";
                cin >> b;
                cout << "---------------------------------------" << endl;
                volume = phi * a * a * b;
                luas = (phi * a * 2) * (b * a);
                cout << "Volume Tabung " << volume << endl;
                cout << "Luas Tabung " << luas << endl;
                break;

            case 6:
                cout << "|-------------|" << endl;
                cout << "|   Kerucut   |" << endl;
                cout << "|-------------|" << endl;
                cout << "Panjang Jari-Jari Alas Kerucut : ";
                cin >> a;
                cout << "Tinggi Kerucut : ";
                cin >> b;
                cout << "Garis Pelukis Kerucut : ";
                cin >> d;
                cout << "-----------------------------------------" << endl;
                volume = (phi * a * a * b) / 3;
                luas = (phi * a * (a + d));
                cout << "Volume Kerucut " << volume << endl;
                cout << "Luas Permukaan Kerucut " << luas << endl;
                break;

            case 7:
                cout << "|---------------------------|" << endl;
                cout << "|   Prisma Tegak Segitiga   |" << endl;
                cout << "|---------------------------|" << endl;
                cout << "Alas Segitiga Prisma : ";
                cin >> a;
                cout << "Tinggi Segitiga Prisma : ";
                cin >> b;
                cout << "Sisi Lengkung Segitiga Alas Prisma : ";
                cin >> c;
                cout << "Tinggi Prisma Tegak : ";
                cin >> d;
                cout << "---------------------------------------------" << endl;
                volume = (a * b / 2) * d;
                luas = (2 * (a * b / 2)) + ((a + b + c) * d);
                cout << "Volume Kerucut " << volume << endl;
                cout << "Luas Permukaan Kerucut " << luas << endl;
                break;

            case 8:
                cout << "Terima Kasih Telah Menggunakan Program Ini!!" << endl;
                exitProgram = true;
                break;

            default:
                cout << "Pilihan Menu Yang Anda Masukkan Salah" << endl;
                break;
        }
    }

    return 0;
}