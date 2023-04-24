#include<bits/stdc++.h>
using namespace std;
const string Tzolkin[]={ "imix", "ik", "akbal", "kan", "chicchan", 
                                  "cimi", "manik", "lamat", "muluk", "ok", 
                                  "chuen", "eb", "ben", "ix", "mem", 
                                  "cib", "caban", "eznab", "canac", "ahau" };
//1-20
int findmonth(string monthstr);
int main(){
    long long int testcase;
    cin>>testcase;
    cout<<testcase<<endl;
    long long int day,year,month,totalday=0;
    char trash;
    string monthstr;
    while(testcase--){
        totalday=0;
        scanf("%d.",&day);
        cin>>monthstr;
        scanf("%d",&year);
        month=findmonth(monthstr);
        
        totalday=year*365+month*20+day;
        cout<<totalday%13+1<<" "<<Tzolkin[totalday%20]<<" "<<totalday/260<<endl;
    }
    

}
int findmonth(string monthstr){
  if( monthstr == "pop" ) return 0;
  if( monthstr == "no" ) return 1;
  if( monthstr == "zip" ) return 2;
  if( monthstr == "zotz" ) return 3;
  if( monthstr == "tzec" ) return 4;
  if( monthstr == "xul" ) return 5;
  if( monthstr == "yoxkin" ) return 6;
  if( monthstr == "mol" ) return 7;
  if( monthstr == "chen" ) return 8;
  if( monthstr == "yax" ) return 9;
  if( monthstr == "zac" ) return 10;
  if( monthstr == "ceh" ) return 11;
  if( monthstr == "mac" ) return 12;
  if( monthstr == "kankin" ) return 13;
  if( monthstr == "muan" ) return 14;
  if( monthstr == "pax" ) return 15;
  if( monthstr == "koyab" ) return 16;
  if( monthstr == "cumhu" ) return 17;
  if( monthstr == "uayet" ) return 18;
}