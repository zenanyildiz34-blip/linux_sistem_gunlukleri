#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Syslog kayıtlarını tutacak düğüm yapısı
*/

typedef struct LogNode {

    char message[300];
    struct LogNode *next;

} LogNode;


/*
    Yeni düğüm oluşturur
*/

LogNode* createNode(char *msg)
{
    LogNode *newNode = (LogNode*)malloc(sizeof(LogNode));

    strcpy(newNode->message, msg);

    newNode->next = NULL;

    return newNode;
}


/*
    Bağlı listenin sonuna log ekler
*/

void addLog(LogNode **head, char *msg)
{

    LogNode *newNode = createNode(msg);

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    LogNode *temp = *head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

}


/*
    Tüm logları yazdırır
*/

void printLogs(LogNode *head)
{
    LogNode *temp = head;

    while(temp != NULL)
    {
        printf("%s", temp->message);
        temp = temp->next;
    }
}


/*
    Hata loglarını filtreler
*/

void printErrorLogs(LogNode *head)
{
    LogNode *temp = head;

    printf("\n--- ERROR LOGS ---\n");

    while(temp != NULL)
    {

        if(strstr(temp->message,"error") || strstr(temp->message,"failed"))
        {
            printf("%s", temp->message);
        }

        temp = temp->next;
    }
}


/*
    Toplam log sayısını hesaplar
*/

int countLogs(LogNode *head)
{
    int count = 0;

    LogNode *temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}


/*
    Syslog dosyasını okuyup listeye ekler
*/

void readSyslog(LogNode **head)
{

    FILE *file;

    char buffer[300];

    file = fopen("/var/log/syslog","r");

    if(file == NULL)
    {
        printf("Syslog dosyasi acilamadi\n");
        return;
    }

    while(fgets(buffer,sizeof(buffer),file))
    {
        addLog(head,buffer);
    }

    fclose(file);
}


int main()
{

    LogNode *head = NULL;

    readSyslog(&head);

    printf("\n--- SYSLOG KAYITLARI ---\n\n");

    printLogs(head);

    printf("\nToplam Log Sayisi: %d\n", countLogs(head));

    printErrorLogs(head);

    return 0;
}