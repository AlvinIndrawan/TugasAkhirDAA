#include <iostream>
#include <conio.h>

using namespace std;

//struct untuk penggunaan linked list
struct produk{
	int harga_produk, stok_produk;
	string id_produk, nama_produk;
	
	produk *next;
};

produk *newData, *head=NULL, *tail=NULL, *tampil, *temp;

//FUNGSI TAMBAH STOK
int TambahStok(string cari, int stok){
	
	if(head == NULL){
		cout<<"Data masih kosong";
	}else{
		temp = head;
		do{
			if(temp->nama_produk == cari || temp->id_produk == cari){
				temp->stok_produk += stok;
				cout<<"stok produk "<<temp->nama_produk<<" telah berhasil ditambah"<<endl;
				cout<<"stok produk "<<temp->nama_produk<<" sekarang : "<<temp->stok_produk<<endl;
				return 1;
			}
			temp = temp->next;
		}while(temp != NULL);
		cout<<"Nama Produk tidak ditemukan";
	}
	
}

//FUNGSI EDIT PRODUK
int EditProduk(string cari, int harga){
	
	if(head == NULL){
		cout<<"Data masih kosong";
	}else{
		temp = head;
		do{
			if(temp->nama_produk == cari || temp->id_produk == cari){
				temp->harga_produk = harga;
				cout<<"Data produk "<<temp->nama_produk<<" sudah berhasil diedit"<<endl;
				return 1;
			}
			temp = temp->next;
		}while(temp != NULL);
		cout<<"Nama Produk tidak ditemukan";
	}
	
}

//NOTIFIKASI
void Notifikasi(){
	string nama_produk[10];
	int stok[10];
	int n = 0;
	
	if(head == NULL){
		cout<<"Data masih kosong";
	}else{
		temp = head;
		do{
			if(temp->stok_produk < 100){
				nama_produk[n] = temp->nama_produk;
				stok[n] = temp->stok_produk;
				n++;
			}
			temp = temp->next;
		}while(temp != NULL);
		
		if(n > 0){
			for(int i=0; i<n; i++){
				cout<<"Stok produk "<<nama_produk[i]<<" hampir habis"<<endl;
				cout<<"Sisa stok produk "<<nama_produk[i]<<" : "<<stok[i]<<endl<<endl;
			}
		}else{
			cout<<"Kosong"<<endl;
		}
	}
}

int main() {
	
	int pilihan, pilih;
	Menu:
	cout<< " ===================================================== "<<endl;
	cout<< "                    TOKO CYAND                         "<<endl;
	cout<< " ===================================================== "<<endl;
	cout<<endl;
	cout<< "     PILIHAN MENU : "<<endl;
	cout<< "     1. Transaksi  "<<endl;
	cout<< "     2. Kelola Produk "<<endl;
	cout<< "     3. Cek Pemberitahuan (notification)"<<endl;
	cout<< "     4. Laporan (report) "<<endl;
	cout<< "     5. Keluar "<<endl; 
	cout<<endl;
	
	cout<< "     Masukkan pilihan Anda (1/2/3/4/5) : ";
	cin>>pilihan; 
	if ( pilihan == 1 ){
	}
	else if ( pilihan == 2) {
		
		cout << " ------------------------------------------------ "<<endl;
		cout << "              MENU KELOLA PRODUK                  "<<endl;
		cout << " ------------------------------------------------ "<<endl;
		cout << "    1. Tambah produk baru "<<endl;
		cout << "    2. Cek stok produk "<<endl;
		cout << "    3. Tambah stok produk "<<endl;
		cout << "    4. Edit Produk "<<endl;
		cout << "    5. Tambah diskon "<<endl;
		cout << endl;
		cout<<"      Masukkan pilihan Anda (1/2/3/4/5) : ";
		cin>>pilih;
	}
	else if ( pilihan == 3 ){
		Notifikasi();
	}
	else if ( pilihan == 4 ){
		
	}
	else if ( pilihan == 5 ){
		
	}
	else {
		cout << " Pilihan tidak ada di menu, Pilihan (1/2/3/4/5) "<<endl;
		cout<<endl;
		goto Menu;
	}
	
	
	return 0;
}
