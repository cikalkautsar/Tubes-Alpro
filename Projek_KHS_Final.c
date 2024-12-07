/*
1.	Percabangan
Menggunakan IF else, (dan mungkin jika dirasa membutuhkan memakai switch case).
If else ini digunakan untuk menentukan indeks nilai pada mata kuliah.
2.	Perulangan
Menggunakan while. Ketika user sudah selesai menjalankan program.
user akan diberikan pilihan untuk melanjutkan atau selesai.
3.	Array
Untuk menampung variabel nama mahasiswa, program studi, mata kuliah
4.	Fungsi/Prosedur
Prosedur untuk menampilkan data mahasiswa dan data mata kuliah
5.	Pengurutan
Mengurutkan nama mahasiwa dari abjad paling awal atau NIM mahasiswa dari
angka paling kecil.
6.	Pencarian
Fitur pencarian di buat untuk memudahkan user mencari nama mahasiswa

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data mahasiswa
typedef struct Mahasiswa {
    char nama[50];
    char prodi[50];
    char nim[10];
    char kelas[5];
    int alpro, arsikom, desgaf, ptki, psikopend, nilai;
    char indeks;
    int semester;
} mahasiswa;

int jumlahdata = 0;
int jumlahdata_terhapus = 0;

// Fungsi untuk menampilkan menu
void menu() {
    printf("\n+-----------------------------+\n");
    printf("| Program Kartu Hasil Studi   |\n");
    printf("+-----------------------------+\n");
    printf("1. Input Data Mahasiswa\n");
    printf("2. Lihat Data Mahasiswa\n");
    printf("3. Edit Data Mahasiswa\n");
    printf("4. Hapus Data Mahasiswa\n");
    printf("5. Urutan Nilai Tertinggi\n");
    printf("6. Cari Data Mahasiswa\n");
    printf("7. Lihat History Data Terhapus\n");
    printf("8. Keluar\n");
    printf("Pilihan: ");
}

// Fungsi untuk menghitung nilai rata-rata
int penilaian(int alpro, int arsikom, int desgaf, int ptki, int psikopend) {
    return (alpro + arsikom + desgaf + ptki + psikopend) / 5;
}

// Fungsi untuk membersihkan input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fungsi untuk menampilkan data mahasiswa
void printData(mahasiswa mhs[], int i) {
    printf("\n+--------------------------------+\n");
    printf("Nama              : %s\n", mhs[i].nama);
    printf("Kelas             : %s\n", mhs[i].kelas);
    printf("NIM               : %s\n", mhs[i].nim);
    printf("Program Studi     : %s\n", mhs[i].prodi);
    printf("Semester          : %d\n", mhs[i].semester);
    printf("Nilai Rata-rata   : %d\n", mhs[i].nilai);
    printf("Indeks Nilai      : %c\n", mhs[i].indeks);
}

// Fungsi untuk menghapus data mahasiswa
void delete_data(mahasiswa mhs[], mahasiswa mhs_terhapus[], int *jumlahdata, int *jumlahdata_terhapus) {
    char namaHapus[50];
    int found = 0;

    printf("Masukkan nama mahasiswa yang akan dihapus: ");
    fgets(namaHapus, sizeof(namaHapus), stdin);
    namaHapus[strcspn(namaHapus, "\n")] = '\0';

    for (int i = 0; i < *jumlahdata; i++) {
        if (strcmp(mhs[i].nama, namaHapus) == 0) {
            // Simpan data ke dalam array history
            mhs_terhapus[*jumlahdata_terhapus] = mhs[i];
            (*jumlahdata_terhapus)++;

            // Geser elemen array untuk menutup celah
            for (int j = i; j < *jumlahdata - 1; j++) {
                mhs[j] = mhs[j + 1];
            }

            (*jumlahdata)--; // Kurangi jumlah data
            printf("Data mahasiswa %s berhasil dihapus!\n", namaHapus);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Data mahasiswa dengan nama %s tidak ditemukan.\n", namaHapus);
    }
}

// Fungsi untuk melihat history data yang telah dihapus
void lihat_history(mahasiswa mhs_terhapus[], int jumlahdata_terhapus) {
    if (jumlahdata_terhapus == 0) {
        printf("Tidak ada data yang telah dihapus.\n");
        return;
    }
    for (int i = 0; i < jumlahdata_terhapus; i++) {
        printData(mhs_terhapus, i);
    }
}

// Main program
int main() {
    mahasiswa mhs[100], mhs_terhapus[100];
    int pilihan;

    do {
        menu();
        scanf("%d", &pilihan);
        clearInputBuffer();

        switch (pilihan) {
            case 1:
                // Input Data
                while (1) {
                    printf("Masukkan Nama Mahasiswa (atau 'selesai' untuk keluar): ");
                    fgets(mhs[jumlahdata].nama, sizeof(mhs[jumlahdata].nama), stdin);
                    mhs[jumlahdata].nama[strcspn(mhs[jumlahdata].nama, "\n")] = '\0';

                    if (strcmp(mhs[jumlahdata].nama, "selesai") == 0) break;

                    printf("Masukkan Kelas: ");
                    scanf("%s", mhs[jumlahdata].kelas);
                    clearInputBuffer();

                    printf("Masukkan NIM: ");
                    scanf("%s", mhs[jumlahdata].nim);
                    clearInputBuffer();

                    printf("Masukkan Program Studi: ");
                    fgets(mhs[jumlahdata].prodi, sizeof(mhs[jumlahdata].prodi), stdin);
                    mhs[jumlahdata].prodi[strcspn(mhs[jumlahdata].prodi, "\n")] = '\0';

                    printf("Masukkan Semester: ");
                    scanf("%d", &mhs[jumlahdata].semester);
                    clearInputBuffer();

                    // Masukkan nilai dan hitung
                    printf("Masukkan nilai Algoritma Pemrograman: ");
                    scanf("%d", &mhs[jumlahdata].alpro);
                    printf("Masukkan nilai Arsitektur dan Organisasi Komputer: ");
                    scanf("%d", &mhs[jumlahdata].arsikom);
                    printf("Masukkan nilai Desain Grafis: ");
                    scanf("%d", &mhs[jumlahdata].desgaf);
                    printf("Masukkan nilai Pengantar Teknologi Informasi: ");
                    scanf("%d", &mhs[jumlahdata].ptki);
                    printf("Masukkan nilai Psikologi Pendidikan: ");
                    scanf("%d", &mhs[jumlahdata].psikopend);
                    clearInputBuffer();

                    // Hitung nilai rata-rata dan indeks
                    mhs[jumlahdata].nilai = penilaian(mhs[jumlahdata].alpro, mhs[jumlahdata].arsikom, mhs[jumlahdata].desgaf, mhs[jumlahdata].ptki, mhs[jumlahdata].psikopend);
                    if (mhs[jumlahdata].nilai >= 90) mhs[jumlahdata].indeks = 'A';
                    else if (mhs[jumlahdata].nilai >= 80) mhs[jumlahdata].indeks = 'B';
                    else if (mhs[jumlahdata].nilai >= 70) mhs[jumlahdata].indeks = 'C';
                    else if (mhs[jumlahdata].nilai >= 60) mhs[jumlahdata].indeks = 'D';
                    else mhs[jumlahdata].indeks = 'E';

                    jumlahdata++;
                }
                break;

            case 2:
                // Lihat Data
                for (int i = 0; i < jumlahdata; i++) {
                    printData(mhs, i);
                }
                break;

            case 4:
                // Hapus Data
                delete_data(mhs, mhs_terhapus, &jumlahdata, &jumlahdata_terhapus);
                break;

            case 7:
                // Lihat History Data Terhapus
                lihat_history(mhs_terhapus, jumlahdata_terhapus);
                break;

            case 8:
                printf("Program selesai.\n");
                exit(0);

            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (1);

    return 0;
}

