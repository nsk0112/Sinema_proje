#include <stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<conio.h>

void uyeEkle();
void uyeGirisi();
void uyeSil(int s);
void filmsec();
void filmler();
void aSifre();
void admin();
void filmEkle();
void atistirmalikAl(float ucret);
void atistirmalikDuzenle();
void atistirmalikEkle();
void atistirmalikSil();
void atistirmalikGoruntule();


typedef struct {
	char ad[20];
	char soyad[20];
	char dogumTarihi[11];
	char eposta[30];
	char tel[10];	
	char sifre[11];
}kullanici;

typedef struct{
	char filmAdi[40];
	long int filmKodu;
    char filmTur[30];
    int filmSaat;
    char filmSeans[5][4];
    float filmPuan;
    char filmOzet[1000];
    int secenek;
}film;

typedef struct {
	char urunAdi[25];
	float urunFiyati;	
}atistirmalik;


int main()
{
	setlocale(LC_ALL,"Turkish");
	system ("color F4");
	int uyelik;
	printf("\n%60s%38s\n" ,"HO�GELD�N�Z!","");
	printf("| �ye ol -> [1]\n| �ye giri�i -> [2]\n| Admin i�lemleri -> [3]\n| ��k�� -> [4]\n|\n| Se�iminiz -> ");
	scanf("%d",&uyelik);
	system("cls");
	if ( uyelik == 1){
		uyeEkle();
	}
	else if( uyelik == 2){
		uyeGirisi();
	}
	
	else if(uyelik==3){
	    aSifre();
	}
	
	else if(uyelik==4) {
		exit(EXIT_SUCCESS);	
	}
	
}

void uyeEkle()
{  
    printf("\n| Kay�t i�lemi s�ras�nda T�rk�e karakter kullnmay�n�z.\n");
    printf("| E-posta adresi giri�inde G-Mail adresinizi kullan�n�z ve @ i�aretinden �nceki k�sm�n� giriniz.\n\n");
    kullanici uye;
    char gec;
	FILE *uyeler;
    uyeler=fopen("uyeler.txt","a");
    fflush(stdin);
	printf("\n\t\t| Ad: ");
	scanf("%[^\n]s",&uye.ad);
	fprintf(uyeler,"%s\n",&uye.ad);
	printf("\t\t| Soyad: ");
	scanf("%s",&uye.soyad);
	fprintf(uyeler,"%s\n",&uye.soyad);
	printf("\t\t| Do�um tarihi: ");
	scanf("%s",&uye.dogumTarihi);
	fprintf(uyeler,"%s\n",&uye.dogumTarihi);
	printf("\t\t| Telefon numaras�: 0");
    scanf("%s",&uye.tel);
    fprintf(uyeler,"%s\n",&uye.tel);
	printf("\t\t| E-posta adresi: ");
	scanf("%s",&uye.eposta);
	fprintf(uyeler,"%s\n",&uye.eposta);
	printf("\t\t| �ifrenizi belirleyiniz:(10 karakterli olmak zorundad�r.) ");
	scanf("%s",&uye.sifre);
	fprintf(uyeler,"%s\n\n",&uye.sifre);
	fclose(uyeler);
	printf("\n\n\t\t\t| �YEL�K BA�ARIYLA OLU�TURULDU. HO�GELD�N�Z %s!\n\t\t\t| F�LM SE�ME EKRANINA G�TMEK ���N HERHANG� B�R TU�A TIKLAYINIZ.",strupr(uye.ad));
    getch();
    filmsec();
    
}

void uyeGirisi(){
	FILE *uyegiris;
	char epostaG[30],sifreG[11],eposta[30],sifre[11];
	uyegiris=fopen("uyeler.txt","r");
	donus:
    rewind(uyegiris);
	int i=0;
	int secim;
	printf("\n\n\t-Eposta: ");
	scanf("%s",&epostaG);
	printf("\n\t-�ifre: ");
	while(i<10)
        { sifreG[i]=getch();
          printf("*");
          i++;
        }
     sifreG[i]='\0';  
	  while( getc(uyegiris)!=EOF )
        {   fscanf(uyegiris,"\n%s\n",&eposta);
            fscanf(uyegiris,"%s",&sifre);    
            if(strcmp(epostaG,eposta)==0 && strcmp(sifreG,sifre)==0)
            { printf("\n\n\t\tHO�GELD�N�Z!\n\n| Film se�imi -> [1]\n| �ifre de�i�tirme -> [2]\n| �yelik iptali -> [3]\n|\n| Se�iminiz -> ");
			  scanf("%d",&secim);
			  break;
			  }
        }
    if(secim==1){
    system("cls");
	filmsec();
	}
	else if(secim==2) uyeSil(secim);
	else if(secim==3) uyeSil(secim);
    else {
    printf("\n\t\t**BA�ARISIZ G�R��...TEKRAR DENEY�N�Z**");
	goto donus;	
	};

}

void filmsec()
	{
		
	setlocale(LC_ALL,"Turkish");
	char harf[10]={"ABCDEFGH"};
	char koltuk[10][10];
	int a;
	char seans[5];
	int kod,i,j,k,okisi=0, tamkisi=0, kisi=0;
	float ogr=10.00, tam=15.50, toplam=0;
	system("cls");

	filmler();
	
	printf("\n");
	printf("\t\t");
	for(i=1;i<=44;i++){
		printf("-");
	}
    printf("\n\t\t| SE�MEK �STED���N�Z F�LM�N KODUNU G�R�N�Z |\n");
    printf("\t\t");
    for(i=1;i<=44;i++){
		printf("-");
	}
    printf("\n\t\t| Film Kodu:");              
    scanf("%d",&kod);
    printf("\t\t| Se�ti�iniz seans (�rne�in 11.00): ");
    scanf("%s",&seans);
				
				//while(fscanf(filmler,"%ld",kod)!=EOF){
				//	fscanf(filmler,"")
				//}
				
	printf("\t\t| ��renci bileti say�s�: ");
	scanf("%d",&okisi);
	printf("\t\t| Tam bilet say�s�: ");
	scanf("%d",&tamkisi);
	for(i=0;i<okisi;i++){
		toplam=toplam+ogr;
	}
	for(i=0;i<tamkisi;i++){
			       toplam=toplam+tam;
				}
				
	kisi=okisi+tamkisi;
	printf("\n\n\n\n\t\t->Toplam Bilet Tutar�:%0.2f\n\n",toplam);
				
	for(i=0;i<7;i++){
		printf("\t\t%c",harf[i]);
		for(j=0;j<10;j++){
			printf("%d",j);
			printf(" __   ");
		}
		printf("\n\n\n");
	}
	printf("\t\t----------------------------- P E R D E ----------------------------- \n");
	printf("\t\tKoltu�unuzu Se�iniz:\n\n ");
	for(a=0;a<kisi;a++)	{
		printf("\t\t-> ");
		scanf("%s[^\n]",koltuk[a]);
		}
		printf("\t\t\n\n\t/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / \n");
		printf("\n\t\t***SON B�LET B�LG�LER� OLU�TURULUYOR***\n\n");
				
				
		printf("\t\tSon Bilet Bilgileri:\n \t\t|  Bilet tutar�: %0.2f\n \t\t|  ��renci Bileti Say�s�: %d\n \t\t|  Tam Bilet Say�s�: %d\n \t\t|  Film Kodu: %d\n \t\t|  Seans: %s\n ",toplam,okisi,tamkisi,kod,seans);
		printf("\t\t|  Koltuk Numaras�: \n");
		printf("\t\t");
		for(a=0;a<kisi;a++){
			printf("|  ");
			puts(koltuk[a]);
			printf("\t\t");
		}
		printf("\t\t\n\t/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /");
		
	FILE *dosya;
	    dosya=fopen("Biletbilgileri.txt","a");
	    if(dosya==NULL)
	   {
		printf("Dosya olu�turulamad�...");
     	}
	    else {
	    	fprintf(dosya,"\t\t\t***B�LET B�LG�LER�***\n ");
		fprintf(dosya,"\t\t-->�denen:%f\n\t\t-->Film:%d\n\t\t-->Ki�i say�s�:%d\n\t\t-->Seans:%s\n",toplam,kod,kisi,seans);
			for(a=0;a<kisi;a++)
			{
				fprintf(dosya,"\t\t-->%d.Koltuk Numaras�:%s\n ",a+1,koltuk[a]);
			}
			
	         }
    	fclose(dosya);
    	
    	int at;
    	printf("\n\n| At��t�rmal�k sat�n almak ister misiniz?\n| Evet -> [1]\n| Hay�r -> [2]\n\n| Se�iminiz -> ");
    	scanf("%d",&at);
    	if(at==1) atistirmalikAl(toplam);
    	else {
    		printf("\n\n\t\t�Y� SEY�RLER D�LER�Z...");
    		
		}
		}
		
	
void aSifre()
{
	char kullanici[6]="admin", sifre[6]="admin";
	char kullanici2[6], sifre2[6];
	int i=0;
	geridon:
	
	printf("\n| Kullan�c� ad�n� giriniz: ");
	scanf("%s",kullanici2);
	printf("| �ifreyi giriniz: ");
	while(i<5)
        { sifre2[i]=getch();
          printf("*");
          i++;
        }
     sifre2[i]='\0';
    
    if(strcmp(kullanici2,kullanici)==0 && strcmp(sifre2,sifre)==0){
    	printf("\n\n| Ho�geldiniz admin.\n");
    	admin();
    } 
    else{
    printf("\n\t\tBA�ARISIZ G�R��...TEKRAR DENEY�N�Z");
    goto geridon;
	}
}
	
void admin()
{   
	int secim;
	geri:
	system("cls");
  	while (secim!=4){
    	printf("\n| Yapmak istedi�iniz i�lemi se�iniz\n|\n| Vizyondaki Filmler -> [1]\n| Film d�zenle -> [2]\n| At��t�rmal�k d�zenle -> [3]\n| �ye silme -> [4]\n| ��k�� -> [5]\n|\n| Se�iminiz -> ");
	    scanf("%d",&secim);
	switch(secim){
	    case 1:
		filmler();
		break;
		case 2:
		filmEkle();
		break;
		case 3:
		atistirmalikDuzenle();
		break;
		case 4:
		uyeSil(secim);
		break;
		case 5:
		main();
		break;
		default:
			printf("\t\tGe�ersiz giri�.Se�im ekran�na y�nlendiriliyorsunuz...");
			goto geri;
		    }
		}
	}  


void filmler()
{
	system("cls");
	FILE *filmler;
	filmler = fopen("filmler.txt" , "r"); //filmler adindaki dosyayi sadece okumak icin r modu ile kullandik
	if (filmler==NULL){
		printf("\n| Dosya bulunamad�.");
	}
	else{
		while(! feof(filmler) ){
   		putchar(fgetc(filmler));
  }
  fclose(filmler);
  printf("\n\n");
}}


void filmEkle()
{
	FILE *dosya;
	film filmler;
	int i ,s, secenek;
	system("cls");
	fflush(stdin);
	printf("| Filmin ad�:  ");
	scanf("%[^\n]s",filmler.filmAdi);
	//printf("\n%s",filmler.filmAdi);
	printf("| Kodu (5 rakamdan olu�mal�d�r):  ");
	scanf("%ld",&filmler.filmKodu);
	printf("| Film �zelli�i; normal=1, altyaz�l�=2, 3D=3, altyaz�l� ve 3D=4:  ");
	scanf("%d",&secenek);
	printf("| T�r:  ");
	scanf("%s",filmler.filmTur);
	printf("| S�re(dakika cinsinden giriniz):  ");
	scanf("%d",&filmler.filmSaat);
	printf("| Ka� seans olacak?:  ");
	scanf("%d",&s);
	for(i=0;i<s;i++){
		printf("%d. seans� giriniz: ",i+1);
		scanf("%s",&filmler.filmSeans[i]);
	}
	printf("| IMDB puan�:  ");
	scanf("%f", &filmler.filmPuan); 
	fflush(stdin);
	printf("| Ozet:\n");
	scanf("%[^\n]s",filmler.filmOzet);
	//printf("\n%s",filmler.filmOzet); 
	dosya = fopen ("filmler.txt","a");
	fprintf( dosya ,"\n\n\n\t--> Film adi: %s\n\t--> Film kodu: %ld\n\t--> Film turu: %s\n\t--> Film suresi: %d dakika\n", filmler.filmAdi , filmler.filmKodu,filmler.filmTur,filmler.filmSaat);
	if(secenek==1) fprintf(dosya,"\t--> Film �zelli�i: Normal\n");
	else if(secenek==2) fprintf(dosya,"\t--> Film �zelli�i: Altyazili\n");
	else if(secenek==3) fprintf(dosya,"\t--> Film �zelli�i: 3D\n");
	else if(secenek==4) fprintf(dosya,"\t--> Film �zelli�i: 3D ve Altyazili\n");
	
    for(i=0;i<s;i++){
		fprintf(dosya,"\t--> %d numarali seans: %.4s0\n",i+1,filmler.filmSeans[i]);
	}
	fprintf(dosya,"\t--> IMDB puani: %.1f\n\t--> Film Ozeti: %s",filmler.filmPuan,filmler.filmOzet);

	fclose(dosya);
	admin();

}
	

void atistirmalikDuzenle()
{
	system("cls");
	printf("\n| Hangi i�lemi yapmak istersiniz?\n|\n| �r�n ekle -> [1]\n| �r�n sil -> [2]\n| �r�nleri g�r�nt�le -> [3]\n| ��k�� -> [4]\n|\n| Se�iminiz -> ");
	int sec;
	scanf("%d",&sec);
	if (sec==1) atistirmalikEkle();
	else if (sec==2) atistirmalikSil();
	else if (sec==3) atistirmalikGoruntule();
	else if (sec==4) admin();
}


void atistirmalikEkle()
{
	FILE *dosya;
	dosya=fopen("atistirmalik.txt","a+");
	atistirmalik a;
	int i, j;
	system("cls");
	printf("\n\n| Ka� adet at��t�rmal�k giri�i olacak?  ");
	scanf("%d",&j);
	for(i=0; i<j; i++){
		fflush(stdin);
 		printf("| Eklenecek at��t�rmal���n\n| Ad�n� giriniz: ");
    	scanf("%[^\n]s",&a.urunAdi);
    	printf("| Fiyat�n� giriniz: ");
    	scanf("%f",&a.urunFiyati);
    	printf("\n");
    	fprintf(dosya, "%s  %f\n",a.urunAdi,a.urunFiyati);
	}
	fclose(dosya);
	admin();
	
}

void atistirmalikSil()
{
	atistirmalik yedekA[15],silinecekA[15];
	char kelime[15];
    printf("\n| Silinecek at��t�rmal��� girin: ");
    scanf("%s",&kelime);
    FILE *dosya;
    dosya=fopen("atistirmalik.txt","r");
    int a=0,i,kacinci;

    while(!feof(dosya)){
        fscanf(dosya,"%s%f",yedekA[a].urunAdi,&yedekA[a].urunFiyati);
        a++;
    }
   
 
    for(i=0;i<(a-1);i++){
        if(strcmp(kelime,yedekA[i].urunAdi)==0){            
		    kacinci=i;
            }
    }

    for(i=0;i<(kacinci);i++){
        strcpy(silinecekA[i].urunAdi,yedekA[i].urunAdi);
        silinecekA[i].urunFiyati=yedekA[i].urunFiyati;
        }

    for(i=(kacinci+1);i<=(a-1);i++){
        strcpy(silinecekA[i-1].urunAdi,yedekA[i].urunAdi);
        silinecekA[i-1].urunFiyati=yedekA[i].urunFiyati;
     }
    fclose(dosya);
 

    FILE *dosya2;
    dosya2=fopen("atistirmalik.txt","w");
    int i2;
    for(i2=0;i2<(a-2);i2++){
        fprintf(dosya2,"%s  %f\n",silinecekA[i2].urunAdi, silinecekA[i2].urunFiyati);
    }
    fclose(dosya2);	
	printf("| �r�n ba�ar�yla kald�r�ld�.\n\n");	
}


void atistirmalikAl(float ucret)
{
	FILE *dosya;
	dosya=fopen("atistirmalik.txt","r");
	atistirmalik al[15];
	int a=0, i, sayi, kod;
	
	while(!feof(dosya)){
		fscanf(dosya,"%s%f",al[a].urunAdi,&al[a].urunFiyati);
		a++;
	}
	printf("\n\n| �r�nler\n");
	for(i=0;i<(a-1);i++){
		printf("| %d->\t%s\t%.2f TL\n",i+1,al[i].urunAdi,al[i].urunFiyati);
	}
	float hesap=0.0;
	printf("| Ka� adet at��t�rmal�k sat�n alacaks�n�z? -> ");
	scanf("%d",&sayi);
	
	for(i=0;i<sayi;i++){
		printf("\n| Alaca��n�z at��t�rmal���n kodunu giriniz -> ");
		scanf("%d",&kod);
		hesap+=al[kod-1].urunFiyati;
	}
	float toplam=hesap+ucret;
	printf("\n\n| At��t�rmal�k toplam�: %.2f",hesap);
	printf("\n| Toplam hesap:  %.2f TL",toplam);
	printf("\n\n   \t\t�Y� SEY�RLER D�LER�Z...");
}

void atistirmalikGoruntule()
{
	FILE *dosya;
	dosya=fopen("atistirmalik.txt","r");
	atistirmalik al[15];
	int a=0, i, sayi, kod;
	float hesap=0;
	while(!feof(dosya)){
		fscanf(dosya,"%s%f",al[a].urunAdi,&al[a].urunFiyati);
		a++;
	}
	printf("\n\n| �r�nler\n");
	for(i=0;i<(a-1);i++){
		printf("| %d->\t%s\t%.2f TL\n",i+1,al[i].urunAdi,al[i].urunFiyati);
	}
	
}

void uyeSil(int s)
{
	kullanici yedek[20], silinecek[20];
	char kisi[20];
	printf("| ��lem uygulanacak ki�inin ad�n� giriniz -> ");
	scanf("%s",&kisi);
	FILE *dosya;
	dosya=fopen("uyeler.txt","r");
	int a=0, b=1, i, kacinci; 
	char yeni[10];
	
	while(!feof(dosya)){
		fscanf(dosya,"%s%s%s%s%s%s",yedek[a].ad,yedek[a].soyad,yedek[a].dogumTarihi,yedek[a].eposta,yedek[a].tel,yedek[a].sifre);
		a++;
	}
	
	for(i=0;i<(a-1);i++){
		if(strcmp(kisi,yedek[i].ad)==0){
			kacinci=i;
		}
	}
	
	for(i=0;i<(kacinci);i++){
		strcpy(silinecek[i].ad,yedek[i].ad);
		strcpy(silinecek[i].soyad,yedek[i].soyad);
		strcpy(silinecek[i].dogumTarihi,yedek[i].dogumTarihi);
		strcpy(silinecek[i].eposta,yedek[i].eposta);
		strcpy(silinecek[i].tel,yedek[i].tel);
		strcpy(silinecek[i].sifre,yedek[i].sifre);
	}
	
	if(s==2){
		b=0;
		printf("\n| Yeni 10 haneli �ifreyi giriniz -> ");
		scanf("%s",&yeni);
	}
	
	for(i=(kacinci+b);i<=(a-b);i++){
		strcpy(silinecek[i-b].ad,yedek[i].ad);
		strcpy(silinecek[i-b].soyad,yedek[i].soyad);
		strcpy(silinecek[i-b].dogumTarihi,yedek[i].dogumTarihi);
		strcpy(silinecek[i-b].eposta,yedek[i].eposta);
		strcpy(silinecek[i-b].tel,yedek[i].tel);
		if(s==2&&i==(kacinci+b)) strcpy(silinecek[i-b].sifre,yeni);
		else strcpy(silinecek[i-b].sifre,yedek[i].sifre);
	}
	fclose(dosya);
	
	FILE *dosya2;
	dosya2=fopen("uyeler.txt","w");
	int i2;
	for(i2=0;i2<(a-b);i2++){
		fprintf(dosya,"%s\n%s\n%s\n%s\n%s\n%s\n\n",silinecek[i2].ad,silinecek[i2].soyad,silinecek[i2].dogumTarihi,silinecek[i2].eposta,silinecek[i2].tel,silinecek[i2].sifre);
	}
	fclose(dosya2);
	if(s==2) printf("\n\t\tYeni �ifre ba�ar�yla kaydedildi.\n\n");
	else printf("\n\t\t�yelik ba�ar�yla silinmi�tir.\n\n");
	main();
}
