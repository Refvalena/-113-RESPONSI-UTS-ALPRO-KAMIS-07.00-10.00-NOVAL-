#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>

using namespace std;


struct jadwal_kuliah{
	string dosen;
	string matkul;
	string waktu;
	string kebutuhan;
	
};


struct ruangan {
	string nama;
	int kapasitas;
	string lokasi;
	string fasilitas;
	
};

vector<ruangan>daftarruang; //menyimpan list semua ruangan
vector<jadwal_kuliah>jadwalmatkul; //menyimpan semua jadwal kuliah

//Hanya dua user yang bisa login:
bool masuk(string username, string password){
	return  (username=="admin" && password=="1994") || (username=="mhs" && password=="1994");
}
 
//fungsi fungsi
void tambahruangbaru(){
	ruangan ruang;
	cout<<"nama ruang : ";
	cin.ignore();
	getline(cin, ruang.nama);
	cout<<"kebutuhan kapasitas  : ";
	cin>>ruang.kapasitas;
	cin.ignore();
	cout<<"lokasi ruang  : ";
	getline(cin, ruang.lokasi);
	cout<<"fasilitas ruang  : ";
	getline(cin, ruang.fasilitas);
	daftarruang.push_back(ruang);
	cout<<"ruangan ditambahkan"<<endl;
}


 void nambahjadwal (){
 	jadwal_kuliah jadwal;
 	cout<<"Dosen : ";
 	cin.ignore();
 	getline(cin, jadwal.dosen);
 	cout<<"Matakuliah : ";
 	getline(cin, jadwal.matkul);
 	cout<<"Waktu : ";
 	getline(cin, jadwal.waktu);
 	cout<<"kebutuhan ruang: ";
 	getline(cin, jadwal.kebutuhan);
 	jadwalmatkul.push_back(jadwal);
 	cout<<"jadwal ditambahkan"<<endl;
 	
 }
 void tampilkanruang(){
 	ruangan ruang;
    cout<<"Nama ruang : "<< ruang.nama <<endl<< "Kapasitas: "<< ruang.kapasitas
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
	 	cout<<"6. Hapus Jadwal "<<endl;
	 	cout<<"7. Hapus ruang "<<endl;
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
