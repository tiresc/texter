#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phone {
  char *company;
  char *sms;
  char *mms;
  long number;
  char full_number[50];
  char strnumber[50];
};

long get_number(void){
  long num;
  int c = 0;
  puts("What is the number?");
  fscanf(stdin, "%ld", &num);
  printf("%ld\n",num);
  return num;
}
int main(void){
  //companies/, mms addresses, sms addresses
  char *companies[]={"Cricket Wireless", "Boost Mobile", "AT&T", "Google Project Fi", "Republic Wireless", "Sprint", "Straight Talk", "T-Mobile", "Ting", "Tracfone","U.S. Cellular", "Verizon", "Virgin Mobile"};
  char *sms[]={"@mms.cricketwireless.net","@sms.myboostmobile.com", "@txt.att.net", "@msg.fi.google.com","@text.republicwireless.com", "@messaging.sprintpcs.com","@vtext.com","@tmomail.net","@message.ting.com","@mmst5.tracfone.com","@email.uscc.net","@vtext.com","@vmobl.com"};
  char *mms[] = {"@mms.cricketwireless.net", "@myboostmobile.com", "@mms.att.net", "@msg.fi.google.com","@text.republicwireless.com", "@pm.sprint.com", "@mypixmessages.com", "@tmomail.net","@message.ting.com","@mmst5.tracfone.com","@mms.uscc.net","@vzwpix.com","@vmpix.com"};

  // gets size of *companies[]
  int company_size = sizeof(companies)/sizeof(char*);
  int answer = 0;

  // Displays all companies to choose from
  for(int i = 0; i < company_size; i++){
      printf("%d. %s\n",i+1, companies[i]);
  }

  fscanf(stdin, "%d", &answer);
  long numbers = get_number();
  answer--;
  for(int i = 1; i < company_size; ++i){
      if(answer == i){
        printf("%d", answer);
        struct phone text_phone = {companies[i], sms[i], mms[i], numbers};
        snprintf(text_phone.strnumber, 10, "%ld", numbers);
        strcat(text_phone.strnumber, text_phone.sms);

        printf("company: %s\n", text_phone.company);
        printf("%s\n",text_phone.strnumber);
      }
    }


  return 0;
}
