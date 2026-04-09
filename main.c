#include <stdio.h>
#include <string.h>
#include <time.h>

void gunluk_oku();
void yeni_gunluk();

int main()
{

    int menu = 1;

    while (menu == 1)
    {
        int secim;
        printf("\n\t___<3_Kisisel_Gunluk_Tutma_Platformuna_Hosgeldin_<3___\n");
        printf("\n1- Yeni bir gunluk sayfasi ac"
               "\n2- Eski gunluk sayfalarini oku"
               "\n3- Tekrar gorusmek uzere"
               "\n\nSecimin: ");

        scanf("%d", &secim);
        while (getchar() != '\n');

        switch (secim)
        {
            case 1:
                yeni_gunluk();
                break;

            case 2:
                gunluk_oku();
                break;

            case 3:
                menu = 0;
                break;

            default:
                printf("\nSanirim yanlis giris yaptiniz.\n");
                break;
        }
    }

    return 0;
}

void yeni_gunluk()
{
    FILE *gunluk = fopen("gunluk.txt", "a");
    if (gunluk == NULL)
    {
        printf("\nMaalesef gunluk dosyasina ulasilamadi...\n");
        return;
    }

    time_t simdi;
    struct tm *zaman_bilgisi;

    time(&simdi);  // þu anki zamaný al
    zaman_bilgisi = localtime(&simdi);  // yerel zamana çevir

    char metin[1000];
    printf("\nTarih: %02d/%02d/%d\n",
           zaman_bilgisi->tm_mday,
           zaman_bilgisi->tm_mon + 1,
           zaman_bilgisi->tm_year + 1900);
    printf("Merhaba Sevgili Gunluk;\n");
    fgets(metin, sizeof(metin), stdin);
    metin[strcspn(metin, "\n")] = '\0';
    fprintf(gunluk,"%02d/%02d/%d /n "
           ,zaman_bilgisi->tm_mday,
           zaman_bilgisi->tm_mon + 1,
           zaman_bilgisi->tm_year + 1900 );
    fputs("Merhaba Sevgili Gunluk; /n ",gunluk);
    fprintf(gunluk, "%s", metin);
    fputs(" /n /n ",gunluk);

    fclose(gunluk);
}

void gunluk_oku(void)
{
    FILE *gunluk = fopen("gunluk.txt", "r");
    if (gunluk == NULL)
    {
        printf("\nMaalesef gunluk dosyasina ulasilamadi...\n");
        return;
    }

    char kelime[50];

    printf("\n");

    while (fscanf(gunluk, "%49s",kelime) == 1)
    {
            if(strcmp(kelime,"/n")==0)
            printf("\n");
            else
            printf("%s ", kelime);


    }

    fclose(gunluk);
}
