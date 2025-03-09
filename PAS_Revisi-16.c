/*
 Nama Program: Revisi Final Project - "Hospital Management System"
 Programmer: 	Aradea Haikal Ikhwan (2106636880)
    			Amar Reza Al'as (2106703304)
 Tanggal: 18/12/2022
 Versi: 2.0
*/

#include<stdio.h> 
#include<conio.h>
#include<string.h>

void dataList(); //deklarasi function dataList
void pembayaran(); //deklarasi function pembayaran
void pembuka (); //deklarasi function pembuka
void layanan (); //deklarasi function layanan

struct data { //Menentukan variabel yang akan digunakan di dalam program menggunakan struct
	int noKamar;
	char nama [100];
	char penyakit [50];
	char alamat[300];
	int tanggalLahir;
	int bulanLahir;
	int tahunLahir;
	unsigned long long int NIK;
	char jenisKelamin;
	int tanggalMasuk;
	int bulanMasuk;
	int tahunMasuk;
	float totalHarga;
	long int hargaObat;
	long int hargaKamar;
	long int hargaDokter;
	int hari;
	char BPJS;
	int jenisKamar;
	int jenisPenyakit;
	
}; 

int main (){ //Main function
	pembuka (); // pemanggilan function welcome sebagai pembuka program
	int menu, i, kamar; // deklarasi variabel untuk function main
	struct data dataPasien[100]; //deklarasi variabel dengan struct
		//laman utama program 
		menuawal : //menu awal
		system ("cls"); //membersihkan layar saat menggunakan goto menuawal;
		printf("\n  ========================================="); 
		printf("\n     PELAYANAN RUMAH SAKIT JAMALUDDIN");//Nama Rumah Sakit
		printf("\n  =========================================");
		printf("\n  MENU\n\n"); //Menu
		printf("  1. Pendaftaran\n  2. Pembayaran\n  3. Info Layanan\n  4. Exit\n"); //isi menu
		printf("\n\n  Silakan Masukkan pilihan Anda: "); //pengguna melakukan input untuk pilihan menu mana yang diinginkan 
		scanf("%d", &menu); 
			if (menu==1) { //Pengguna memilih menu 1 (pendaftaran)
				MenuKamarPasien : //menu pemilihan kamar pasien
				system ("cls");
				printf("\n  ==============Jenis Kamar==========\n"); //Jenis kamar yang disediakan rumah sakit
				printf("      1. VIP        (Kamar 1-20)  --> 1jt/hari     \n");
			   	printf("      2. Kelas I    (Kamar 21-40) --> 800rb/hari   \n");
			    printf("      3. Kelas II   (Kamar 41-60) --> 600rb/hari   \n");
			    printf("      4. Kelas III  (Kamar 61-80) --> 400rb/hari   \n");
				printf("\n  Kamar Pasien : "); //pengguna menginput nomor kamar yang diinginkan sesuai jenis kamar pada daftar di atas
				scanf("%d", &kamar);
				if (kamar > 80 || kamar < 1){ //error handling untuk penginputan nomor kamar diluar ketersediaan rumah sakit
					printf("  Input salah, masukkan kembali dalam 3 detik"); sleep(3);
					goto MenuKamarPasien; // kembali ke menu pemilihan kamar pasien
				}
				
				if (dataPasien[kamar-1].NIK != 0){ //error handling untuk nomor kamar pasien
					long int x;
					printf("\n  Kamar telah terisi, masukkan nomor kamar ulang!\n"); 
					printf("\n  Angka 1 = Memasukkan Ulang Nomor Kamar \n  Selain Angka 1 = Kembali Ke Menu Awal\n"); //pengguna menginput pilihan yang diinginkan selanjutnya
					printf("\n  Masukkan pilihan : ");
					scanf("%ld", &x);
					switch (x){
						case 1 : //jika input angka 1, program akan langsung menuju ke menukamar:
						goto MenuKamarPasien;//kembali ke menukamar
						
						case 2 ... 10000000: //jika input angka 2-1000000
						system ("cls");//membersihkan layar
						goto menuawal
						; //kembali ke menuawal
					}
				}
				fflush(stdin); //mencegah terjadinya buffer
				dataSalah :
				dataPasien[kamar-1].noKamar = kamar;
				printf("\n\n\n  ==========Mengisi Formulir Pasien ============\n"); //Mengisi data-data pasien
				printf(  "       1. Dokter Umum                                  \n"
					     "       2. Dokter Gigi                                  \n"
				         "       3. Spesialis THT                                \n"	
			             "       4. Spesialis Anak                               \n"
			             "       5. Spesialis Kandungan                          \n"
			             "       6. Spesialis Syaraf                             \n"
			             "       7. Spesialis Bedah                              \n"
			             "       8. Spesialis Mata                               \n"
				         "       9. Spesialis Kulit dan Kelamin                  \n");
				fflush(stdin); //mencegah terjadinya buffer
				printf("\n  Nama Pasien               : ");  //pengguna menginput nama pasien
				gets(dataPasien[kamar-1].nama); //scanf nama pasien dengan fungsi gets
				fflush(stdin); //mencegah terjadinya buffer
				do {
					printf("  Nomor jenis penyakit      : "); // pengguna menginput jenis/kelompok dari penyakit yg diidap pasien
					scanf("%d",&dataPasien[kamar-1].jenisPenyakit);
					fflush(stdin); //mencegah terjadinya buffer
				} while (dataPasien[kamar-1].jenisPenyakit <= 0 || dataPasien[kamar-1].jenisPenyakit >= 10);
				printf("  Penyakit                  : "); //pengguna menginput penyakit yang diderita pasien 
				gets(dataPasien[kamar-1].penyakit);
				fflush(stdin); //mencegah terjadinya buffer
				printf("  NIK  Pasien               : "); //pengguna menginput NIK pasien
				scanf("%llu", &dataPasien[kamar-1].NIK);
				fflush(stdin); //mencegah terjadinya buffer
				printf("  Alamat atau Domisili      : "); //pengguna menginput alamat atau domisili pasien
				gets(dataPasien[kamar-1].alamat); //scanf alamat pasien dengan fungsi gets
				fflush(stdin); //mencegah terjadinya buffer
				
				dataPasien :
				while(dataPasien[kamar-1].jenisKelamin != 'l' && dataPasien[kamar-1].jenisKelamin != 'p' && dataPasien[kamar-1].jenisKelamin != 'L' && dataPasien[kamar-1].jenisKelamin != 'P')	{
			    	printf("  Jenis Kelamin (L/P)       : "); //pengguna menginput jenis kelamin
			       	scanf(" %c", &dataPasien[kamar-1].jenisKelamin);
					fflush(stdin);
					};
				while ((dataPasien[kamar-1].tanggalLahir > 31 || dataPasien[kamar-1].tanggalLahir < 1) || (dataPasien[kamar-1].bulanLahir > 12 || dataPasien[kamar-1].bulanLahir <1)){ //error handling untuk tanggal lahir
					printf("  Tanggal Lahir (DD MM YYYY): ");//menginput tanggal lahir pasien
				    scanf("%d %d %d", &dataPasien[kamar-1].tanggalLahir, &dataPasien[kamar-1].bulanLahir, &dataPasien[kamar-1].tahunLahir);
				    fflush(stdin);
				    };
				while ((dataPasien[kamar-1].tanggalMasuk > 31 || dataPasien[kamar-1].tanggalMasuk < 1) || (dataPasien[kamar-1].bulanMasuk > 12 || dataPasien[kamar-1].bulanMasuk <1)){ //error handling untuk tanggal masuk
					printf("  Tanggal Masuk (DD MM YYYY): ");//menginput tanggal masuk pasien
				    scanf("%d %d %d", &dataPasien[kamar-1].tanggalMasuk, &dataPasien[kamar-1].bulanMasuk, &dataPasien[kamar-1].tahunMasuk);
				    fflush(stdin);
				    };
				if (dataPasien[kamar-1].jenisPenyakit==1){
					printf("  Nama dokter : dr. Achmad Bachtiar P.");
					dataPasien[kamar-1].hargaDokter = 200000;
					}
				else if (dataPasien[kamar-1].jenisPenyakit==2){
					printf("  Nama dokter : drg. Amar Reza Al'as");
					dataPasien[kamar-1].hargaDokter = 150000;
					}
				else if (dataPasien[kamar-1].jenisPenyakit==3){
					printf("  Nama dokter : dr. Aradea Haikal Sp.THT");
					dataPasien[kamar-1].hargaDokter = 250000;
					}
				else if (dataPasien[kamar-1].jenisPenyakit==4){
					printf("  Nama dokter : dr. Muhammad Fikri Sp.A");
					dataPasien[kamar-1].hargaDokter = 200000;
					}
				else if (dataPasien[kamar-1].jenisPenyakit==5){
					printf("  Nama dokter : dr. Ivan Rafa Sp.OB");
					dataPasien[kamar-1].hargaDokter = 350000;
					}
				else if (dataPasien[kamar-1].jenisPenyakit==6){
					printf("  Nama dokter : dr. Akmal Prabowo  Sp.N");
					dataPasien[kamar-1].hargaDokter = 500000;
					}
				else if (dataPasien[kamar-1].jenisPenyakit==7){
					printf("  Nama dokter : dr. Alif Zidni Sp.B");
					dataPasien[kamar-1].hargaDokter = 600000;
					}
				else if (dataPasien[kamar-1].jenisPenyakit==8){
					printf("  Nama dokter : dr. Farrel Muhammad Sp.M");
					dataPasien[kamar-1].hargaDokter = 400000;
					}
				else if (dataPasien[kamar-1].jenisPenyakit==9){
					printf("  Nama dokter : dr. Fearless Sp.KK");
					dataPasien[kamar-1].hargaDokter = 250000;
					}
				fflush(stdin);
				int p;
				printf("\n  Apakah data tersebut sudah benar ?"
					   "\n  >Masukkan angka 1 jika data salah dan ingin mengisi data ulang"
					   "\n  >Masukkan angka selain 1 jika data sudah benar"
					   "\n  Konfirmasi : ");
				scanf("%d", &p);
				fflush(stdin);
				if (p==1){
					system("cls");
					goto dataSalah;
					goto dataPasien;	
				}
				else {
					fflush(stdin);
					printf("\n  Menginput Data Pasien Ke Dalam Sistem");  Sleep(800); printf("."); Sleep(800); printf("."); Sleep(800); printf("."); //loading input data untuk pembayaaran
					printf("\n  Data Pasien Telah Disimpan!"); //pemberitahuan data telah tersimpan
					printf("\n\n  Tekan ENTER untuk kembali ke menu awal!"); //input untuk kembali ke menu awal
					getch(); //function getch untuk menginput apa saja, program ke menu awal
					goto menuawal; 
				}
			}
			
			else if (menu == 2){ //jika pengguna memilih menu=2 (pembayaran)
				int x;
				menukamar :
				printf("  Masukkan Nomor Kamar Pasien : "); //menginput nomor kamar
				scanf("%d", &kamar);
				if (dataPasien[kamar-1].NIK == 0){ //error handling untuk nomor kamar pasien
					long int x;
					printf("\n  Kamar tidak ditemukkan, masukkan nomor kamar ulang!\n"); 
					printf("\n  Angka 1 = Memasukkan Ulang Nomor Kamar \n  Selain Angka 1 = Kembali Ke Menu Awal\n"); //pengguna menginput pilihan yang diinginkan selanjutnya
					printf("\n  Masukkan pilihan : ");
					scanf("%ld", &x);
					switch (x){
						case 1 : //jika input angka 1, program akan langsung menuju ke menukamar:
						goto menukamar;//kembali ke menukamar
						
						case 2 ... 10000000: //jika input angka 2-1000000
						system ("cls");//membersihkan layar
						goto menuawal; //kembali ke menuawal
					}
				}
				
				switch (dataPasien[kamar-1].noKamar) { //apabila pengguna memilih nomor kamar antara 1-20 (VIP)
					case 1 ... 20:
						system("cls");
						printf ("  LAMAN BIAYA RAWAT INAP KELAS VIP\n");
						printf("  __________________________________\n\n");
						dataPasien[kamar-1].hargaKamar = 1000000; //harga untuk setiap malam pada ruang VIP 
						break;
						
					case 21 ... 40: //apabila pengguna memilih nomor kamar antara 21-40 (Kelas I)
						system("cls");
						printf ("  LAMAN BIAYA RAWAT INAP KELAS  I\n");
						printf("  _________________________________\n\n");
						dataPasien[kamar-1].hargaKamar = 800000; //harga untuk setiap malam pada Kelas I
						break;
						
					case 41 ... 60: //apabila pengguna memilih nomor kamar antara 41-60 (Kelas II)
						system("cls");
						printf ("  LAMAN BIAYA RAWAT INAP KELAS II\n");
						printf("  _________________________________\n\n");
						dataPasien[kamar-1].hargaKamar = 600000; //harga untuk setiap malam pada Kelas II
						break;
					case 61 ... 80: //apabila pengguna memilih nomor kamar antara 61-80 (Kelas III)
						system("cls");
						printf ("  LAMAN BIAYA RAWAT INAP KELAS III\n");
						printf("  _________________________________\n\n");
						dataPasien[kamar-1].hargaKamar = 400000; //harga untuk setiap malam pada Kelas II
						break;
				}
						
				printf("  Harga Obat : ") ; //pengguna meninput harga obat
				scanf("%d", &dataPasien[kamar-1].hargaObat);
				printf("  Lama Rawat Inap : "); //penguna menginput lama rawat inap
				scanf("%d", &dataPasien[kamar-1].hari);
						
				printf("  Apakah Pasien Memiliki Layanan BPJS? (Ketik Y jika menerima, ketik apa saja jika tidak) :"); //pengguna menginput ketersediaan pasian memiliki layanan BPJS
				scanf(" %c", &dataPasien[kamar-1].BPJS);
				
				if (dataPasien[kamar-1].BPJS == 'Y' || dataPasien[kamar-1].BPJS == 'y'){
					dataPasien[kamar-1].totalHarga = (0.3)*((dataPasien[kamar-1].hargaKamar)*(dataPasien[kamar-1].hari) + dataPasien[kamar-1].hargaObat + 2*dataPasien[kamar-1].hargaDokter);//Menghitung biaya kamar pasien jika memiliki kartu BPJS
				}
				else {
					dataPasien[kamar-1].totalHarga = (dataPasien[kamar-1].hargaKamar)*(dataPasien[kamar-1].hari) + dataPasien[kamar-1].hargaObat + 2*dataPasien[kamar-1].hargaDokter; //Menghitung biaya kamar pasien jika tidak memiliki kartu BPJS
				}
				
				printf("\n  Menghitung total harga"); //loading program menghitung total harga 
				Sleep(800); printf("."); Sleep(800); printf("."); Sleep(800); printf("."); //jeda waktu titik-titik
				Sleep(800); // jeda waktu ke mencetak data pasien dan total biaya
				
				system("cls"); //membersihkan layar
				printf("\n\n\n  =================== Formulir Pasien ==================="); //mencetak data pasien dan total biaya pelayanan rumah sakit
				printf("\n  Nama Pasien          : %s" , dataPasien[kamar-1].nama); //mencetak nama pasien
				printf("\n  Nomor Kamar Pasien   : %d" , dataPasien[kamar-1].noKamar); //mencetak nomor kamar pasien
				printf("\n  Penyakit             : %s" , dataPasien[kamar-1].penyakit); //mencetak sakit yang diderita
				printf("\n  NIK  Pasien          : %llu" , dataPasien[kamar-1].NIK); //mencetak NIK
				printf("\n  Tanggal Lahir Pasien : %d %d %d", dataPasien[kamar-1].tanggalLahir, dataPasien[kamar-1].bulanLahir, dataPasien[kamar-1].tahunLahir); //Mencetak tanggal lahir pasien
				printf("\n  Jenis Kelamin        : % c", dataPasien[kamar-1].jenisKelamin); //mencetak jenis kelamin
				printf("\n  Alamat dan Domisili  : %s" , dataPasien[kamar-1].alamat); //mencetak alamat atau domisili
				printf("\n  Tanggal Masuk Pasien : %d %d %d", dataPasien[kamar-1].tanggalMasuk, dataPasien[kamar-1].bulanMasuk, dataPasien[kamar-1].tahunMasuk); //Mencetak tanggal masuk pasien
				
				printf("\n\n  TOTAL HARGA          : Rp%.2f",dataPasien[kamar-1].totalHarga); //mencetak total harga
				
				printf("\n\n  Silakan Bayar Ke Kasir!"); //informasi untuk keluarga/pendamping pasien segera membayar tagihan ke kasir
				printf("\n\n\n\n\n\n  Program Akan Segera Kembali Ke Menu Awal Dalam 15 Detik!"); //program akan kembali ke menuawal dalam 15 detik
				sleep(15); //jeda ke menu selanjutnya selama 15 detik
				goto menuawal;
			}
				
			else if (menu==3){
				layanan (); //memanggil fungsi layanan
				printf("\n\n\n\n\n\t  Jika Ingin Ke Menu Awal, Silakan Tekan ENTER!"); //pilihan untuk kembali ke menuawal
				getch(); //memanggil function getchar berfungsi saat menuliskan karakter, program akan melanjutkan kode berikutnya
				goto menuawal; //kembali ke menu awal
			}
			
			else if(menu ==4){
				system ("cls"); //membersihkan layar
				printf("TERIMA KASIH!"); //terima kasih
				return 0; //program telah berakhir
			}
			
			else if(menu>4 || menu<=0){ //error handling untuk input menu > 4 dan menu <= 0
				goto menuawal; // kembali ke menu awal
				
			}
}


void pembuka (){ //fungsi welcome untuk memunculkan pembuka program 
	int i;//deklarasi variabel integer untuk looping
	printf("UNTUK PENGALAMAN YANG LEBIH BAIK, SILAHKAN FULLSCREEN DAN ENTER UNTUK MEMULAI PROGRAM!");
	getch();//memanggil fungsi getch berfungsi saat menuliskan karakter, program akan melanjutkan kode berikutnya
	system("CLS");//Membersihkan layar
	Sleep(500);//menjeda program selama 0.5 detik
	system("color 0B") ; //untuk membuat background menjadi hitam dan tulisan menjadi cyan 
	printf("\n\n\n\n\n\n\n");
	char a[]= { "\t\t\t\t\t\t\t\t=====================================\n"
				"\t\t\t\t\t\t\t\t|           Selamat Datang          |\n"
			    "\t\t\t\t\t\t\t\t|    HOSPITAL MANAGEMENT SYSTEM     |\n"
			    "\t\t\t\t\t\t\t\t|     Amar Reza & Aradea Haikal     |\n"
			    "\t\t\t\t\t\t\t\t|            Kelompok 16            |\n"
			    "\t\t\t\t\t\t\t\t|          Dasar Komputer           |\n"
				"\t\t\t\t\t\t\t\t=====================================\n"};	
	
	for(i=0;a[i]!=a[350];i++){ 
		printf("%c",a[i]); 
		Sleep(5); 
	}
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t       Loading"); Sleep(800); 
	printf("."); Sleep(800); 
	printf("."); Sleep(800); 
	printf("."); Sleep(800);
	printf("."); Sleep(800); // Loading dengan waktu 4 detik (0,8x5)
	Beep(300,300); //Bunyi yang menandakan program akan segera memasuki penginputan data atau menampilkan informasi
	Sleep(1500);//Menjeda program selama 1.5 detik
	system("cls");//Membersihkan layar	
	system("color B0"); //untuk membuat background menjadi sian dan tulisan menjadi hitam 
}

void layanan (){
	int i;
	system("cls"); //Membersihkan layar
	char info[]= { "                                                                            \n\n" //deklarasi informasi layanan rumah sakit
	               "       ================ INFO LAYANAN RUMAH SAKIT JAMALUDDIN ==================\n"
				   "       | Senin-Jumat      : Buka 24 Jam                                      |\n"
			       "       | Sabtu & Minggu   : 08.00 - 20.00                                    |\n"
			       "       |=====================================================================|\n"
			       "       | Daftar Dokter Yang Bertugas      :                                  |\n"
			       "       | >Dokter Umum                     : dr. Achmad Bachtiar P.           |\n"
				   "       | >Dokter Gigi                     : drg. Amar Reza Al'as             |\n"
				   "       | >Spesialis THT                   : dr. Aradea Haikal Sp.THT         |\n"	
			       "       | >Spesialis Anak                  : dr. Muhammad Fikri Sp.A          |\n"
			       "       | >Spesialis Kandungan             : dr. Ivan Rafa Sp.OB              |\n"
			       "       | >Spesialis Syaraf                : dr. Akmal Prabowo  Sp.N          |\n"
			       "       | >Spesialis Bedah                 : dr. Alif Zidni Sp.B              |\n"
			       "       | >Spesialis Mata                  : dr. Farrel Muhammad Sp.M         |\n"
				   "       | >Spesialis Kulit dan Kelamin     : dr. Fearless Sp.KK               |\n"
				   "       =======================================================================\n"};
					
	for(i=0;info[i]!=info[1500];i++){ //mencetak layanan informasi yang sudah dideklarasikan
		printf("%c",info[i]); 
	}
}




