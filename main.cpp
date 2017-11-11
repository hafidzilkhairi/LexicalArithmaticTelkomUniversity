#include "List.h"
#include <iostream>

using namespace std;
list_TBA L;
int skipspasipertama(string a,int idx){
    //menerima index yang telah spasi dan akan dilewati atau berindex -1;
    bool sampai = false;
    int i = a.length();
    while(idx<i && a[idx]==' '){
        idx+=1;
    }
    return idx;
}

bool ceknomor(char a){
    bool c = false;
    string b="1234567890";
    for(int i=0;i<10;i++){
        if(a==b[i]){
            c=true;
        }
    }
    return c;
}
void isnum(string a, bool bolehtanda, bool ekoma,bool &pengecek,int &idx){
    int i=a.length();
    int j=idx;
    idx=skipspasipertama(a,j);
    if(idx<i&& pengecek==true){
        if(bolehtanda==true&&(a[idx]=='+'||a[idx]=='-')&& pengecek==true){
            bolehtanda=false;
            idx+=1;
            isnum(a,bolehtanda,ekoma,pengecek,idx);
        }else if(ceknomor(a[idx])==true&&(idx==i-1||a[idx+1]==' '||a[idx+1]==')')&& pengecek==true){
            insertlast_TBA(L,"NUM");
            idx+=1;
        }else if(ceknomor(a[idx])==true&& pengecek==true){
            bolehtanda=false;
            idx+=1;
            isnum(a,bolehtanda,ekoma,pengecek,idx);
        }else if((a[idx]=='E'||a[idx]==',')&&ekoma==true&& pengecek==true){
            if(a[idx]=='E'){
                bolehtanda=true;
                ekoma=false;
                idx+=1;
                isnum(a, bolehtanda, ekoma, pengecek, idx);
            }else if(a[idx]==','){
                ekoma=false;
                idx+=1;
                isnum(a,bolehtanda,ekoma,pengecek,idx);
            }
        }else if(pengecek==true){
            pengecek =false;
            insertlast_TBA(L,"ERROR");
            idx+=1;
        }
    }else if (pengecek==true){
        pengecek = false;
        insertlast_TBA(L,"ERROR");
        idx+=1;
    }
}

void idbukurtup(char a, bool &pengecek, int &hitung){
    if(a=='('){
        hitung+=1;
        insertlast_TBA(L,"BUKUR");

    }else if(a==')'){
        hitung-=1;
        if(hitung<0){
            pengecek=false;
            insertlast_TBA(L,"ERROR");
        }else{
            insertlast_TBA(L,"TUKUR");
        }
    }
}

void isopr(string a, bool &pengecek,int &hitung, int &idx){
    int i = a.length();
    int j=idx;
    idx = skipspasipertama(a,j);
    if(a[idx]=='X'||a[idx]=='x'||a[idx]=='+'||a[idx]=='-'||a[idx]==':'){
        if(idx<i){
            if(a[idx+1]==' '){
                insertlast_TBA(L,"OPR");
                idx+=1;
            }else if(a[idx]=='+'||a[idx]=='-'){
                isnum(a,true,true,pengecek,idx);
            }else if(idx==i-1){
                insertlast_TBA(L,"OPR");
                idx+=1;
            }else{
                pengecek =false;
                insertlast_TBA(L,"ERROR");
                idx+=1;
            }
        }else{
            pengecek =false;
            insertlast_TBA(L,"ERROR");
            idx+=1;
        }
    }else if(ceknomor(a[idx])){
        isnum(a,true,true,pengecek,idx);
    }else if(a[idx]=='('||a[idx]==')'){
        idbukurtup(a[idx],pengecek,hitung);
        idx+=1;
    }
}


int main()
{
    bool pengecek = true;
    int hitung =0;
    string a;
    int idx = 0;
    createlist_TBA(L);
    address_TBA p;
    cout << "Masukkan : " << endl;
    getline(cin,a);
    int i=a.length();
    while(idx<i && pengecek==true){
        //isnum(a,true,true, pengecek,idx);
        isopr(a,pengecek,hitung,idx);
    }
    if(hitung>0)insertlast_TBA(L,"ERROR");
    p=first(L);
    while(p!=NIL){
        printinfo_TBA(L,p);
        p=next(p);
    }
    return 0;
}
