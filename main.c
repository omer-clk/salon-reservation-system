#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIFRE 48

#ifdef _WIN32
#define EKRANI_TEMIZLE "cls"
#else
#define EKRANI_TEMIZLE "clear"
#endif

char musteriAd[20][30];
char musteri_Telefon[20][12];
int toplam_Randevu = 0;

void Menu_Ana();
void Sira_Al();
void Sira_Sorgula();
void kuafor_Girisi();
void Dosya_Yaz();
void Dosya_Oku();

int main() 
{
	int secim;
	
	Dosya_Oku();
	printf("Kuafor Randevu Sistemine Hosgeldiniz!\nAna Menuye yonlendiriliyorsunuz...\n");
	while(1)
	{
		Menu_Ana();
		scanf("%d",&secim);
		system(EKRANI_TEMIZLE); //geçmiş temizlemek
		while(getchar() != '\n');
		if(secim == 1)
		{
			printf("\"Sira Al\" islemi secildi\n");
			Sira_Al();
		}
		else if(secim == 2)
		{
			printf("\"Sira sorgula/iptal et\" islemi secildi\n");
			Sira_Sorgula();
		}
		else if(secim == 3)
		{
			printf("\"Kuafor girisi\" islemi secildi\n");
			kuafor_Girisi();
		}
		else if(secim == 4)
		{
			printf("Sistemden cikiliyor. Hoscakalin!\n");
			break;
		}
		else
		{
			printf("Hatali deger girdiniz! Lutfen size sunulan secenekler arasindan [1-4] secim yapiniz!\n");
		}
	}
	return 0;
}
void Menu_Ana()
{
	printf("-----Ana Menu-----\n");
	printf("Mevcut Sira: %d / 20\n", toplam_Randevu);
	printf("Lutfen islem seciniz:\n");
	printf("1-Sira Al\n2-Sira Sorgula/iptal et\n3-Kuafor Girisi\n4-Cikis\n");
	printf("---\t---\t---\t---\t---\t---\n");
	printf("Seciminiz:\n");
}
void Dosya_Yaz()
{
	int i=0;
	FILE *dosya = fopen("kayitlarim.txt","w");
	
	if(dosya == NULL)
	{
		printf("Dosya olusturulamadi!!!\n");
		return;
	}
	for(i=0;i<toplam_Randevu;i++)
	{
		fprintf(dosya, "%s\n", musteriAd[i]);
		fprintf(dosya, "%s\n", musteri_Telefon[i]);
	}
		fclose(dosya);
}
void Dosya_Oku()
{
	FILE *dosya = fopen("kayitlarim.txt", "r");
	if(dosya == NULL)
	{
		return;
	}
	while(fgets(musteriAd[toplam_Randevu], 30, dosya) != NULL)
	{
	musteriAd[toplam_Randevu][strcspn(musteriAd[toplam_Randevu], "\n")] = 0;
	fscanf(dosya, "%s", musteri_Telefon[toplam_Randevu]);
	fgetc(dosya); //alt satıra geçmesi için(enteri okuma)
	toplam_Randevu++;
	}
	fclose(dosya);
}
void Sira_Al()
{
	if(toplam_Randevu < 20)
	{
		printf("Lutfen isim soyisim giriniz:\n");
		fgets(musteriAd[toplam_Randevu], 30, stdin);
		musteriAd[toplam_Randevu][strcspn(musteriAd[toplam_Randevu], "\n")] = 0;
		printf("Telefon numarasi giriniz (basinda 0 ile):\n");
		scanf("%s", musteri_Telefon[toplam_Randevu]);
		getchar();
		printf("Sayin %s, Basari ile siraya eklendiniz\nSira numarasi:%d\n", musteriAd[toplam_Randevu], toplam_Randevu + 1);
		toplam_Randevu++;
		Dosya_Yaz();
	}
	else
	{
		printf("Uzgunuz liste(20) su anda dolu :(\n");
	}
}
void Sira_Sorgula()
{
	char kayitli_Telefon[12];
	int bulundu = 0;
	int i, j;
	char iptal_islemi;
	
	if(toplam_Randevu == 0)
	{
		printf("liste bos!!!\n");
		return;
	}
	printf("Lutfen kayitli telefon numaranizi giriniz:\n");
	scanf("%s", kayitli_Telefon);
	getchar();
	for(i=0; i<toplam_Randevu; i++)
	{
		if(strcmp(musteri_Telefon[i], kayitli_Telefon)==0) //0 sa metinler aynısı birbirinin (aradaki fark 0)
		{
			printf("Sira bulundu!\nisim soyisim:%s\nSira No:%d\n",musteriAd[i], i+1);
			bulundu=1;
			
			printf("Randevunuzu iptal etmek isterseniz \"e\" tusuna basiniz\n");
			scanf("%c", &iptal_islemi);
			getchar();
			if(iptal_islemi == 'e' || iptal_islemi == 'E')
			{
				for(j=i;j<toplam_Randevu-1;j++)
				{
				strcpy(musteriAd[j],musteriAd[j+1]);
				strcpy(musteri_Telefon[j],musteri_Telefon[j+1]);
				}
			toplam_Randevu--; //en sondaki kişi
			printf("Randevunuz basari ile iptal edilmistir...\n");
			Dosya_Yaz();
			}
			else
			{
				printf("iptal islemi gerceklestirilmedi!\n");
			}
			break;
		}
	}
	if(bulundu==0)
	{
		printf("bu numaraya ait randevu bulanamadi...\n");
	}
}
void kuafor_Girisi()
{
	int girilenSifre;
	int i=0;
	printf("Sayin kuafor lutfen sifrenizi giriniz:\n");
	scanf("%d", &girilenSifre);
	getchar();
	if(girilenSifre == SIFRE)
	{
		printf("Sifre dogru! Hosgeldiniz!\n");
		printf("\n-------------------------------------------------\n");
		printf("\n-------------------------------------------------\n");
		printf("Sira || ISIM SOYISIM || TELEFON NO\n");
		printf("\n-------------------------------------------------\n");
		if(toplam_Randevu==0)
		{
			printf("Listede su an kimse yok!\n");
		}
		else
		{
			for(i=0;i<toplam_Randevu;i++)
			{
				printf("%d  |  %s  |  %s\n",i+1,musteriAd[i], musteri_Telefon[i]);
			}
		}
	}
	else
	{
		printf("Hatali sifre girdiniz!!!\n");
	}
}
