// BERKAN ACIKGOZ
// 02180201072
// 3. Sýnýf

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
bool ayrac(char ch) // Ayraclar
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        	return (true);
    return (false);
}
 
bool islem(char ch) // Operatorler
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        	return (true);
    return (false);
}
 
bool sayilar(char* str) //Sayi tanim
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || (str[0]) == true)
        	return (false);
    return (true);
}
 
bool deyim(char* str) // fonksiyon cagrimlari icin kontrol
{
    if (!strcmp(str, "if") || !strcmp(str, "else")
        || !strcmp(str, "while") || !strcmp(str, "do")
        || !strcmp(str, "break") || !strcmp(str, "void")
        || !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "long") || !strcmp(str, "short")
        || !strcmp(str, "switch") || !strcmp(str, "static"))
        	return (true);
    return (false);
}
 
bool isInteger(char* str) // Integer kontrol
{
    int i, len = strlen(str);
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            	return (false);
    }
    return (true);
}
 
bool sayi(char* str) // Sayi kontrol
{
    int i, len = strlen(str);
    bool hasDecimal = false;
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            	return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}
 
char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}
 
void parcala(char* str) // Kod bloklarini parcalayarak yazdirma
{
    int left = 0, right = 0;
    int len = strlen(str);
    printf("Ayrik Hali: ");
    
    while (right <= len && left <= right)
	{
    	
        if (ayrac(str[right]) == false)
            right++;
 
        if (ayrac(str[right]) == true && left == right)
		{
            if (islem(str[right]) == true)
                printf("'%c' ,", str[right]);
 
        right++;
        left = right;
        }
		else if (ayrac(str[right]) == true && left != right|| (right == len && left != right))
		{
            char* subStr = subString(str, left, right - 1);
 
            if (deyim(subStr) == true)
                printf("'%s' ,", subStr);
 
            else if (isInteger(subStr) == true)
                printf("'%s' ,", subStr);
 
            else if (sayi(subStr) == true)
                printf("'%s' ,", subStr);
 
            else if (sayilar(subStr) == true
                     && ayrac(str[right - 1]) == false)
                printf("'%s' ,", subStr);
 
            else if (sayilar(subStr) == false&& ayrac(str[right - 1]) == false)
                printf("'%s ',", subStr);
            left = right;
        }
    }
    return;
}
 
int main()
{
   FILE *fp;
   char str[255];
   char strtemp[10];
   char adres[50];
   printf("Dosya adini girin (Ornek: dosya.txt):");
   gets(adres);
   fp = fopen(adres,"r");
   fscanf(fp, "%s", str);
   
   printf("1: %s\n", str );
   parcala(str);
   printf("\n-----------------------------------\n");
   int abc,kb;
   for(abc=2;abc<=30;abc++) //Kod blogunu ayirma (Max 30 satir)
   {	
		fgets(str, 255, (FILE*)fp);
		printf("%d: %s\n",(abc),str );
    	parcala(str); //Bloklari parcalama
    	printf("\n-----------------------------------\n");
   		if(strtemp[0]==str[0] && strtemp[1]==str[1] && strtemp[2]==str[2] && strtemp[3]==str[3])
		{
			break; //Satir tekrarini engelleme
		}
   		for(kb=0;kb<4;kb++)
   		{
   			strtemp[kb]=str[kb];
		}
   }
   fclose(fp);
   printf("Adim adim tokenizing islemi gerceklestirildi."); //Tokenizing iþlemi gerçekleþtirildi.
   
   return (0);
}
