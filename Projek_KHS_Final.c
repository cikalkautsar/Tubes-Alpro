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

typedef struct Mahasiswa
{
    char nama[50];
    char prodi[50];
    char nim[10];
    char kelas[5];
    int alpro;
    int arsikom;
    int desgaf;
    int ptki;
    int psikopend;
    int nilai;
    char indeks;
    int semester;
} mahasiswa;

int jumlahdata = 0;
//Fungsi prosedur yang di buat untuk menampilkan menu
void menu()
{
    printf("\nSelamat datang di program Kartu Hasil Studi!\n");
    printf("1. Input Data Mahasiswa\n");
    printf("2. Lihat Data Mahasiswa\n");
    printf("3. Edit Data Mahasiswa\n");
    printf("4. Hapus Data Mahasiswa\n");
    printf("5. Urutan Nilai Tertinggi\n");
    printf("6. Cari Data Mahasiswa\n");
    printf("7. Keluar\n");
}
//fungsi untuk mengembalikan nilai pada penilaian
int penilaian(int alpro, int arsikom, int desgaf, int ptki, int psikopend)
{
    return (alpro + arsikom + desgaf + ptki + psikopend) / 5;
}

/* Fungsi Prosedur untuk membersihkan buffer dalam masalah newline pada fgets*/
void clearInputBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
/*getchar(): Membaca satu karakter dari stdin (standar input).
EOF = End-Of-File*/

}
//Fungsi prosedur untuk print data pada menu 2 (menampilkan data)
void printData(mahasiswa mhs[], int i)
{
    printf("\n+---------------------------------------------+\n");
    printf("|     DEPARTEMEN PENDIDIKAN ILMU KOMPUTER     |\n");
    printf("+---------------------------------------------+\n");
    printf("Kartu Hasil Studi : %s\n", mhs[i].nama);
    printf(" |No                | %d\n", i + 1);
    printf(" |Nama              | %s\n", mhs[i].nama);
    printf(" |Kelas             | %s\n", mhs[i].kelas);
    printf(" |NIM               | %s\n", mhs[i].nim);
    printf(" |Program Studi     | %s\n", mhs[i].prodi);
    printf(" |Matkul            | Algoritma Pemograman : %d | %c \n", mhs[i].alpro, mhs[i].indeks);
    printf(" |Matkul            | Arsitektur dan Organisasi Komputer : %d | %c\n", mhs[i].arsikom, mhs[i].indeks);
    printf(" |Matkul            | Desain Grafis : %d | %c\n", mhs[i].desgaf, mhs[i].indeks);
    printf(" |Matkul            | Pengantar Teknologi Informasi : %d | %c\n", mhs[i].ptki, mhs[i].indeks);
    printf(" |Matkul            | Psikologi Pendidikan : %d | %c\n", mhs[i].psikopend, mhs[i].indeks);
    printf(" |Semester          | Semester : %d\n", mhs[i].semester);
    printf(" |Total SKS         | 23\n");
    printf(" |IP                | %c\n", mhs[i].indeks);
    printf(" |Rata Rata         | %d\n\n", mhs[i].nilai);
}

//fungsi prosedur untuk mengedit data
void edit_data(mahasiswa mhs[], int jumlahdata)
{
    char namaEdit[50];
    int found = 0;

    printf("Masukkan nama mahasiswa yang akan di edit: ");
    /*
    fgets sama seperti scanf tapi fgets bisa baca spasi    
    */
    fgets(namaEdit, sizeof(namaEdit), stdin);
    /* strcspn (string complement span) digunakan karakter newline (\n) yang mungkin ditangkap oleh fungsi fgets 
    ketika membaca string dari input. Fungsi fgets membaca input bersamaan dengan karakter newline
    dan jika tidak dihilangkan, karakter newline tersebut akan menjadi bagian dari string.
    */
    namaEdit[strcspn(namaEdit, "\n")] = '\0';
    /* Looping untuk mengedit data*/
    for (int i = 0; i < jumlahdata; i++)
    {   
    
    /*strcmp (string compare) untuk mencari mahasiswa berdasarkan nama yg merupakan string.
    Dengan menggunakan strcmp, program dapat membandingkan nama yang diinputkan oleh pengguna dengan 
    nama mahasiswa yang terdapat dalam array struktur. fungsi strcmp digunakan untuk membandingkan dua string.
    Jika string-string tersebut sama, strcmp akan mengembalikan nilai 0. 
    Dalam konteks ini, strcmp digunakan untuk mencari mahasiswa dengan nama yang sesuai
    dengan nama yang diinputkan oleh pengguna.*/
        if (strcmp(mhs[i].nama, namaEdit) == 0)
        {
            // Data ditemukan, izinkan pengguna untuk mengedit nilai
            printf("Data ditemukan! Masukkan nilai baru untuk mahasiswa %s:\n", namaEdit);
            printf("Masukkan nilai Algoritma Pemograman: ");
            scanf("%d", &mhs[i].alpro);
            printf("Masukkan nilai Arsitektur dan Organisasi Komputer: ");
            scanf("%d", &mhs[i].arsikom);
            printf("Masukkan nilai Desain grafis: ");
            scanf("%d", &mhs[i].desgaf);
            printf("Masukkan nilai Pengantar Teknologi Informasi: ");
            scanf("%d", &mhs[i].ptki);
            printf("Masukkan nilai Psikologi Pendidikan: ");
            scanf("%d", &mhs[i].psikopend);

            // Perhitungan ulang nilai dan indeks
            mhs[i].nilai = penilaian(mhs[i].alpro, mhs[i].arsikom, mhs[i].desgaf, mhs[i].ptki, mhs[i].psikopend);

            if (mhs[i].nilai >= 90 && mhs[i].nilai <= 100)
            {
                mhs[i].indeks = 'A';
            }
            else if (mhs[i].nilai >= 80 && mhs[i].nilai < 90)
            {
                mhs[i].indeks = 'B';
            }
            else if (mhs[i].nilai >= 70 && mhs[i].nilai < 80)
            {
                mhs[i].indeks = 'C';
            }
            else if (mhs[i].nilai >= 60 && mhs[i].nilai < 70)
            {
                mhs[i].indeks = 'D';
            }
            else
            {
                mhs[i].indeks = 'E';
            }

            printf("Data berhasil diubah!\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Data mahasiswa dengan nama %s tidak ditemukan.\n", namaEdit);
    }
}

//fungsi prosedur hapus data
void delete_data(mahasiswa mhs[], int jumlahdata)
{
    char namaHapus[50];
    int found = 0;

    printf("Masukkan nama mahasiswa yang akan dihapus: ");
    fgets(namaHapus, sizeof(namaHapus), stdin);
    namaHapus[strcspn(namaHapus, "\n")] = '\0';

    for (int i = 0; i < jumlahdata; i++)
    {
        if (strcmp(mhs[i].nama, namaHapus) == 0)
        {
            // Data ditemukan, geser elemen array untuk menutup celah
            for (int j = i; j < jumlahdata - 1; j++)
            {
                mhs[j] = mhs[j + 1];
            }

            (jumlahdata)--; // Kurangi jumlah data setelah penghapusan
            printf("Data mahasiswa %s berhasil dihapus!\n", namaHapus);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Data mahasiswa dengan nama %s tidak ditemukan.\n", namaHapus);
    }
}

void bubbleSortNilai(mahasiswa mhs[], int n)
{
    int i, j;
    mahasiswa temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            // Bandingkan nilai rata-rata mahasiswa
            if (mhs[j].nilai < mhs[j + 1].nilai)
            {
                // Tukar posisi jika nilai rata-rata lebih tinggi
                temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}

void search_data(mahasiswa mhs[], int jumlahdata)
{
    char namaCari[50];
    int found = 0;

    printf("Masukkan nama mahasiswa yang ingin dicari: ");
    fgets(namaCari, sizeof(namaCari), stdin);
    namaCari[strcspn(namaCari, "\n")] = '\0';

    for (int i = 0; i < jumlahdata; i++)
    {
        if (strcmp(mhs[i].nama, namaCari) == 0)
        {
            // Mahasiswa ditemukan, tampilkan data
            printf("Mahasiswa dengan nama %s ditemukan:\n", namaCari);
            printData(mhs, i);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Mahasiswa dengan nama %s tidak ditemukan.\n", namaCari);
    }
}

int main()
{
    mahasiswa mhs[100];
    int pilihan;

    do
    {
        menu();

        printf("-----------PILIH MENU-----------\n");
        scanf("%d", &pilihan);
        clearInputBuffer();

        switch (pilihan)
        {
        case 1:
            // Input Data Mahasiswa
            do
            {
                printf("Masukkan Nama ke-%d / selesai : ", jumlahdata + 1);
                fgets(mhs[jumlahdata].nama, sizeof(mhs[jumlahdata].nama), stdin);
                mhs[jumlahdata].nama[strcspn(mhs[jumlahdata].nama, "\n")] = '\0'; // Hapus karakter newline

                if (strcmp(mhs[jumlahdata].nama, "selesai") == 0)
                {
                    printf("\n[Penginputan Data Telah berhasil!]\n");
                    break;
                }

                printf("Masukkan Kelas ke-%d: ", jumlahdata + 1);
                scanf("%s", &mhs[jumlahdata].kelas);
                clearInputBuffer();

                printf("Masukkan Nim ke-%d: ", jumlahdata + 1);
                scanf("%s", mhs[jumlahdata].nim);
                clearInputBuffer();

                printf("Masukkan Prodi ke-%d: ", jumlahdata + 1);
                fgets(mhs[jumlahdata].prodi, sizeof(mhs[jumlahdata].prodi), stdin);
                mhs[jumlahdata].prodi[strcspn(mhs[jumlahdata].prodi, "\n")] = '\0';

                printf("Masukkan semester ke-%d: ", jumlahdata + 1);
                scanf("%d", &mhs[jumlahdata].semester);
                clearInputBuffer();

                printf("Masukkan nilai Algoritma Pemograman ke-%d : ", jumlahdata + 1);
                scanf("%d", &mhs[jumlahdata].alpro);
                clearInputBuffer();

                printf("Masukkan nilai Arsitektur dan Organisasi Komputer ke-%d : ", jumlahdata + 1);
                scanf("%d", &mhs[jumlahdata].arsikom);
                clearInputBuffer();

                printf("Masukkan nilai Desain grafis ke-%d : ", jumlahdata + 1);
                scanf("%d", &mhs[jumlahdata].desgaf);
                clearInputBuffer();

                printf("Masukkan nilai Pengantar Teknologi Informasi ke-%d : ", jumlahdata + 1);
                scanf("%d", &mhs[jumlahdata].ptki);
                clearInputBuffer();

                printf("Masukkan nilai Psikologi Pendidikan ke-%d : ", jumlahdata + 1);
                scanf("%d", &mhs[jumlahdata].psikopend);
                clearInputBuffer();

                // Perhitungan nilai dan indeks
                mhs[jumlahdata].nilai = penilaian(mhs[jumlahdata].alpro, mhs[jumlahdata].arsikom, mhs[jumlahdata].desgaf, mhs[jumlahdata].ptki, mhs[jumlahdata].psikopend);

                if (mhs[jumlahdata].nilai >= 90 && mhs[jumlahdata].nilai <= 100)
                {
                    mhs[jumlahdata].indeks = 'A';
                }
                else if (mhs[jumlahdata].nilai >= 80 && mhs[jumlahdata].nilai < 90)
                {
                    mhs[jumlahdata].indeks = 'B';
                }
                else if (mhs[jumlahdata].nilai >= 70 && mhs[jumlahdata].nilai < 80)
                {
                    mhs[jumlahdata].indeks = 'C';
                }
                else if (mhs[jumlahdata].nilai >= 60 && mhs[jumlahdata].nilai < 70)
                {
                    mhs[jumlahdata].indeks = 'D';
                }
                else
                {
                    mhs[jumlahdata].indeks = 'E';
                }

                printData(mhs, jumlahdata);
                jumlahdata++;
            } while (strcmp(mhs[jumlahdata - 1].nama, "selesai") != 0);

            break;

        case 2:
            // Lihat Data Mahasiswa
            for (int j = 0; j < jumlahdata; j++)
            {
                printData(mhs, j);
            }
            break;

        case 3:
            // Edit Data Mahasiswa
            edit_data(mhs, jumlahdata);
            break;

        case 4:
            // Hapus Data Mahasiswa
            delete_data(mhs, jumlahdata);
            break;

        case 5:
            // Urutan Nilai Tertinggi
            bubbleSortNilai(mhs, jumlahdata);
            for (int j = 0; j < jumlahdata; j++)
            {
                printData(mhs, j);
            }
            break;

        case 6:
            // Cari Data Mahasiswa
            search_data(mhs, jumlahdata);
            break;

        case 7:
            // Keluar
            printf("Program selesai.\n");
            exit(0);

        default:
            printf("Error Program!\n");
        }
    } while (pilihan != 7);

    return 0;
}
