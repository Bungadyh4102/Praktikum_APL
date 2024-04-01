#include <iostream>
#include <string>

using namespace std;

#define max 10

struct BarangAntik {
    string nama;
    int tahun;
    float harga;
    string namaPembeli; 
};

BarangAntik daftarBarang[max];
string loop;
int pos = 0;

int getMenuChoice() {
    int choice;
    system("cls");
    cout << "=====================" << endl;
    cout << "  TOKO BARANG ANTIK  " << endl;
    cout << "=====================" << endl;
    cout << "1. Tambah\n2. Ubah\n3. Hapus\n4. Tampilkan\n5. Keluar" << endl;
    cout << "Pilihan : ";
    cin >> choice;

    while (cin.fail() || choice < 1 || choice > 5) {
        cout << "Pilihan tidak valid. Masukkan angka dari 1 hingga 5: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> choice;
    }

    return choice;
}

void display() {
    system("cls");
    if (pos != 0) {
        cout << "Data Tersimpan" << endl;
        for (int a = 0; a < pos; a++) {
            cout << "Barang " << a + 1 << ":" << endl;
            cout << "Nama: " << daftarBarang[a].nama << endl;
            cout << "Tahun: " << daftarBarang[a].tahun << endl;
            cout << "Harga: " << daftarBarang[a].harga << endl;
            cout << "Pembeli: " << daftarBarang[a].namaPembeli << endl << endl;
        }
    } else {
        cout << "=== Data Kosong ===" << endl;
    }
}

void add() {
    do {
        display();
        if (pos < max) {
            cin.ignore();
            cout << "Tambah Data : " << endl;
            cout << "Nama Barang: ";
            getline(cin, daftarBarang[pos].nama);
            cout << "Tahun: ";
            cin >> daftarBarang[pos].tahun;
            cout << "Harga: ";
            cin >> daftarBarang[pos].harga;
            cin.ignore();
            cout << "Nama Pembeli: ";
            getline(cin, daftarBarang[pos].namaPembeli);
            pos++;
            display();
            cout << "ulangi (y/t) : ";
            cin >> loop;
        } else {
            cout << "=== memori penuh ===" << endl;
            cout << "isi t untuk kembali : ";
            cin >> loop;
        }
    } while (loop == "y");
}

void edit() {
    int y;
    do {
        display();
        cout << "ubah data ke : ";
        cin >> y;

        while (cin.fail() || y < 1 || y > pos) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Nomor data tidak valid. Masukkan nomor yang ada: ";
            cin >> y;
        }

        cin.ignore();
        cout << "ubah menjadi : " << endl;
        cout << "Nama Barang: ";
        getline(cin, daftarBarang[y - 1].nama);
        cout << "Tahun: ";
        cin >> daftarBarang[y - 1].tahun;
        cout << "Harga: ";
        cin >> daftarBarang[y - 1].harga;
        cin.ignore();
        cout << "Nama Pembeli: ";
        getline(cin, daftarBarang[y - 1].namaPembeli);
        display();
        cout << "ubah lagi (y/t) : ";
        cin >> loop;
    } while (loop == "y");
}

void recursiveDelete(int *x) {
    if (*x < pos) {
        daftarBarang[*x - 1] = daftarBarang[*x];
        recursiveDelete(x + 1);
    }
}

void del() {
    int x;
    do {
        display();
        if (pos > 0) {
            cout << " hapus data ke : ";
            cin >> x;

            while (cin.fail() || x < 1 || x > pos) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Nomor data tidak valid. Masukkan nomor yang ada: ";
                cin >> x;
            }

            int *xPtr = &x;
            recursiveDelete(xPtr);
            pos--;
            display();
            cout << "hapus lagi (y/t) : ";
            cin >> loop;
        } else {
            cout << "isikan t : ";
            cin >> loop;
        }
    } while (loop == "y");
}

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
            cout << "Login berhasil" << endl << endl;
            break;
        } else {
            cout << "Username atau password salah. Silakan coba lagi." << endl << endl;
            salah++;
        }

        if (salah == 3) {
            cout << "Anda sudah mencoba 3 kali. Silakan coba lagi nanti." << endl;
            return 0;
        }
    } while (true);

    int pil;
    do {
        pil = getMenuChoice();
        switch (pil) {
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                del();
                break;
            case 4:
                do {
                    display();
                    cout << "kembali (y) : ";
                    cin >> loop;
                } while (loop != "y");
                break;
            case 5:
                cout << "Keluar" << endl;
                break;
            default:
                cout << "Pilih 1 - 5" << endl;
                break;
        }
    } while (pil != 5);
    cout << "Program selesai";
    return 0;
}