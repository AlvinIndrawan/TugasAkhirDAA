#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

//STRUCT UNTUK PROGRAM
struct produk{
	int harga_produk, stok_produk;
	string id_produk, nama_produk, exp_date_produk;
	
	produk *next;
};

produk *newData, *head=NULL, *tail=NULL, *tampil, *temp;

//STRUCT UNTUK BARANG YANG DIBELI (CART)
struct keranjang{
	string nama_produkcart[10];
	int qty_produkcart[10], harga_produkcart[10], totalharga_pcscart[10];
	int jumlahproduk, total, total_bersih;
	
	keranjang *nextCart;
};

keranjang *newCart, *headCart=NULL, *tailCart=NULL, *tampilCart, *tempCart;

//TRUCT UNTUK DISKON
struct diskon{
	int minimum_pembelian;
	float potongan, potongan_persen;
	
	diskon *next;
};
diskon *newDiskon, *headDiskon=NULL, *tailDiskon=NULL, *tempDiskon, *tempDiskon2;


//FUNGSI INPUT PRODUK
int InputProduk(){
	int no_produk_nilai, harga_produk_nilai, stok_produk_nilai;
	string id_produk_nilai, nama_produk_nilai, exp_date_produk_nilai;
	
	cout << "Masukkan Id Produk: ";
	cin>>id_produk_nilai;
	
	cout << "Masukkan Nama Produk: ";
	getline(cin >> std::ws, nama_produk_nilai);
	
	cout << "Masukkan Expired Date Produk : ";
	getline(cin >> std::ws, exp_date_produk_nilai);
	
	cout << "Masukkan Stok Produk: ";
	cin>>stok_produk_nilai;
	
	cout << "Masukkan Harga Produk: ";
	cin>>harga_produk_nilai;
	
	cout << endl;
	cout << "Produk dengan ID " << id_produk_nilai << " telah terinput! \n";

	newData = new produk;
	newData->id_produk = id_produk_nilai;
	newData->nama_produk = nama_produk_nilai;
	newData->exp_date_produk = exp_date_produk_nilai;
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
int EditHargaProduk(string cari, int harga){
	
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

int EditNamaProduk(string cari, string nama){
	
	if(head == NULL){
		cout<<"Data masih kosong";
	}else{
		temp = head;
		do{
			if(temp->nama_produk == cari || temp->id_produk == cari){
				temp->nama_produk = nama;
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
	float potongan_nilai_persen;
	int minimum_pembelian_nilai;
	float potongan_nilai;
	int i=1;
	
	cout << "Masukkan diskon yang ingin Anda terapkan (dalam persen)  : ";
	cin >> potongan_nilai_persen;
	
	cout << "Masukkan minimum pembelian untuk mendapatkan diskon :    ";
	cin >> minimum_pembelian_nilai;
	
	potongan_nilai = potongan_nilai_persen / 100;
	
	cout << "Keterangan : Diskon sebesar " << potongan_nilai_persen << "% untuk minimum pembelian Rp." << minimum_pembelian_nilai << " telah berhasil diinput! \n\n";
	
	newDiskon = new diskon;
	newDiskon->potongan_persen = potongan_nilai_persen;
	newDiskon->potongan = potongan_nilai;
	newDiskon->minimum_pembelian = minimum_pembelian_nilai;
	
	if(headDiskon == NULL){
		headDiskon = newDiskon;
		tailDiskon = newDiskon;
		headDiskon->next = NULL;
		tailDiskon->next = NULL;
	}
	else{
		tailDiskon->next = newDiskon;
		tailDiskon = newDiskon;
		tailDiskon->next = NULL;
	}
	
	//menampilkan Diskon yang telah diinput tadi
	cout << "------------------------------------------------------------------------------\n";
    cout << "\tNo\t\tJumlah Diskon\t\tMinimum Pembelian\n";
    cout << "------------------------------------------------------------------------------\n";
    
    if(headDiskon == NULL){

	}else{
		tempDiskon = headDiskon;
		do{
			cout << "\t"<<i<<"\t\t"<<tempDiskon->potongan_persen << "%"<<"\t\t"<<tempDiskon->minimum_pembelian<<endl;
			cout << "------------------------------------------------------------------------------\n";
			i++;
			tempDiskon = tempDiskon->next;
		}while(tempDiskon != NULL);
	}
   cout << endl;
}

//FUNGSI CEK DISKON
int CekDiskon(int total){
	int diskon;
	
	tempDiskon = headDiskon;
	tempDiskon2 = tempDiskon->next;
	
	do{
		if(total >= tempDiskon->minimum_pembelian && total < tempDiskon2->minimum_pembelian){
			diskon = tempDiskon->potongan * total;
			return diskon;
		}
		else if(tempDiskon->minimum_pembelian > total){
			return -1;
		}
		tempDiskon = tempDiskon->next;
		tempDiskon2 = tempDiskon2->next;
	} while(tempDiskon != NULL && tempDiskon2 != NULL);
	
	if(tempDiskon2 == NULL){
		diskon = tempDiskon->potongan * total;
		return diskon;
	}
	return -1;
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
			if(temp->stok_produk < 20){
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

//MENGECEK NAMA PRODUK YANG DIBELI
string CekNama(string cari){
	string nama; 
	temp = head;
	do{
		if(temp->nama_produk == cari || temp->id_produk == cari){
			nama = temp->nama_produk;
			return nama;
		}
		temp = temp->next;
	}while(temp != NULL);
	return "kosong";
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
int TambahCart(string produk[], int qty[], int harga[], int harga_produk[], int jumlah_produk, int total_produk, int total_produk_bersih)
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
	newCart->total_bersih = total_produk_bersih;
	
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
int Nota(int bayar, int kembalian, float diskon, int total){
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
		cout << "\t"<<tempCart->nama_produkcart[i]<<"\t\t "<<tempCart->qty_produkcart[i]<<"\t\t\t "<<tempCart->harga_produkcart[i]<<"\t\t\t "<<tempCart->totalharga_pcscart[i]<<endl;
		cout << "---------------------------------------------------------------------------------------------"<<endl<<endl;
	}
	cout << "Total Pembelian Produk   : " << tempCart->total << endl;
	
	if(diskon==-1){
		cout << "Diskon Pembelian         : tidak ada" << endl;
	} else{
		cout << "Diskon Pembelian         : " << tempDiskon->potongan_persen << "%" << endl;
	}
	
	cout << "Total Pembelian Akhir    : " << total << endl;
	cout << "Jumlah uang yang dibayar : " << bayar << endl;
	cout << "Kembalian                : " << kembalian << endl;

	cout << endl;
}

// FUNGSI UNTUK TRANSAKSI
int Transaksi(){
	string produk;
	int qty;
	int harga;
	string nama = "kosong";
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
    float diskon;
    
    do{
	    cout << "masukkan nama atau ID produk : ";
	    getline(cin >> std::ws, produk);
	    
		nama = CekNama(produk);    
	    if(nama == "kosong"){
	        cout<<"Nama atau ID produk yang dimasukkan salah"<<endl;
	        continue;
		}else{
			cout << "masukkan jumlah             : ";
	        cin >> qty;
	        
	        harga = CekHarga(produk);
	
			DiBeli(produk, qty);
			total_produk = harga * qty;
			total += total_produk;
		    cout<<"Total : "<<total_produk<<endl;
		    cout <<"Ket  : Produk " << produk << " berhasil diinput!\n";
		    
		    nama_produk[jumlah_produk] = nama;
		    qty_produk[jumlah_produk] = qty;
		    harga_satuan_produk[jumlah_produk] = harga;
		    harga_produk[jumlah_produk] = total_produk;
		    jumlah_produk++;
		}
        cout<<"belanja lagi?[y/n] : ";
        cin>>lagi;
        cout<<endl;
	}
	while(lagi=='Y' || lagi=='y');
	
	cout<<"Harga Total yang harus dibayar : "<<total<<endl;
	
	diskon = CekDiskon(total);
	
	if(diskon==-1){
		cout << "Diskon pembelian               : Maaf, tidak mencapai minimal pembelian"<<endl;
		TambahCart(nama_produk, qty_produk, harga_satuan_produk, harga_produk, jumlah_produk,total, total);
	}else{
		cout << "Berhasil menerapkan diskon sebesar " << tempDiskon->potongan_persen << "% " <<endl;
		cout << "Diskon pembelian               : " << diskon << endl;
		total = total - diskon;
		cout << "Harga total yang harus dibayar : "<<total<<endl;
		TambahCart(nama_produk, qty_produk, harga_satuan_produk, harga_produk, jumlah_produk,total + diskon, total);
	}
	
	cout<<"Jumlah uang yang dibayar       : ";
	cin>>bayar;
	kembalian = bayar - total;
	if(kembalian > 0){
		cout << "Kembalian anda sebesar         : "<<kembalian<<endl<<endl;
	}
	
	cout << "Apakah ingin print nota? [y/n] : ";
	cin >> print_nota;
	if(print_nota == 'Y' || print_nota == 'y'){
		Nota(bayar, kembalian, diskon, total);
	} else{
	  cout << "Terima Kasih Sudah Berbelanja! \n";
	}
}

//REPORT DATA PENJUALAN
int ReportData () {
	int total_jumlah_produk = 0;
	int total_pendapatan = 0;
	int n = 0;
	int indeks;
	int sudah_ada = 0;
	int jumlah_jenis_produk = 0;
	int total = 0;
	int total_bersih = 0;
	string nama_produk[20];
	int jumlah_produk[20];
	int total_produk[20];
	
	cout<<"====================================================================================="<<endl;
	cout<<"\tNama Produk \t\t Jumlah \t\t Total"<<endl;
	cout<<"====================================================================================="<<endl;
	
	 if(headCart == NULL){

	}else{
		tempCart = headCart;
		do{
			n = tempCart->jumlahproduk;
			if(jumlah_jenis_produk == 0){
				for(int i=0; i<n; i++){
					//ID produk belum
					nama_produk[i] = tempCart->nama_produkcart[i];
					jumlah_produk[i] = tempCart->qty_produkcart[i];
					total_produk[i] = tempCart->totalharga_pcscart[i];
					jumlah_jenis_produk++;
				}
			}else{
				for(int i=0; i<n; i++){
					//Mengecek apakah sudah ada data produk yang sama
					for(int x=0; x<jumlah_jenis_produk; x++){
						if(tempCart->nama_produkcart[i] == nama_produk[x]){
							indeks = x;
							sudah_ada = 1;
						}
					}
					
					if(sudah_ada == 1){
						jumlah_produk[indeks] += tempCart->qty_produkcart[i];
						total_produk[indeks] += tempCart->totalharga_pcscart[i];
						sudah_ada = 0;
					}else{
						nama_produk[jumlah_jenis_produk] = tempCart->nama_produkcart[i];
						jumlah_produk[jumlah_jenis_produk] = tempCart->qty_produkcart[i];
						total_produk[jumlah_jenis_produk] = tempCart->totalharga_pcscart[i];
						jumlah_jenis_produk++;
					}
				}
			}
			total += tempCart->total;
			total_bersih += tempCart->total_bersih;
			tempCart = tempCart->nextCart;
		}while(tempCart != NULL);
		
		for(int i=0; i<jumlah_jenis_produk; i++){
			cout << "\t"<<nama_produk[i]<<"\t\t "<<jumlah_produk[i]<<"\t\t "<<total_produk[i]<<endl;
			cout << "-----------------------------------------------------------------------------------"<<endl;
			total_jumlah_produk += jumlah_produk[i];
		}

	}
	cout<<endl;
	cout<<"Jumlah produk terjual   : "<<total_jumlah_produk<<endl;
	cout<<"Total pendapatan        : "<<total<<endl; 
	cout<<"Total pendapatan bersih : "<<total_bersih<<endl<<endl; 
}

int main() {
	
	int pilihan, pilih, pilih_edit;
	string produk_edit, cari, nama;
	int stok_tambah, harga;
	
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
	cout<<endl;
	 
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
		cout<<endl;
		
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
			cout<<"     Menu Edit Produk :     "<<endl; 
			cout<<"     1. Edit Nama Produk"<<endl; 
			cout<<"     2. Edit Harga Produk"<<endl; 
			cout<<endl; 
			cout<<"     Masukkan Pilihan : ";
			cin>>pilih_edit; 
			if (pilih_edit == 1){ 
				cout<<"Masukkan Nama Produk atau ID Produk yang ingin di edit : ";
				getline(cin>>std::ws, cari);
				cout<<"Masukkan Nama Produk baru :";
				getline(cin>>std::ws, nama);
				
				EditNamaProduk(cari, nama); 
			}
			if (pilih_edit == 2){
				cout<<"Masukkan Nama Produk atau ID Produk yang ingin di edit : ";
				getline(cin>>std::ws, cari);
				cout<<"Masukkan Harga Produk terbaru :";
				cin>>harga; 
				
				EditHargaProduk(cari, harga); 
			}
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
		goto Menu;
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
