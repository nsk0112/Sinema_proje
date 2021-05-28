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
	printf("\n%60s%38s\n" ,"HOÞGELDÝNÝZ!","");
	printf("| Üye ol -> [1]\n| Üye giriþi -> [2]\n| Admin iþlemleri -> [3]\n| Çýkýþ -> [4]\n|\n| Seçiminiz -> ");
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
    printf("\n| Kayýt iþlemi sýrasýnda Türkçe karakter kullnmayýnýz.\n");
    printf("| E-posta adresi giriþinde G-Mail adresinizi kullanýnýz ve @ iþaretinden önceki kýsmýný giriniz.\n\n");
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
	printf("\t\t| Doðum tarihi: ");
	scanf("%s",&uye.dogumTarihi);
	fprintf(uyeler,"%s\n",&uye.dogumTarihi);
	printf("\t\t| Telefon numarasý: 0");
    scanf("%s",&uye.tel);
    fprintf(uyeler,"%s\n",&uye.tel);
	printf("\t\t| E-posta adresi: ");
	scanf("%s",&uye.eposta);
	fprintf(uyeler,"%s\n",&uye.eposta);
	printf("\t\t| Þifrenizi belirleyiniz:(10 karakterli olmak zorundadýr.) ");
	scanf("%s",&uye.sifre);
	fprintf(uyeler,"%s\n\n",&uye.sifre);
	fclose(uyeler);
	printf("\n\n\t\t\t| ÜYELÝK BAÞARIYLA OLUÞTURULDU. HOÞGELDÝNÝZ %s!\n\t\t\t| FÝLM SEÇME EKRANINA GÝTMEK ÝÇÝN HERHANGÝ BÝR TUÞA TIKLAYINIZ.",strupr(uye.ad));
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
	printf("\n\t-Þifre: ");
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
            { printf("\n\n\t\tHOÞGELDÝNÝZ!\n\n| Film seçimi -> [1]\n| Þifre deðiþtirme -> [2]\n| Üyelik iptali -> [3]\n|\n| Seçiminiz -> ");
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
    printf("\n\t\t**BAÞARISIZ GÝRÝÞ...TEKRAR DENEYÝNÝZ**");
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
    printf("\n\t\t| SEÇMEK ÝSTEDÝÐÝNÝZ FÝLMÝN KODUNU GÝRÝNÝZ |\n");
    printf("\t\t");
    for(i=1;i<=44;i++){
		printf("-");
	}
    printf("\n\t\t| Film Kodu:");              
    scanf("%d",&kod);
    printf("\t\t| Seçtiðiniz seans (örneðin 11.00): ");
    scanf("%s",&seans);
				
				//while(fscanf(filmler,"%ld",kod)!=EOF){
				//	fscanf(filmler,"")
				//}
				
	printf("\t\t| Öðrenci bileti sayýsý: ");
	scanf("%d",&okisi);
	printf("\t\t| Tam bilet sayýsý: ");
	scanf("%d",&tamkisi);
	for(i=0;i<okisi;i++){
		toplam=toplam+ogr;
	}
	for(i=0;i<tamkisi;i++){
			       toplam=toplam+tam;
				}
				
	kisi=okisi+tamkisi;
	printf("\n\n\n\n\t\t->Toplam Bilet Tutarý:%0.2f\n\n",toplam);
				
	for(i=0;i<7;i++){
		printf("\t\t%c",harf[i]);
		for(j=0;j<10;j++){
			printf("%d",j);
			printf(" __   ");
		}
		printf("\n\n\n");
	}
	printf("\t\t----------------------------- P E R D E ----------------------------- \n");
	printf("\t\tKoltuðunuzu Seçiniz:\n\n ");
	for(a=0;a<kisi;a++)	{
		printf("\t\t-> ");
		scanf("%s[^\n]",koltuk[a]);
		}
		printf("\t\t\n\n\t/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / \n");
		printf("\n\t\t***SON BÝLET BÝLGÝLERÝ OLUÞTURULUYOR***\n\n");
				
				
		printf("\t\tSon Bilet Bilgileri:\n \t\t|  Bilet tutarý: %0.2f\n \t\t|  Öðrenci Bileti Sayýsý: %d\n \t\t|  Tam Bilet Sayýsý: %d\n \t\t|  Film Kodu: %d\n \t\t|  Seans: %s\n ",toplam,okisi,tamkisi,kod,seans);
		printf("\t\t|  Koltuk Numarasý: \n");
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
		printf("Dosya oluþturulamadý...");
     	}
	    else {
	    	fprintf(dosya,"\t\t\t***BÝLET BÝLGÝLERÝ***\n ");
		fprintf(dosya,"\t\t-->Ödenen:%f\n\t\t-->Film:%d\n\t\t-->Kiþi sayýsý:%d\n\t\t-->Seans:%s\n",toplam,kod,kisi,seans);
			for(a=0;a<kisi;a++)
			{
				fprintf(dosya,"\t\t-->%d.Koltuk Numarasý:%s\n ",a+1,koltuk[a]);
			}
			
	         }
    	fclose(dosya);
    	
    	int at;
    	printf("\n\n| Atýþtýrmalýk satýn almak ister misiniz?\n| Evet -> [1]\n| Hayýr -> [2]\n\n| Seçiminiz -> ");
    	scanf("%d",&at);
    	if(at==1) atistirmalikAl(toplam);
    	else {
    		printf("\n\n\t\tÝYÝ SEYÝRLER DÝLERÝZ...");
    		
		}
		}
		
	
void aSifre()
{
	char kullanici[6]="admin", sifre[6]="admin";
	char kullanici2[6], sifre2[6];
	int i=0;
	geridon:
	
	printf("\n| Kullanýcý adýný giriniz: ");
	scanf("%s",kullanici2);
	printf("| Þifreyi giriniz: ");
	while(i<5)
        { sifre2[i]=getch();
          printf("*");
          i++;
        }
     sifre2[i]='\0';
    
    if(strcmp(kullanici2,kullanici)==0 && strcmp(sifre2,sifre)==0){
    	printf("\n\n| Hoþgeldiniz admin.\n");
    	admin();
    } 
    else{
    printf("\n\t\tBAÞARISIZ GÝRÝÞ...TEKRAR DENEYÝNÝZ");
    goto geridon;
	}
}
	
void admin()
{   
	int secim;
	geri:
	system("cls");
  	while (secim!=4){
    	printf("\n| Yapmak istediðiniz iþlemi seçiniz\n|\n| Vizyondaki Filmler -> [1]\n| Film düzenle -> [2]\n| Atýþtýrmalýk düzenle -> [3]\n| Üye silme -> [4]\n| Çýkýþ -> [5]\n|\n| Seçiminiz -> ");
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
			printf("\t\tGeçersiz giriþ.Seçim ekranýna yönlendiriliyorsunuz...");
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
		printf("\n| Dosya bulunamadý.");
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
	printf("| Filmin adý:  ");
	scanf("%[^\n]s",filmler.filmAdi);
	//printf("\n%s",filmler.filmAdi);
	printf("| Kodu (5 rakamdan oluþmalýdýr):  ");
	scanf("%ld",&filmler.filmKodu);
	printf("| Film özelliði; normal=1, altyazýlý=2, 3D=3, altyazýlý ve 3D=4:  ");
	scanf("%d",&secenek);
	printf("| Tür:  ");
	scanf("%s",filmler.filmTur);
	printf("| Süre(dakika cinsinden giriniz):  ");
	scanf("%d",&filmler.filmSaat);
	printf("| Kaç seans olacak?:  ");
	scanf("%d",&s);
	for(i=0;i<s;i++){
		printf("%d. seansý giriniz: ",i+1);
		scanf("%s",&filmler.filmSeans[i]);
	}
	printf("| IMDB puaný:  ");
	scanf("%f", &filmler.filmPuan); 
	fflush(stdin);
	printf("| Ozet:\n");
	scanf("%[^\n]s",filmler.filmOzet);
	//printf("\n%s",filmler.filmOzet); 
	dosya = fopen ("filmler.txt","a");
	fprintf( dosya ,"\n\n\n\t--> Film adi: %s\n\t--> Film kodu: %ld\n\t--> Film turu: %s\n\t--> Film suresi: %d dakika\n", filmler.filmAdi , filmler.filmKodu,filmler.filmTur,filmler.filmSaat);
	if(secenek==1) fprintf(dosya,"\t--> Film özelliði: Normal\n");
	else if(secenek==2) fprintf(dosya,"\t--> Film özelliði: Altyazili\n");
	else if(secenek==3) fprintf(dosya,"\t--> Film özelliði: 3D\n");
	else if(secenek==4) fprintf(dosya,"\t--> Film özelliði: 3D ve Altyazili\n");
	
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
	printf("\n| Hangi iþlemi yapmak istersiniz?\n|\n| Ürün ekle -> [1]\n| Ürün sil -> [2]\n| Ürünleri görüntüle -> [3]\n| Çýkýþ -> [4]\n|\n| Seçiminiz -> ");
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
	printf("\n\n| Kaç adet atýþtýrmalýk giriþi olacak?  ");
	scanf("%d",&j);
	for(i=0; i<j; i++){
		fflush(stdin);
 		printf("| Eklenecek atýþtýrmalýðýn\n| Adýný giriniz: ");
    	scanf("%[^\n]s",&a.urunAdi);
    	printf("| Fiyatýný giriniz: ");
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
    printf("\n| Silinecek atýþtýrmalýðý girin: ");
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
	printf("| Ürün baþarýyla kaldýrýldý.\n\n");	
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
	printf("\n\n| Ürünler\n");
	for(i=0;i<(a-1);i++){
		printf("| %d->\t%s\t%.2f TL\n",i+1,al[i].urunAdi,al[i].urunFiyati);
	}
	float hesap=0.0;
	printf("| Kaç adet atýþtýrmalýk satýn alacaksýnýz? -> ");
	scanf("%d",&sayi);
	
	for(i=0;i<sayi;i++){
		printf("\n| Alacaðýnýz atýþtýrmalýðýn kodunu giriniz -> ");
		scanf("%d",&kod);
		hesap+=al[kod-1].urunFiyati;
	}
	float toplam=hesap+ucret;
	printf("\n\n| Atýþtýrmalýk toplamý: %.2f",hesap);
	printf("\n| Toplam hesap:  %.2f TL",toplam);
	printf("\n\n   \t\tÝYÝ SEYÝRLER DÝLERÝZ...");
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
	printf("\n\n| Ürünler\n");
	for(i=0;i<(a-1);i++){
		printf("| %d->\t%s\t%.2f TL\n",i+1,al[i].urunAdi,al[i].urunFiyati);
	}
	
}

void uyeSil(int s)
{
	kullanici yedek[20], silinecek[20];
	char kisi[20];
	printf("| Ýþlem uygulanacak kiþinin adýný giriniz -> ");
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
		printf("\n| Yeni 10 haneli þifreyi giriniz -> ");
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
	if(s==2) printf("\n\t\tYeni þifre baþarýyla kaydedildi.\n\n");
	else printf("\n\t\tÜyelik baþarýyla silinmiþtir.\n\n");
	main();
}
