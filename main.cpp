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

//MENAMPILKAN SELURUH STOK PRODUK
void TampilStokProduk(){
    cout << "-----------------------------------------------------------------------------\n";
    cout << "\tID\t\tNama Produk\t\tStok\n";
    cout << "-----------------------------------------------------------------------------\n";
    
    if(head == NULL){

	}else{
		temp = head;
		do{
			cout << "\t"<<temp->id_produk<<"\t\t"<<temp->nama_produk<<"\t\t"<<temp->stok_produk<<endl;
			cout << "------------------------------------------------------------------------------\n";
			temp = temp->next;
		}while(temp != NULL);
	}
   cout << endl;
}


//MENGECEK HARGA PRODUK YANG DIBELI
int CekHarga(string cari){
	int harga;
	temp = head;
	do{
		if(temp->nama_produk == cari || temp->id_produk == cari){
			harga = temp->harga_produk;
			return harga;
		}
		temp = temp->next;
	}while(temp != NULL);
	return -1;
}

//MENGURANGI JUMLAH STOK PRODUK YANG TERSISA KARENA DIBELI
void DiBeli(string cari, int qty){
	temp = head;
	do{
		if(temp->nama_produk == cari || temp->id_produk == cari){
			temp->stok_produk -= qty;
		}
		temp = temp->next;
	}while(temp != NULL);
}

// TRANSAKSI PERHITUNGAN HARGA DAN PEMBAYARAN
int Transaksi()
{
	string produk;
	int qty;
	int harga;
    char lagi = 'y';
    int total_produk;
    int total = 0;
    int bayar;
    int kembalian;
    do{
        cout << "masukkan nama atau ID produk : ";
        cin >> produk;

        harga = CekHarga(produk);
        if(harga == -1){
        	cout<<"Nama atau ID produk yang dimasukkan salah"<<endl;
        	continue;
		}else{
			cout << "masukkan jumlah                : ";
        		cin >> qty;
			DiBeli(produk, qty);
			total_produk = harga * qty;
			total += total_produk;
	        cout<<"Total : "<<total<<endl;
		}
        cout<<"belanja lagi?[y/n] ";
        cin>>lagi;
        cout<<endl;
    }
	while(lagi=='Y' || lagi=='y');
	cout<<"Harga Total yang harus dibayar : "<<total<<endl;
	cout<<"Jumlah uang yang dibayar       : ";
	cin>>bayar;
	kembalian = bayar -  total;
	if(kembalian > 0){
		cout<<"Kembalian anda sebesar        : "<<kembalian<<endl;
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
		Transaksi();

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
		if(pilih == 1){
			
		}else if(pilih == 2){
			TampilStokProduk();
		}else if(pilih == 3){
			
		}else if(pilih == 4){
			
		}else if(pilih == 5){
			
		}else{
			
		}
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
