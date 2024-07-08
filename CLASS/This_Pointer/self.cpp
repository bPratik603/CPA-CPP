#include<iostream>
#include<cstdio>
#include<cstring>

class Date
{
  private:
    int day,month,year;

    bool is_valid(int dd,int mm,int yy)
    {
       if(dd <= 00 || dd>31)
       {
        return(false);
       }
       if(mm <= 00 || mm>12)
       {
        return(false);
       }
       if(yy <= 0)
       {
         return(false);
       }

       return(true);
    }
  
  public:
    Date(char* strDate)
    {
         size_t L = strlen(strDate);
         char* cc_strDate = (char*)malloc(L + 1);
         if(cc_strDate == NULL)
         {
          puts("Error in allocating memory");
          exit(EXIT_FAILURE);
         }

         *(cc_strDate + L) = '\0';
         strncpy(cc_strDate,strDate,L);

         char* str_day = strtok(cc_strDate,"-");
         char* str_month = strtok(NULL,"-");
         char* str_year = strtok(NULL,"-");

         day = atoi(str_day);
         month = atoi(str_month);
         year = atoi(str_year);       
    
        free(cc_strDate);
        cc_strDate = NULL;
      }
       bool show()
      {
         if(!is_valid(day,month,year))
         {
            printf("Invalid Date...!");
            return(false);
         }
         
         printf("Date : %d-%d-%d\n",day,month,year);
         return(true);
    }
};





int main()
{
  Date d1("1-2-2023");
  d1.show();
   
   return(0);
}