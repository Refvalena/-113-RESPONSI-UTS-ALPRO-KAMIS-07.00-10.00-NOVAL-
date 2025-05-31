#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>

using namespace std;

struct ruangKelas {
	string ruang;
	int kapasitas;
	string lokasi;
	string fasilitas;
	
}r;

struct jadwal_kuliah{
	string dosen;
	string matkul;
	string waktu;
	string kebutuhan;
	
}j;


vector<ruangKelas>daftarruang; 
vector<jadwal_kuliah>jadwalmatkul; 


bool masuk(string username, string password){
	return  (username=="admin" && password=="1994") || (username=="mhs" && password=="1994");
}
 

void tambahruangbaru(){

	cout<<"nama ruang : ";
	cin>>r.ruang;
	cout<<"kebutuhan kapasitas  : ";
	cin>>r.kapasitas;
	cout<<"lokasi ruang  : ";
	cin>>r.lokasi;
	cout<<"fasilitas ruang  : ";
	cin>>r.fasilitas;
	daftarruang.push_back(r);
	cout<<"ruangan ditambahkan"<<endl;
}


 void nambahjadwal (){
 	jadwal_kuliah jadwal;
 	cout<<"Dosen : ";
 	cin>>j.dosen;
 	cout<<"Matakuliah : ";
 	cin>>j.matkul;
 	cout<<"Waktu : ";
 	cin>>j.waktu;
 	cout<<"kebutuhan ruang: ";
 	cin>>j.kebutuhan;
 	jadwalmatkul.push_back(j);
 	cout<<"jadwal ditambahkan"<<endl;
 	
 }
 void tampilkanruang(){
 	ruangKelas ruang;
    cout<<"Nama ruang : "<< ruang.ruang <<endl<< "Kapasitas: "<< ruang.kapasitas
    <<endl<< " Lokasi: " << ruang.lokasi <<endl<< " Fasilitas: " << 
	ruang.fasilitas << endl;
    
 	
 }
 void tampilkanjadwal(){
 	jadwal_kuliah jadwal;
 	cout<<"Dosen : "<<jadwal.dosen<<endl<<"matakuliah : "<<
	jadwal.matkul<<endl<<"waktu : "<<jadwal.waktu<<endl<<"kebutuhan ruang : "<<
	jadwal.kebutuhan<<endl;
 	
 }

int main (){
	string username,password;
	cout<<"===============SIMERU UAD================="<<endl;
	cout<<"masukkan username : ";
	cin>>username;
	cout<<"masukkan password : ";
	cin>>password;
	
	if(!masuk( username, password)) {
		cout<<"Login gagal."<<endl;
		return 0;
	}

	
	bool Admin = (username == "admin");
	int pilihan;
	do {
	 cout <<"===== Menu " << (Admin ? "Admin" : "Mahasiswa") << " ====="<<endl;
	 if (Admin) {
	 	cout<<"1. Tambah ruang "<<endl;
	 	cout<<"2. Tambah jadwal "<<endl;
	 	cout<<"3. Lihat ruangan "<<endl;
	 	cout<<"4. Lihat jadwal "<<endl;
	 	cout<<"5. Ubah jadwal"<<endl;
		cout<<"0. keluar "<<endl;
	 } else{
	 		cout<<"1. Lihat jadwal "<<endl;
	 		cout<<"2. unduh jadwal "<<endl;
	 		cout<<"0. keluar "<<endl;
	 }
	 cout<<"pilih  : ";
	 cin>>pilihan;
	 
	 if (Admin){
	 	switch (pilihan){
	 		case 1: tambahruangbaru();
	 		break;
	 		case 2: nambahjadwal();
	 		break;
	 		case 3: tampilkanruang();
	 		break;
	 		case 4: tampilkanjadwal();
	 		case 0: cout<<"keluar "<<endl;
	 		break;
	 		default: cout<<"pilihan tidak tersedia"<<endl;
	 	
		 } 
	 } else {switch (pilihan){
	 	case 1:; 
	 }
	 }
	} while (pilihan !=0);
	
	return 0;
	
}
