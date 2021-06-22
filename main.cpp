#include <iostream>
#include <conio.h>>

using namespace std;

int main() {
	
int Pilihan, Pilih;
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
	cin>>Pilihan; 
	if ( Pilihan == 1 ){
	}

	if ( Pilihan == 2) {
		
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
		cin>>Pilih;
	}
	
	if ( Pilihan == 3 ){
		
	}
	if ( Pilihan == 4 ){
		
	}
	if ( Pilihan == 5 ){
		
	}
	else {
		cout << " Pilihan tidak ada di menu, Pilihan (1/2/3/4/5) "<<endl;
		cout<<endl;
		goto Menu;
	}
	
	
	return 0;
}
