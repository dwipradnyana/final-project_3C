void masukdata(){
	//Deklarasi Variabel Yang Digunakan
	int A[50][50],B[200];
	int a,b,c,d,tgl;
	
	//Mengambil data dari file Graf.txt dan disimpan pada Array 1 dimensi
	FILE*Graf=fopen("Graf.txt","r");
	a=0;
	while(!feof(Graf)){
		fscanf(Graf,"%i",&B[a]);fflush(stdin);
		a++;
	}
	
	//Mengakarkan a sehingga didapatkan index untuk membenruk Array 2 dimensi
	b=1;
	while(b!=a/b){
		b++;
	}
	
	//Memindahkan data dari Array 1 Dimensi ke Array 2 Dimensi
	d=0;
	for(a=0;a<b;a++){
		A[b][a]=0;A[b+1][a]=a;
		for(c=0;c<b;c++){
			A[a][c]=B[d];
			A[b][a]+=A[a][c];
			d++;
		}
	}
	
	//Mendapatkan bobot edge tiap vertex
	d=b;
	for(a=0;a<d;a++){
		for(b=0;b<d;b++){
			if (A[d][a]>=A[d][b]){
				c=A[d][a];A[d][a]=A[d][b];A[d][b]=c;
				c=A[d+1][a];A[d+1][a]=A[d+1][b];A[d+1][b]=c;
			}
		}
	}
	
	//Memberi warna ke tiap vertex
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
			printf("\tKelas Ekonomi: %i | Jalur 1\n",jam);
		}else if(A[a][d]==1){
			printf("\tKelas Bisnis: %i | Jalur 2\n",jam);
		}else{
			printf("\tKelas Eksekutif: %i | Jalur 3\n",jam);
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
    printf("Dihitung dari kiri ke kanan (0-35)");
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
