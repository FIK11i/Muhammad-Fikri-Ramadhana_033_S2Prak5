#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

//deklarasi simpul
struct node
{
	int data;
	struct node *next;
};

node *awal;
node* akhir;
node* curr;
node* bantu;
node* masuk;
node* cari;

//inisialisasi
void inisialisasi()
{
	awal=NULL;
	akhir=NULL;
}

//insert data pada simpul awal
void insert(int a)
{
	masuk=(node* )malloc(sizeof(node));
	masuk->data=a;
	masuk->next=NULL;
	if (awal==NULL)
	{
		awal=masuk;
		awal->next=NULL;
	}
	else
	{
		masuk->next=awal;
		awal=masuk;
	}
}

//menampilkan data
void tampil()
{
	curr=awal;
	if (awal==NULL)
	{
		cout<<"\n";
		cout<<"Data Tidak Tersedia "<<endl;
	}
	else
	{
		cout<<"\n";
		cout<<"Data dalam Linked List : "<<endl;
		cout<<setw(5);
		while (curr!=NULL)
		{
			cout<<curr->data<<" -> ";
			curr=curr->next;
		}
		cout<<"NULL";
		cout<<endl;
	}
}

//Mencari simpul tertentu
void search(int a)
{
	cari=masuk;
	cari->data=a;
	while (cari->data!=a)
	{
		cari=cari->next;
	}	
}

//insert data pada simpul akhir
void tail(int a)
{
	node *masuk,*bantu;
	masuk=new node;
	masuk->data=a;
	masuk->next=NULL;
	if (awal==NULL)
	{
		awal=masuk;
		awal->next=NULL;
	}
	else
	{
		bantu=awal;
		while (bantu->next!=NULL)
		{
			bantu=bantu->next;
		}
		bantu->next=masuk;
	}
}

void menu()
{
      char pilih, ulang;
      int data;

      do
      {
      system("cls");
      cout<<"======================================"<<endl;
      cout<<"       SINGLE LINKED LIST (LIFO)      "<<endl;
      cout<<"--------------------------------------"<<endl;
      cout<<"Menu : "<<endl;
      cout<<"1. Insert awal"<<endl;
      cout<<"2. Tampil data"<<endl;
      cout<<"3. Mencari data"<<endl;
      cout<<"4. Insert akhir"<<endl;
      cout<<"5. Exit"<<endl;
      cout<<"Masukkan pilihan Anda : "; cin>>pilih;

      switch(pilih)
      {
      case '1' :
            cout<<"\nMasukkan data : ";
            cin>>data;
            insert(data);
            break;
      case '2' :
            tampil();
            break;
      case '3' :
            cout<<"\nMasukkan data yang dicari : ";
            cin>>data;
			tampil();
            break;
      case '4' :
            cout<<"\nMasukkan data : ";
            cin>>data;
            tail(data);
            break;
      case '5' :
            exit(0);
            break;
		break;
			
	  default :
            cout<<"\nPilih ulang"<<endl;
      }
      cout<<"\nKembali ke menu ? (y/n) "; cin>>ulang;
      }while (ulang=='y' || ulang=='Y');
}
	
	int main()
{

      inisialisasi();
      menu();

      return EXIT_SUCCESS;
}
