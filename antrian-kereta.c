#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 5

struct data{
    char nama[30];
    char alamat[30];
    char tujuan[30];
    char kelas[30];
    int no;
};

int main(){
    int pil, i;
    int head = -1;
    int tail = -1;
    char ulang;
    char temp[10];

    struct data antri[MAX];

    do{
        system("cls");
        printf("===========================================================Selamat Datang di Stasiun Kereta Api Sentana Bali============================================================\n");
        printf("Silahkan pilih menu dibawah ini: \n");
        printf("1. Pesan Tiket \n2. Ambil Tiket \n3. Kosongkan antrian\n4. Lihat data pemesan\n5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d",&pil);
        switch(pil){
        case 1:
            system ("cls");
            if(tail == MAX-1)
                printf("Antrian Penuh, silakan tunggu hingga pemesan telah mengambil tiket!!!");
            else{
                tail ++;
                printf("Pilih kelas yang tersedia: \n");
                printf("Kelas Ekonomi\nKelas Bisnis\nKelas Eksekutif\n");
                printf("Ketikkan Kelas: ");
                fflush(stdin);
                gets(temp);
                strcpy(antri[tail].kelas, temp);
                if (strcmp(temp, "ekonomi") == 0){
                    printf("Masukkan no\t\t: ");
                    scanf("%d", &antri[tail].no);
                    printf("Masukkan nama\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].nama);
                    printf("Masukkan alamat\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].alamat);
                    printf("Masukkan tujuan\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].tujuan);
                }
                else if(strcmp(temp, "bisnis") == 0){
                    printf("Masukkan no\t\t: ");
                    scanf("%d", &antri[tail].no);
                    printf("Masukkan nama\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].nama);
                    printf("Masukkan alamat\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].alamat);
                    printf("Masukkan tujuan\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].tujuan);
                }
                else if (strcmp(temp, "eksekutif") == 0){
                    printf("Masukkan no\t\t: ");
                    scanf("%d", &antri[tail].no);
                    printf("Masukkan nama\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].nama);
                    printf("Masukkan alamat\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].alamat);
                    printf("Masukkan tujuan\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].tujuan);
                }
                else{
                    printf("Pilihan tidak ada!!!\n");
                    tail --;
                }
            }
            break;
        case 2:
            system ("cls");
            if(head == tail)
                printf("Tidak ada antrian!\n");
            else{
                head ++;
                printf("Pemesan dengan no antrian %d silahkan menuju ke loket untuk mengambil tiket\n", antri[head].no);
                }
            break;
        case 3:
            system ("cls");
            if(head == tail)
                printf("Data masih kosong\n");
            else{
                head = tail = -1;
                printf("Data sudah dikosongkan\n");
            }
            break;
        case 4:
            system ("cls");
            if(head == tail)
                printf("Tidak ada antrian!\n");
            else{
                printf("Data pemesan saat ini\n");
                for(i=head+1; i<=tail; i++){
                    printf("No\t: %d\n", antri[i].no);
                    printf("Nama\t: %s\n", antri[i].nama);
                    printf("Alamat\t: %s\n", antri[i].alamat);
                    printf("Tujuan\t: %s\n", antri[i].tujuan);
                    printf("Kelas\t: %s\n\n", antri[i].kelas);
                }
            }
            break;
        case 5:
            printf("\nTerima Kasih");
            exit(0);
            break;
        default:
            printf("Pilihan tidak tersedia!!!\n");
        }printf("Ingin mengulang?(y/t): ");
         scanf("%s", &ulang);
    }while(ulang == 'y');
  return 0;
}

