#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

//STRUCT UNTUK PROGRAM
struct produk{
	int harga_produk, stok_produk;
	string id_produk, nama_produk;
	
	produk *next;
};

produk *newData, *head=NULL, *tail=NULL, *tampil, *temp;

//STRUCT UNTUK BARANG YANG DIBELI (CART)
struct keranjang{
	string nama_produkcart[10];
	int qty_produkcart[10], harga_produkcart[10], totalharga_pcscart[10], jumlahproduk, total;
	
	keranjang *nextCart;
};

keranjang *newCart, *headCart=NULL, *tailCart=NULL, *tampilCart, *tempCart;


//FUNGSI INPUT PRODUK
int InputProduk(){
	int no_produk_nilai, harga_produk_nilai, stok_produk_nilai;
	string id_produk_nilai, nama_produk_nilai;
	
	cout << "Masukkan Id Produk: ";
	cin>>id_produk_nilai;
	
	cout << "Masukkan Nama Produk: ";
	getline(cin >> std::ws, nama_produk_nilai);
	
	cout << "Masukkan Stok Produk: ";
	cin>>stok_produk_nilai;
	
	cout << "Masukkan Harga Produk: ";
	cin>>harga_produk_nilai;
	
	cout << endl;
	cout << "Produk dengan ID " << id_produk_nilai << " telah terinput! \n";

	newData = new produk;
	newData->id_produk = id_produk_nilai;
	newData->nama_produk = nama_produk_nilai;
	newData->stok_produk = stok_produk_nilai;
	newData->harga_produk = harga_produk_nilai;
}

// FUNGSI TAMBAH PRODUK
int TambahProduk(){
	InputProduk();
	if(head == NULL){
		head = newData;
		tail = newData;
		head->next = NULL;
		tail->next = NULL;
	}
	else{
		tail->next = newData;
		tail = newData;
		tail->next = NULL;
	}
}

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

// FUNGSI TAMBAH DISKON
int TambahDiskon () {
	int d;
	
	cout<<" Pilihan tambah diskon :"<<endl;
	cout<<" \t 1. Diskon 10 %"<<endl;
	cout<<" \t 2. Diskon 15 %"<<endl;
	cout<<" \t 3. Diskon 20 %"<<endl;
	cout<<" \t 4. Diskon 30 %"<<endl;
	cout<<" \t 5. Diskon 50 %"<<endl;
	cout<<" Masukkan pilihan Anda (1/2/3/4/5) : ";
	cin>>d;
	
	if ( d == 1)
	{
		
	}
	else if ( d == 2)
	{
		
	}
	else if ( d == 3)
	{
		
	}
	else if ( d == 4)
	{
		
	}
	else if ( d == 5)
	{
		
	}
	else 
	{
		cout<<" Pilihan tidak tersedia !"<<endl;
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
    cout << "------------------------------------------------------------------------------\n";
    cout << "\tID\t\tNama Produk\t\tStok\n";
    cout << "------------------------------------------------------------------------------\n";
    
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
int DiBeli(string cari, int qty){
	int stok;
	temp = head;
	do{
		if(temp->nama_produk == cari || temp->id_produk == cari){
		   temp->stok_produk -= qty;
		   return 0;
		}
		temp = temp->next;
	}while(temp != NULL);
}

// FUNGSI UNTUK TAMBAH KERANJANG
int TambahCart(string produk[], int qty[], int harga[], int harga_produk[], int jumlah_produk, int total_produk)
{
	newCart = new keranjang;
	for(int i=0; i<jumlah_produk; i++){
		newCart->nama_produkcart[i] = produk[i];
		newCart->qty_produkcart[i] = qty[i];
		newCart->harga_produkcart[i] = harga[i];
		newCart->totalharga_pcscart[i] = harga_produk[i];
	}
	newCart->jumlahproduk = jumlah_produk;
	newCart->total = total_produk;
	
	if(headCart == NULL){
		headCart = newCart;
		tailCart = newCart;
		headCart->nextCart = NULL;
		tailCart->nextCart = NULL;
	}
	else{
		tailCart->nextCart = newCart;
		tailCart = newCart;
		tailCart->nextCart = NULL;
	}
}

// FUNGSI UNTUK CETAK NOTA
int Nota(int bayar, int kembalian){
	time_t curr_time;
	curr_time = time(NULL);

	char *tanggal = ctime(&curr_time);

	tempCart = tailCart;
	
	cout<<endl;
	cout << "Tanggal : " << tanggal << endl;
	cout<< " ================================================================================================== "<<endl;
	cout<< "                                NOTA TRANSAKSI TOKO CYAND                        "<<endl;
	cout<< " ================================================================================================== "<<endl;
	cout<<"\tNama Produk \t\t Jumlah \t\t Harga Satuan \t\t Total"<<endl;
	
	for(int i=0; i<tempCart->jumlahproduk; i++){
		cout << "\t"<<tempCart->nama_produkcart[i]<<"\t\t"<<tempCart->qty_produkcart[i]<<"\t\t"<<tempCart->harga_produkcart[i]<<"\t\t"<<tempCart->totalharga_pcscart[i]<<endl;
		cout << "---------------------------------------------------------------------------------------------"<<endl;
	}
	cout << "Total Pembelian Produk   : " << tempCart->total << endl;
	cout << "Jumlah uang yang dibayar : " << bayar << endl;
	cout << "Kembalian                : " << kembalian << endl;

	cout << endl;
}

// FUNGSI UNTUK TRANSAKSI
int Transaksi(){
	string produk;
	int qty;
	int harga;
    char lagi = 'y';
    int total_produk;
    int total = 0;
    int bayar;
    int kembalian;
    char print_nota = 'y';
    
    int jumlah_produk = 0;
    string nama_produk[10];
    int qty_produk[10];
    int harga_satuan_produk[10];
    int harga_produk[10];
    
    do{
	    cout << "masukkan nama atau ID produk : ";
	    getline(cin >> std::ws, produk);
	    
	    harga = CekHarga(produk);    
	    if(harga== -1){
	        cout<<"Nama atau ID produk yang dimasukkan salah"<<endl;
	        continue;
		}else{
			cout << "masukkan jumlah             : ";
	        cin >> qty;
	
			DiBeli(produk, qty);
			total_produk = harga * qty;
			total += total_produk;
		    cout<<"Total : "<<total_produk<<endl;
		    cout <<"Ket  : Produk " << produk << " berhasil diinput!\n";
		    
		    nama_produk[jumlah_produk] = produk;
		    qty_produk[jumlah_produk] = qty;
		    harga_satuan_produk[jumlah_produk] = harga;
		    harga_produk[jumlah_produk] = total_produk;
		    jumlah_produk++;
		}
        cout<<"belanja lagi?[y/n] ";
        cin>>lagi;
        cout<<endl;
	}
	while(lagi=='Y' || lagi=='y');
	
	TambahCart(nama_produk, qty_produk, harga_satuan_produk, harga_produk, jumlah_produk,total);
	
	cout<<"Harga Total yang harus dibayar : "<<total<<endl;
	cout<<"Jumlah uang yang dibayar       : ";
	cin>>bayar;
	kembalian = bayar - total;
	if(kembalian > 0){
		cout<<"Kembalian anda sebesar      : "<<kembalian<<endl;
	}
	
	cout << "Apakah ingin print nota? [y/n] \n";
	cin >> print_nota;
	if(print_nota == 'Y' || print_nota == 'y'){
		Nota(bayar, kembalian);
	} else{
	  cout << "Terima Kasih Sudah Berbelanja! \n";
	}
}

//MENAMPILKAN DATA PENJUALAN
int ReportData () {
	int jumlah_produk = 0, total_pendapatan = 0;
	
	cout<<"====================================================================================="<<endl;
	cout<<"\tID \t\t Nama Produk \t\t Stok \t\t Harga Produk"<<endl;
	cout<<"====================================================================================="<<endl;
	
	 if(head == NULL){

	}else{
		temp = head;
		do{
			cout << "\t"<<temp->id_produk<<"\t\t"<<temp->nama_produk<<"\t\t"<<temp->stok_produk<<"\t\t"<<temp->harga_produk<<endl;
			cout << "-----------------------------------------------------------------------------------"<<endl;
			temp = temp->next;
		}while(temp != head);
	}
	// produk terjual dan pendapatan masih belum
	cout<<"Jumlah produk terjual"<<jumlah_produk<<endl;
	cout<<"Total pendapatan : "<<total_pendapatan<<endl; 
}

int main() {
	
	int pilihan, pilih;
	string produk_edit;
	int stok_tambah;
	
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
		goto Menu;

	}
	else if ( pilihan == 2) {
		
		MenuKelolaProduk:
		cout << " ------------------------------------------------ "<<endl;
		cout << "              MENU KELOLA PRODUK                  "<<endl;
		cout << " ------------------------------------------------ "<<endl;
		cout << "    1. Tambah produk baru "<<endl;
		cout << "    2. Cek stok produk "<<endl;
		cout << "    3. Tambah stok produk "<<endl;
		cout << "    4. Edit Produk "<<endl;
		cout << "    5. Tambah diskon "<<endl;
		cout << "    6. Kembali ke menu utama "<<endl;
		cout << endl;
		cout<<"      Masukkan pilihan Anda (1/2/3/4/5/6) : ";
		cin>>pilih;
		if(pilih == 1){
			TambahProduk();
		}else if(pilih == 2){
			TampilStokProduk();
		}else if(pilih == 3){
			cout<<"Masukkan nama atau ID produk yang ingin ditambah stoknya : ";
			getline(cin >> std::ws, produk_edit);
			cout<<"Masukkan jumlah stok yang ditambah                       : ";
			cin>>stok_tambah;
			TambahStok(produk_edit, stok_tambah);
		}else if(pilih == 4){
			
		}else if(pilih == 5){
			TambahDiskon();
		}else if(pilih == 6){
			goto Menu;
		}else{
			cout << " Pilihan tidak ada di menu, Pilihan (1/2/3/4/5/6) "<<endl;
		}
		goto MenuKelolaProduk;
	}
	else if ( pilihan == 3 ){
		Notifikasi();
		goto Menu;
	}
	else if ( pilihan == 4 ){
		ReportData();
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
