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

void bubbleSortName();
void selectionSortPrice();
void quickSortBuyerName(int low, int high);

int sequentialSearchAscending(string key);
int binarySearchDescending(float key, int left, int right);

int getMenuChoice() {
    int choice;
    system("cls");
    cout << "=====================" << endl;
    cout << "  TOKO BARANG ANTIK  " << endl;
    cout << "=====================" << endl;
    cout << "1. Tambah\n2. Ubah\n3. Hapus\n4. Tampilkan\n5. Cari\n6. Keluar" << endl;
    cout << "Pilihan : ";
    cin >> choice;

    while (cin.fail() || choice < 1 || choice > 6) {
        cout << "Pilihan tidak valid. Masukkan angka dari 1 hingga 6: ";
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

void bubbleSortName() {
    for (int i = 0; i < pos - 1; i++) {
        for (int j = 0; j < pos - i - 1; j++) {
            if (daftarBarang[j].nama > daftarBarang[j + 1].nama) {
                swap(daftarBarang[j], daftarBarang[j + 1]);
            }
        }
    }
}

void selectionSortPrice() {
    for (int i = 0; i < pos - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < pos; j++) {
            if (daftarBarang[j].harga > daftarBarang[max_index].harga) {
                max_index = j;
            }
        }
        swap(daftarBarang[i], daftarBarang[max_index]);
    }
}

void quickSortBuyerName(int low, int high) {
    if (low < high) {
        int pivot = low;
        int i = low;
        int j = high;

        while (i < j) {
            while (daftarBarang[i].namaPembeli <= daftarBarang[pivot].namaPembeli && i < high) {
                i++;
            }
            while (daftarBarang[j].namaPembeli > daftarBarang[pivot].namaPembeli) {
                j--;
            }
            if (i < j) {
                swap(daftarBarang[i], daftarBarang[j]);
            }
        }
        swap(daftarBarang[j], daftarBarang[pivot]);
        quickSortBuyerName(low, j - 1);
        quickSortBuyerName(j + 1, high);
    }
}

int sequentialSearchAscending(string key) {
    for (int i = 0; i < pos; i++) {
        if (daftarBarang[i].nama == key) {
            return i;
        }
    }
    return -1;
}

int binarySearchDescending(float key, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (daftarBarang[mid].harga == key) {
            return mid;
        }
        if (daftarBarang[mid].harga < key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
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
                int sortChoice;
                cout << "Pilih metode sorting:" << endl;
                cout << "1. Bubble Sort (Ascending huruf berdasarkan nama barang antik)" << endl;
                cout << "2. Selection Sort (Descending angka berdasarkan harga)" << endl;
                cout << "3. Quick Sort (Ascending huruf berdasarkan nama pembeli)" << endl;
                cout << "Pilihan : ";
                cin >> sortChoice;

                switch (sortChoice) {
                    case 1:
                        bubbleSortName();
                        break;
                    case 2:
                        selectionSortPrice();
                        break;
                    case 3:
                        quickSortBuyerName(0, pos - 1);
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                        break;
                }

                display();
                cout << "kembali (y) : ";
                cin >> loop;
                break;
            case 5:
                // Search menu
                int searchChoice;
                cout << "Pilih metode pencarian:" << endl;
                cout << "1. Sequential Search (Ascending huruf berdasarkan nama barang antik)" << endl;
                cout << "2. Binary Search (Descending angka berdasarkan harga)" << endl;
                cout << "Pilihan : ";
                cin >> searchChoice;

                switch (searchChoice) {
                    case 1: {
                        string searchKey;
                        cout << "Masukkan nama barang yang ingin dicari: ";
                        cin >> searchKey;
                        int result = sequentialSearchAscending(searchKey);
                        if (result != -1) {
                            cout << "Barang ditemukan pada posisi " << result + 1 << endl;
                        } else {
                            cout << "Barang tidak ditemukan." << endl;
                        }
                        break;
                    }
                    case 2: {
                        float searchKey;
                        cout << "Masukkan harga barang yang ingin dicari: ";
                        cin >> searchKey;
                        int result = binarySearchDescending(searchKey, 0, pos - 1);
                        if (result != -1) {
                            cout << "Barang ditemukan pada posisi " << result + 1 << endl;
                        } else {
                            cout << "Barang tidak ditemukan." << endl;
                        }
                        break;
                    }
                    default:
                        cout << "Pilihan tidak valid." << endl;
                        break;
                }
                cout << "kembali (y) : ";
                cin >> loop;
                break;
            case 6:
                cout << "Keluar" << endl;
                break;
            default:
                cout << "Pilih 1 - 6" << endl;
                break;
        }
    } while (pil != 6);
    cout << "Program selesai";
    return 0;
}