#include <iostream>
using namespace std;

int main() {
    string username;
    string password;
    int salah = 0;

    do {
        cout << "username: ";
        cin >> username;

        cout << "password: ";
        cin >> password;

        if (username == "Bunga" && password == "2309106133") {
            cout << "Login berhasil";
            break;
        } else {
            cout << "Username atau password salah. Silakan coba lagi." << endl;
            salah++;
        }

        if (salah == 3) {
            cout << "Anda sudah mencoba 3 kali. Silakan coba lagi nanti." << endl;
            break;
        }
    } while (true); 

    int answer;
    float Celcius, Farenheit, Kelvin, Reamur;
    string choice;

    do {
        cout << "=====================" << endl;
        cout << "    Konversi Suhu    " << endl;
        cout << "=====================" << endl;
        cout << "Masukkan kode suhu yang ingin dikonversikan" << endl;
        cout << "1. Celcius" << endl;
        cout << "2. Farenheit" << endl;
        cout << "3. Kelvin" << endl;
        cout << "4. Reamur" << endl;
        cout << "Kode suhu: ";
        cin >> answer;

        switch (answer) {
            case 1:
                cout << "Konversi Suhu Celcius" << endl;
                cout << "Masukkan suhu awal (Data berupa angka)" << endl;
                cout << "Suhu awal: ";
                cin >> Celcius;
                Farenheit = 9 * Celcius / 5 + 32;
                Kelvin = Celcius + 273.15;
                Reamur = 4 * Celcius / 5;
                cout << "Farenheit = " << Farenheit << endl;
                cout << "Kelvin = " << Kelvin << endl;
                cout << "Reamur = " << Reamur << endl;
                break;
            case 2:
                cout << "Konversi Suhu Farenheit" << endl;
                cout << "Masukkan suhu awal (Data berupa angka)" << endl;
                cout << "Suhu awal: ";
                cin >> Farenheit;
                Celcius = (Farenheit - 32) * 5 / 9;
                Kelvin = (Farenheit - 32) * 5 / 9 + 273.15;
                Reamur = (Farenheit - 32) * 4 / 9;
                cout << "Celcius = " << Celcius << endl;
                cout << "Kelvin = " << Kelvin << endl;
                cout << "Reamur = " << Reamur << endl;
                break;
            case 3:
                cout << "Konversi Suhu Kelvin" << endl;
                cout << "Masukkan suhu awal (Data berupa angka)" << endl;
                cout << "Suhu awal: ";
                cin >> Kelvin;
                Celcius = Kelvin - 273.15;
                Farenheit = (Kelvin - 273.15) * 9 / 5 + 32;
                Reamur = (Kelvin - 273.15) * 4 / 5;
                cout << "Celcius = " << Celcius << endl;
                cout << "Farenheit = " << Farenheit << endl;
                cout << "Reamur = " << Reamur << endl;
                break;
            case 4:
                cout << "Konversi Suhu Reamur" << endl;
                cout << "Masukkan suhu awal (Data berupa angka)" << endl;
                cout << "Suhu awal: ";
                cin >> Reamur;
                Celcius = 5 * Reamur / 4;
                Farenheit = 9 * Reamur / 4 + 32;
                Kelvin = 5 * Reamur / 4 + 273.15;
                cout << "Celcius = " << Celcius << endl;
                cout << "Farenheit = " << Farenheit << endl;
                cout << "Kelvin = " << Kelvin << endl;
                break;
            default:
                cout << "Maaf, format kode suhu yang anda masukkan salah" << endl;
        }

        cout << "Apakah Anda ingin melanjutkan? (ya/tidak): ";
        cin >> choice;
    } while (choice == "ya" || choice == "Ya" || choice == "YA");
    

    return 0;
}
