#include "List.h"

void createlist_TBA(list_TBA &L){
    first(L) = NIL;
    last(L) = NIL;
}
address_TBA alokasi_TBA(string x){
    address_TBA P = new elmtlist_TBA;
	info(P) = x;
	next(P) = NIL;
	prev(P) = NIL;
	return P;
}
void dealokasi_TBA(address_TBA &P){
    next(P) = NIL;
	prev(P) = NIL;
	delete P;
	P = NIL;
}

//insert
void insertlast_TBA(list_TBA &L, string a){
    address_TBA P = alokasi_TBA(a);
    if(first(L)==NIL){
        first(L)=P;
        last(L)=P;
    } else{
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=next(last(L));
    }
}

void deletefirst_TBA(list_TBA &L, address_TBA &P){

}
void deletelast_TBA(list_TBA &L, address_TBA &P){

}
void deletepilih(list_TBA &L, address_TBA &P){

}
void printinfo_TBA(list_TBA L, address_TBA P){
    cout<<" "<<info(P);
}
