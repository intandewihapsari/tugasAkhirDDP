#include <iostream>
#include <fstream>
using namespace std;

//memasukkan inputan ke file data dan nota
//ios::app
ofstream writeFile("Data.txt",ios::app);

//ios::trunc
ofstream writeNota("Nota.txt",ios::trunc);

//penggunaan struct
struct data{
	string nama;
	int totalHarga, hargaAkhir, kodeProduk,jumProduk ,jumBelanja,kembalian;

}dt;

//fungsi menampilkan nota
void input(){
	ifstream readFile("Nota.txt");
	string tampungData;
	while(getline(readFile,tampungData)){
		cout<<tampungData<<endl;
	}
	readFile.close();
}

//fungsi isi data produk
void produk(){
	dt.totalHarga = 0;

	//penggunaan array untuk menyimpan data produk
	string namaProduk[10] = {"Minyak","Beras","Telur","Tepung","Mie   ","Gula   ","Teh Celup","Kopi KA","Garam","Gas   "};
	int hargaProduk[10] = {12000,9000,24000,4000,2500,14000,6000,11000,14000,20000};
	
	//menampilkan list produk di array
	for(int i = 0; i<10; i++) {
		if(i<9){
			cout <<"| "<< i+1 << ".  " << namaProduk[i];
		}else{
			cout <<"| "<< i+1 << ". " << namaProduk[i];
		}
		for(int j = 0; j<1; j++) {
				cout<<"\t\t = Rp." << hargaProduk[i] <<"\t|"<< endl;
				}
	}
	
	//cout untuk menampilkan ke program
	//writeFile untuk menyimpan ke file data
	//writeNota untuk menyimpan ke file nota
	
	cout << "=========================================" << endl;	
	cout << "- Masukkan Jumlah Belanjaan: "; cin>>dt.jumBelanja;
	writeFile << "=========================================" << endl;
	writeFile<< "| Nama Barang  Jumlah      Total        |" << endl;

	writeNota << "=========================================================" << endl;
	writeNota << "| Pesanan Anda                                          |" << endl;
	writeNota << "=========================================================" << endl;
	writeNota << "| Nama Barang   Harga/pc      Jumlah      Total         |" << endl;
	
	
	for(int p = 0 ; p<dt.jumBelanja; p++){

		//kode produk yang dipilih konsumen
		cout << "- Masukkan Kode Produk : "; cin>>dt.kodeProduk;
		
		//seberapa banyak pcs dalam produk yang sudah disediakan
		cout << "- Masukkan Jumlah Produk : "; cin>>dt.jumProduk;
		
		//rumus harga produk dikali jumlah
		int totalJumlah = hargaProduk[dt.kodeProduk-1] * dt.jumProduk;
		//menyimpan produk yang dipilih ke file nota.txt
		writeFile <<"| "<<namaProduk[dt.kodeProduk-1]<<" \t      "<<dt.jumProduk<<"\t Rp." <<totalJumlah<<"\t|"<<endl;
		writeNota <<"| "<<namaProduk[dt.kodeProduk-1]<<" \t "<<hargaProduk[dt.kodeProduk-1] <<"\t\t"<<dt.jumProduk<<"\t Rp." <<totalJumlah<<"\t|"<<endl;
		
		//rumus jumlah seluruh harga yang sudah dikalikan
		dt.totalHarga += totalJumlah;
		
	}
	writeFile << "=========================================" << endl;
	writeNota << "=========================================================" << endl;
	


}
void diskon(){

	//menyimpan total belanja ke file nota.txt
	writeNota << "| Total Belanja\t\t\t\t Rp."<<dt.totalHarga<<"\t|"<<endl;

	//2 kondisi yang akan mendapatkan diskon 
	if ((dt.totalHarga >= 50000) && (dt.totalHarga < 100000)) {
    	dt.hargaAkhir = dt.totalHarga - (0.1*dt.totalHarga);
    	writeNota << "| Selamat, anda mendapat diskon 10%\t\t\t|" << endl;
	}else if ((dt.totalHarga >= 100000)) {
    	dt.hargaAkhir = dt.totalHarga - (0.2*dt.totalHarga);
    	writeNota << "| Selamat, anda mendapat diskon 20%\t\t\t|" << endl;
		}
  	else {
    	dt.hargaAkhir = dt.totalHarga;
 	}
	
	//menyimpan total belanja ke file data.txt
	writeFile << "Total Pengdapatan: Rp." << dt.hargaAkhir << endl;
	writeFile << endl;

	//menyimpan total belanja ke file nota.txt
	writeNota << "=========================================================" << endl;
	writeNota << "| Total bayar\t\t\t\t Rp." << dt.hargaAkhir <<"\t|" <<endl;
	writeNota << "=========================================================" << endl;

}
//menu 1
void menu1(){
	//penggunaan pointer
	int uang, *u;
	cout << "=========================================" << endl;
	cout << "|         Diskon Potongan Harga         |" << endl;
	cout << "=========================================" << endl;	
	cout << "|                                       |" << endl;
	cout << "============ Daftar Produk ==============" << endl;
	produk();	
	cout << "=========================================" << endl;	
	diskon();
	
	system("cls");
	//pemanggilan fungsi input
	input();
	//alamat pada pointer untuk mengambil nilai uang pembayaran
	u = &uang;
	cout << " - Masukkan Uang Pembayaran \t\t Rp."; cin>>*u;
	
	//kembalian dari uang pembayaran
	dt.kembalian = uang-dt.hargaAkhir;
	cout << "| Total Kembalian\t\t\t Rp." << dt.kembalian <<"\t|" <<endl;

}

//menu 2
void menu2(){
	//menampilkan seluruh data yang tersimpan di file data.txt
	ifstream readFile("Data.txt");
	string tampungData;
	
	while(getline(readFile,tampungData)){
		cout<<tampungData<<endl;
	}
	readFile.close();
}

//tampilan keseluruhan
void display(){
	int pil;
	bool ulang = true;
	
	//perulangan menu
	do{
		cout<<"================================"<<endl;
		cout<<"======== Selamat Datang ========"<<endl;
		cout<<"==== Toko Sembako Indriyuuu ===="<<endl;
		cout<<"================================"<<endl;
		cout<<"= Kode     Manu                ="<<endl;
		cout<<"=  1.   Tambah Data            ="<<endl;
		cout<<"=  2.   Lihat Seluruh Data     ="<<endl;
		cout<<"=  3.   Keluar                 ="<<endl;
		cout<<"================================"<<endl;
	
		cout<<"Masukkan Kode Yang Anda Pilih : ";cin>>pil;
		switch(pil){
			case 1:
				system("cls");
				menu1();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				cout << "|        Data Penjualan Hari Ini        |" << endl;
				menu2();
				system("pause");
				system("cls");
				break;
			case 3 :
				cout<<endl;
				cout<<"     Terimakasih Bestie :)"<<endl;
				ulang = false;
				break;
			
			default :
				cout<<"Kode Menu Salah!!"<<endl;
				system("pause");
				system("cls");
				break;
				}
		}while(ulang);
	}
	
int main(){
	display();
}

