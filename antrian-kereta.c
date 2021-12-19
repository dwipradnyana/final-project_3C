#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define banyak_kursi 4
#define MAX 5

struct data{
    char nama[30];
    char alamat[30];
    char tujuan[30];
    char kelas[30];
    int no;
};

struct tumpukan {
    int top;
    int data[MAX];
};
struct tumpukan stack;

void create_stack(){
    stack.top = -1;
}

void push(int data){
    stack.top++;
    stack.data[stack.top] = data;
}
void  pop(){
    stack.top--;
}

void bayar(int harga){
    create_stack();
    int pecahan[7] = {1000, 2000, 5000, 10000, 20000, 50000, 100000};
    int bayar, banyak[7];
    int i = 6, count = 0, buff[MAX];
    printf(" Harga\t: Rp%d\n", harga);
    printf(" Bayar\t: Rp");
    scanf("%d", &bayar);
    int sisa = bayar - harga;
    if (sisa < 0){
        printf(" Uang Anda tidak cukup\n");
    }else if (sisa > 0){
        for (i; i >= 0 && sisa != 0; i--){
            if (pecahan[i] < sisa){
                banyak[count] = sisa / pecahan[i];
                sisa = sisa % pecahan[i];
                push(pecahan[i]);
                buff[count] = i;
                count++;
            }else if (pecahan[i] == sisa){
                banyak[count] = sisa / pecahan[i];
                sisa = 0;
                push(pecahan[i]);
                count++;
            }
        }
	printf("\n Kembalian\t: Rp%d\n", bayar-harga);
        for (i = 0; i < count; i++){
            printf(" %d sebanyak %d\n", stack.data[stack.top], banyak[i]);
            pop();
        }
        printf("\n\n TERIMA KASIH\n");
    }else {
        printf("\n\n TERIMA KASIH\n\n");
    }

}

void masukdata(){
	int A[50][50],B[200];
	int a,b,c,d,tgl;
	
	FILE*Graf=fopen("Graf.txt","r");
	a=0;
	while(!feof(Graf)){
		fscanf(Graf,"%i",&B[a]);fflush(stdin);
		a++;
	}
	
	b=1;
	while(b!=a/b){
		b++;
	}
	
	d=0;
	for(a=0;a<b;a++){
		A[b][a]=0;A[b+1][a]=a;
		for(c=0;c<b;c++){
			A[a][c]=B[d];
			A[b][a]+=A[a][c];
			d++;
		}
	}
	
	d=b;
	for(a=0;a<d;a++){
		for(b=0;b<d;b++){
			if (A[d][a]>=A[d][b]){
				c=A[d][a];A[d][a]=A[d][b];A[d][b]=c;
				c=A[d+1][a];A[d+1][a]=A[d+1][b];A[d+1][b]=c;
			}
		}
	}
	
	for(a=0;a<d;a++){
		for(b=0;b<d;b++){
			if(A[a][d]==A[b][d]&&A[a][b]==1&&a>b&&a!=b){
				A[a][d]++;
			}
		}
	}
	
	int kelas=0; int jam=10;
	printf("Keberangkatan Pukul %i: \n",jam);
	for(a=0;a<d;a++){
		if(A[a][d]==0){
			printf("\tKelas Ekonomi\t: %i\t| Jalur 1\n",jam);
		}else if(A[a][d]==1){
			printf("\tKelas Bisnis\t: %i\t| Jalur 2\n",jam);
		}else{
			printf("\tKelas Eksekutif\t: %i\t| Jalur 3\n",jam);
		}
		kelas++;
		if(kelas==3){
			kelas=0;
			jam+=3;
			printf("Keberangkatan Pukul %i: \n",jam);
		}
	}
}

void kursi(){
    int kursi[banyak_kursi*banyak_kursi], kursi_pilihan;
    printf("Kursi yang tersedia (1 terisi, 0 kosong)\n \n");
    int i,j;
	for(i = 0; i < banyak_kursi*2; i++){
        for( j = 0; j < banyak_kursi; j++){
            kursi[i + j] = rand() % 2;
        }
    }
    ulang:
    for (i = 0; i < banyak_kursi*2; i++){
        for(j = 0; j < banyak_kursi; j++){
            printf("| %d |  ", kursi[i + j]);
        }
        printf("\n");
    }
    printf("Dihitung dari kiri ke kanan (0-27)");
    printf("\nPilih kursi yang Anda inginkan: ");
    scanf("%d", &kursi_pilihan);

    if (kursi[kursi_pilihan] == 1){
        printf("Kursi telah terambil\n");
        goto ulang;
    }else if (kursi[kursi_pilihan] == 0){
        kursi[kursi_pilihan] = 1;
        printf("Kursi berhasil terpesan\n\n NOMOR KURSI ANDA ADALAH %d\n", kursi_pilihan);
    }
}

int main(){
    int pil, i;
    int head = -1;
    int tail = -1;
    char ulang;
    char temp[10];
    int ekonomi=74000, bisnis=285000, eksekutif=500000;
    struct data antri[MAX];

    do{
        system("cls");
        printf("===========================================================Selamat Datang di Stasiun Kereta Api Sentana Bali============================================================\n");
        printf("\n***Jadwal Keberangkatan***\n");
        masukdata();
	printf("========================================================================================================================================================================\n");
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
                printf("Ketikkan Kelas\t: ");
                fflush(stdin);
                gets(temp);
                strcpy(antri[tail].kelas, temp);
                if (strcmp(temp, "ekonomi") == 0){
		printf("Masukkan No\t\t: ");
                    scanf("%d", &antri[tail].no);
                    printf("Masukkan Nama\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].nama);
                    printf("Masukkan Alamat\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].alamat);
                    printf("Masukkan Tujuan\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].tujuan);
                    kursi();
                    bayar(ekonomi);
                }
                else if(strcmp(temp, "bisnis") == 0){
		    printf("Masukkan No\t\t: ");
                    scanf("%d", &antri[tail].no);
                    printf("Masukkan Nama\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].nama);
                    printf("Masukkan Alamat\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].alamat);
                    printf("Masukkan Tujuan\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].tujuan);
                    kursi();
                    bayar(bisnis);
                }
                else if (strcmp(temp, "eksekutif") == 0){
		    printf("Masukkan No\t\t: ");
                    scanf("%d", &antri[tail].no);
                    printf("Masukkan Nama\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].nama);
                    printf("Masukkan Alamat\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].alamat);
                    printf("Masukkan Tujuan\t\t: ");
                    fflush(stdin);
                    gets(antri[tail].tujuan);
                    kursi();
                    bayar(eksekutif);
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
