// digunakan untuk memanggil beberapa file
#include <iostream>
#include <regex>
using namespace std;

// fungsi modulus
int moduloFunc(int a, int b)
{
    int result = a % b;
    if (result < 0)
    {
        result += b;
    }
    return result;
}

// Digunakan untuk membuat Fungsi Enkripsi
void Enkripsi()
{
    // Pendeklarasian nilai plain text yang dimasukkan atau diinputkan
    string msg;
    cout << "Masukkan Plain Text : ";
    getline(cin, msg);

    // Perulangan untuk menjalankan semua huruf
    for (int i = 0; i < msg.length(); i++)
    {
        // Pendeklarasian perubahan menjadi huruf kapital
        msg[i] = toupper(msg[i]);
    }
    msg = regex_replace(msg, regex("\\s+"), "");

    // Digunakan untuk mengecek jumlah plaintext dapat habis dibagi 2 atau tidak

    int lenChk = 0;
    // Percabangan digunakan untuk mengecek plaintext habis dibagi 2 jika tidak akan tambahkan huruf a
    if (msg.length() % 2 != 0)
    {
        msg += "0";
        lenChk = 1;
    }
    // Digunakan untuk membagi plain text yang lebih panjang menjadi 2 huruf perpasangan
    int msg2D[2][msg.length() / 2];
    int itr1 = 0;
    int itr2 = 0;
    for (int i = 0; i < msg.length(); i++)
    {
        // Percabangan jika huruf yang menentukan tempat pasangan huruf
        if (i % 2 == 0)
        {
            // Digunakan untuk mengubah huruf menjadi angka
            msg2D[0][itr1] = msg[i] - 65;
            // Digunakan untuk menjalankan pasangan selanjutnya
            itr1++;
        }
        // Jika salah akan menjalankan percabangan ini
        else
        {
            // Digunakan untuk mengubah huruf menjadi angka
            msg2D[1][itr2] = msg[i] - 65;
            // Digunakan untuk menjalankan pasangan selanjutnya
            itr2++;
        }
    }

    // Digunakan untuk mencetak tulisan
    cout << "Masukkan Kunci Dalam Bentuk Text (4 Huruf) : ";
    string key;
    getline(cin, key);

    // Digunakan untuk membuat semua huruf menjadi kapital
    // Perulangan untuk menjalankan semua huruf
    for (int i = 0; i < key.length(); i++)
    {
        // Pendeklarasian perubahan menjadi huruf kapital
        key[i] = toupper(key[i]);
    }

    // Digunakan untuk menghapus spasi
    key = regex_replace(key, regex("\\s+"), "");

    // Digunakan untuk membuat key menjadi matriks 2x2
    int key2D[2][2];
    // Pendeklarasian nilai
    int itr3 = 0;
    // Perulangan untuk membuat matriks atas menjadi 2 bagian
    for (int i = 0; i < 2; i++)
    {
        // Perulangan untuk membuat matrik bawah menjadi 2 bagian
        for (int j = 0; j < 2; j++)
        {
            // Digunakan untuk merubah huruf yang ada menjadi angka
            key2D[i][j] = key[itr3] - 65;
            // Digunakan untuk menjalankan pasangan selanjutnya
            itr3++;
        }
    }

    // Digunakan untuk mengcek key yang dibuat
    // Digunakan untuk mencari nilai determinan dari key yang ada
    int deter = key2D[0][0] * key2D[1][1] - key2D[0][1] * key2D[1][0];
    // Digunakan untuk mencari nilai modulus dari determinal yang sudah ada
    deter = moduloFunc(deter, 26);

    // Mencari nilai inverse matriks
    int mulInv = -1;
    // Perulangan untuk melakukan inverse
    for (int i = 0; i < 26; i++)
    {
        // menghitung nilai inverse
        int tempInv = deter * i;
        // percabangan jika nilai modulus tersisa satu maka akan menjalankan program didalamnya
        if (moduloFunc(tempInv, 26) == 1)
        {
            // menyatakan nilai inverse nya adalah i
            mulInv = i;
            // memberhentikan perulangan
            break;
        }
        else
        {
            continue;
        }
    }

    // percabangan jika nilai inverse -1 akan mejalankan program didalamnya
    if (mulInv == -1)
    {
        // Mencetak tulisan yang sudah diinputkan
        cout << "Key Yang Anda Masukkan Salah!!!" << endl;
        // Memberhentikan program yang dirunning
        exit(EXIT_FAILURE);
    }

    // Pendeklarasian nilai hasil enkripsi yang masih kosong
    string enkripsiText = "";
    // Mendeklarasikan nilai panjang pesan plaintext
    int itrCount = msg.length() / 2;
    // Percabangan jika nilai bagi panjang plaintext habis dibagi 2
    if (lenChk == 0)
    {
        // Perulangan untuk melakukan enskripsi huruf
        for (int i = 0; i < itrCount; i++)
        {
            // Mendeklarasikan enkripsi dengan kunci atas
            int temp1 = msg2D[0][i] * key2D[0][0] + msg2D[1][i] * key2D[0][1];
            // Mendeklarasikan hasil enkripsi yang dimod 26 dan tambah asii
            enkripsiText += (char)((temp1 % 26) + 65);
            // Mendeklarasikan enkripsi dengan kunci bawah
            int temp2 = msg2D[0][i] * key2D[1][0] + msg2D[1][i] * key2D[1][1];
            // Mendeklarasikan hasil enkripsi yang dimod 26 dan tambah asii
            enkripsiText += (char)((temp2 % 26) + 65);
        }
    }
    else
    {
        // Perulangan untuk melakukan enskripsi huruf
        for (int i = 0; i < itrCount - 1; i++)
        {
            // Mendeklarasikan enkripsi dengan kunci atas
            int temp1 = msg2D[0][i] * key2D[0][0] + msg2D[1][i] * key2D[0][1];
            // Mendeklarasikan hasil enkripsi yang dimod 26 dan tambah asii
            enkripsiText += (char)((temp1 % 26) + 65);
            // Mendeklarasikan enkripsi dengan kunci bawah
            int temp2 = msg2D[0][i] * key2D[1][0] + msg2D[1][i] * key2D[1][1];
            // Mendeklarasikan hasil enkripsi yang dimod 26 dan tambah asii
            enkripsiText += (char)((temp2 % 26) + 65);
        }
    }

    // Digunakan untuk mencetak hasil enkripsi
    cout << endl
         << "Cipher Text: " << enkripsiText << endl;
}

// Digunakan untuk membuat Fungsi Dekripsi
void Dekripsi()
{
    // Pendeklarasian nilai plain text yang dimasukkan atau diinputkan
    string msg;
    // Digunakan untuk mencetak tulisan
    cout << "Masukkan Cipher Text : ";
    // Digunakan untuk mencetak nilai yang dimasukkan juga disamping cipher text
    getline(cin, msg);

    // Digunakan untuk membuat semua huruf menjadi kapital
    // Perulangan untuk menjalankan semua huruf
    for (int i = 0; i < msg.length(); i++)
    {
        // Pendeklarasian perubahan menjadi huruf kapital
        msg[i] = toupper(msg[i]);
    }

    // Digunakan untuk menghapus spasi
    msg = regex_replace(msg, regex("\\s+"), "");

    int lenChk = 0;
    // Percabangan digunakan untuk mengecek plaintext habis dibagi 2 jika tidak akan tambahkan huruf a
    if (msg.length() % 2 != 0)
    {
        // Digunakan untuk menambahkan huruf yang bernilai
        msg += "0";
        // Menyatakan nilai yang tidak habis dibagi 1
        lenChk = 1;
    }

    // Digunakan untuk membagi plain text yang lebih panjang menjadi 2 huruf perpasangan
    int msg2D[2][msg.length() / 2];
    // Pendeklarasian nilai yang habis dibagi 2
    int itr1 = 0;
    // Pendeklarasian nilai yang habis dibagi 2
    int itr2 = 0;
    // Perulangan untuk membuat atau membagi huruf menjadi perpasangan
    for (int i = 0; i < msg.length(); i++)
    {
        // Percabangan jika huruf yang menentukan tempat pasangan huruf
        if (i % 2 == 0)
        {
            // Digunakan untuk mengubah huruf menjadi angka
            msg2D[0][itr1] = msg[i] - 65;
            // Digunakan untuk menjalankan pasangan selanjutnya
            itr1++;
        }
        // Jika salah akan menjalankan percabangan ini
        else
        {
            // Digunakan untuk mengubah huruf menjadi angka
            msg2D[1][itr2] = msg[i] - 65;
            // Digunakan untuk menjalankan pasangan selanjutnya
            itr2++;
        }
    }

    // Digunakan untuk mencetak tulisan
    cout << "Masukkan Kunci Dalam Bentuk Text (4 Huruf) : ";
    // Pendeklarasian nilai key yang dimasukkan atau diinputkan
    string key;
    // Digunakan untuk mencetak nilai yang dimasukkan juga disamping key
    getline(cin, key);

    // Digunakan untuk membuat semua huruf menjadi kapital
    // Perulangan untuk menjalankan semua huruf
    for (int i = 0; i < key.length(); i++)
    {
        // Pendeklarasian perubahan menjadi huruf kapital
        key[i] = toupper(key[i]);
    }

    // Digunakan untuk menghapus spasi
    key = regex_replace(key, regex("\\s+"), "");

    // Digunakan untuk membuat key menjadi matriks 2x2
    int key2D[2][2];
    // Pendeklarasian nilai
    int itr3 = 0;
    // Perulangan untuk membuat matriks atas menjadi 2 bagian
    for (int i = 0; i < 2; i++)
    {
        // Perulangan untuk membuat matrik bawah menjadi 2 bagian
        for (int j = 0; j < 2; j++)
        {
            // Digunakan untuk merubah huruf yang ada menjadi angka
            key2D[i][j] = key[itr3] - 65;
            // Digunakan untuk menjalankan pasangan selanjutnya
            itr3++;
        }
    }

    // Digunakan untuk mengcek key yang dibuat
    int deter = key2D[0][0] * key2D[1][1] - key2D[0][1] * key2D[1][0];
    // Digunakan untuk mencari nilai modulus dari determinal yang sudah ada
    deter = moduloFunc(deter, 26);

    // Mencari nilai inverse matriks
    int mulInv = -1;
    for (int i = 0; i < 26; i++)
    {
        // menghitung nilai inverse
        int tempInv = deter * i;
        // percabangan jika nilai modulus tersisa satu maka akan menjalankan program didalamnya
        if (moduloFunc(tempInv, 26) == 1)
        {
            // menyatakan nilai inverse nya adalah i
            mulInv = i;
            // memberhentikan perulangan
            break;
        }
        // jika salah menjalankan else
        else
        {
            // melanjutkan perulangan
            continue;
        }
    }

    // adjugate matrix
    //swapping
    swap(key2D[0][0], key2D[1][1]);

    // changing signs
    key2D[0][1] *= -1;
    key2D[1][0] *= -1;

    key2D[0][1] = moduloFunc(key2D[0][1], 26);
    key2D[1][0] = moduloFunc(key2D[1][0], 26);

    // multiplying multiplicative inverse with adjugate matrix
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            key2D[i][j] *= mulInv;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            key2D[i][j] = moduloFunc(key2D[i][j], 26);
        }
    }

    // Pendeklarasian nilai hasil enkripsi yang masih kosong
    string enkripsiText = "";
    // Mendeklarasikan nilai panjang pesan plaintext
    int itrCount = msg.length() / 2;
    // Percabangan jika nilai bagi panjang plaintext habis dibagi 2
    if (lenChk == 0)
    {
        // Perulangan untuk melakukan enskripsi huruf
        for (int i = 0; i < itrCount; i++)
        {
            // Mendeklarasikan enkripsi dengan kunci atas
            int temp1 = msg2D[0][i] * key2D[0][0] + msg2D[1][i] * key2D[0][1];
            dekripsiText += (char)((temp1 % 26) + 65);
            int temp2 = msg2D[0][i] * key2D[1][0] + msg2D[1][i] * key2D[1][1];
            dekripsiText += (char)((temp2 % 26) + 65);
        }
    }
    else
    {
        // Perulangan untuk melakukan enskripsi huruf
        for (int i = 0; i < itrCount - 1; i++)
        {
            // Mendeklarasikan enkripsi dengan kunci atas
            int temp1 = msg2D[0][i] * key2D[0][0] + msg2D[1][i] * key2D[0][1];
            dekripsiText += (char)((temp1 % 26) + 65);
            int temp2 = msg2D[0][i] * key2D[1][0] + msg2D[1][i] * key2D[1][1];
            dekripsiText += (char)((temp2 % 26) + 65);
        }
    }

    // Digunakan untuk mencetak hasil enkripsi
    cout << endl
         << "Plain Text : " << dekripsiText << endl;
}

// Digunakan untuk fungsi menjalankan program
int main()
{
    // Digunakan untuk mencetak text yang sudah dimasukkan terlebih dahulu
    cout << "1. Enkripsi\n2. Dekripsi\nChoose(1,2): ";
    int choice;
    // digunakan untuk menyatakan pilihan yang sudah dipilih
    cin >> choice;
    cin.ignore();

    // percabangan jika memilih satu akan menjalankan enkripsi
    if (choice == 1)
    {
        // Digunakan untuk mencetak text
        cout << endl
             << "---Enkripsi---" << endl;
        Enkripsi();
    }
    // percabangan jika memilih dua akan menjalankan dekripsi
    else if (choice == 2)
    {
        // Digunakan untuk mencetak text
        cout << endl
             << "---Dekrpsi---" << endl;
        Dekripsi();
    }
    // percabangan jika tidak memilih dua akan menjalankan program didalamnya
    else
    {
        // Digunakan untuk mencetak text
        cout << endl
             << "Pilihan Tidak Ada!!!" << endl;
    }

    return 0;
}