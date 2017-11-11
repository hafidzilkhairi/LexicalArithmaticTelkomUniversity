#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include<iostream>
using namespace std;
#define NIL NULL
#define next(P) (P)->next
#define first(L) (L).first
#define last(L) (L).last
#define prev(L) (L)->prev
#define info(P) (P)->info

typedef struct elmtlist_TBA *address_TBA;
struct elmtlist_TBA{
    string info;
    address_TBA next;
    address_TBA prev;
};

struct list_TBA{
    address_TBA first;
    address_TBA last;
};

void createlist_TBA(list_TBA &L);
address_TBA alokasi_TBA(string x);
void dealokasi_TBA(address_TBA &P);

//insert
void insertlast_TBA(list_TBA &L, string a);

void deletefirst_TBA(list_TBA &L, address_TBA &P);
void deletelast_TBA(list_TBA &L, address_TBA &P);
void deletepilih(list_TBA &L, address_TBA &P);

address_TBA findelm_TBA(list_TBA L, string x);
void printinfo_TBA(list_TBA L, address_TBA P);


#endif // LIST_H_INCLUDED
