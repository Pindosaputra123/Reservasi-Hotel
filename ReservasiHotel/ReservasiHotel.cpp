#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

// Pendeklarasian Variabel
int umur, kasur, tipe, lama_inap, tanggalsatu, tanggaldua, bulansatu, bulandua;
int nId, sel1, sel2, total, bayar, hasil_akhir, pilihanNoKamar, menupilihan;
string nama, alamat, kelamin, email, status, ktp, hp;
int noKamar [10] = {251, 125, 827, 421, 122, 114, 912, 547, 233, 321}; // Variabel Sorting No Kamar
char cariNama; // Variabel Cari Nama
string satuan [] = {"", "satu ", "dua ", "tiga ", "empat ", "lima ", "enam ", "tujuh ", "delapan ", "sembilan "}; // Variabel Konversi Umur Ke Kata

// Record Data Identitas
struct data_identitas{
	string id_nama;
	string id_alamat;
	int id_umur;
	string id_ktp;
	string id_hp;
	string id_email;
	string id_kelamin;
};

//Rekursiv Konversi Umur Ke Kata
string konvertUmur(int n) {
	if (n < 10) {
		return satuan[n];
	} else if (n == 10) { // Khusus Untuk Sepuluh
		return "sepuluh ";
	} else if (n == 11) { // Khusus Untuk Sebelas
		return "sebelas ";
	} else if (n < 20) {
		return satuan[n-10] + "belas ";
	} else if (n < 100) {
		return satuan[(n-(n%10))/10] + "puluh " + konvertUmur(n % 10);
	} else {
		return "Angka terlalu besar! ";
	}
}

void InsertionSort(int noKamar[], int n) { 
	int i, k, j; 
	for (i = 1; i < n; i++) { 
		k = noKamar[i]; 
		j = i - 1; 
		while (j >= 0 && noKamar[j] > k) { 
			noKamar[j + 1] = noKamar[j]; 
			j = j - 1; 
		} 
		noKamar[j + 1] = k; 
	} 
} 

// Main Menu	
void proses() {
	system("CLS");
	cout << "|================================|" << endl;
	cout << "|          Daftar Fitur          |" << endl;
	cout << "|================================|" << endl;
	cout << "| 1 | Booking Hotel              |" << endl;
	cout << "| 2 | History Booking            |" << endl;
	cout << "| 3 | Fasilitas Hotel            |" << endl;
	cout << "| 4 | Promo Menarik              |" << endl;
	cout << "| 5 | Exit Program               |" << endl;
	cout << "| 6 | Cetak File Booking         |" << endl;
	cout << "|================================|" << endl;
}

//Batasan Umur
void val_umur() {
	system("CLS");
	cout << "|===================================|" << endl;
	cout << "|          Verifikasi Umur          |" << endl;
	cout << "|===================================|" << endl;
    cout << endl;
	int umur_akses;
    cout << "Masukan umur Anda : "; cin >> umur_akses;

    if (umur_akses >= 18) {
        cout << "Selamat! Anda dapat mengakses fitur ini, tekan apapun untuk melanjutkan proses booking hotel" << endl;
    } else {
		cout << "Mohon maaf umur anda belum mencukupi untuk bisa mengakses fitur ini!!" << endl;
		getch();
		exit(0);
    }
}

//header Identitas booking
void identitas() {
	system("CLS");
	cout << "|======================================|" << endl;
	cout << "|          Form Booking Hotel          |" << endl;
	cout << "|======================================|" << endl;
    cout << endl;
    cout << "Jumlah orang yang menginap? (Maks 4 orang!) : "; cin >> nId;
}

//Form Identitas
void formIdentitas(data_identitas orang[], int nId) {
    for (int i = 0; i < nId; i++) {
    cout << endl;
    cout << "Identitas orang ke " << i + 1 << endl;
    cout << "Nama          : "; getline (cin >> ws, orang[i].id_nama);
    cout << "Alamat        : "; getline (cin >> ws, orang[i].id_alamat);
    cout << "Umur          : "; cin >> orang[i].id_umur;
    cout << "No. KTP       : "; cin >> orang[i].id_ktp;
    cout << "No. HP        : "; cin >> orang[i].id_hp;
    cout << "E-mail        : "; cin >> orang[i].id_email;
    cout << "Jenis Kelamin : "; cin >> orang[i].id_kelamin;
    }
}

//Pilihan kamar
void pilKamar() {
    cout << "|=============================================|" << endl;
	cout << "|                Pilihan Kamar                |" << endl;
    cout << "|=============================================|" << endl;
    cout << "| 1 | Standard Room       | Rp.500.000/hari   |" << endl;
    cout << "| 2 | Twin Room           | Rp.600.000/hari   |" << endl;
    cout << "| 3 | Family Room         | Rp.1.000.000/hari |" << endl;
    cout << "| 4 | Presidential Suite  | Rp.1.500.000/hari |" << endl;
    cout << "|=============================================|" << endl;
}

//Pilihan kasur
void pilKasur() {
    cout << "|=================================|" << endl;
	cout << "|          Pilihan Kasur          |" << endl;
	cout << "|=================================|" << endl;
    cout << "| 1 | Single bed                  |" << endl;
    cout << "| 2 | Double bed                  |" << endl;
    cout << "| 3 | Twin bed                    |" << endl;
    cout << "| 4 | King bed                    |" << endl;
	cout << "|=================================|" << endl;
}

//Pilihan nomor kamar
void pilNoKamar() {
    cout << "|====================================|" << endl;
	cout << "|          Pilihan No Kamar          |" << endl;
	cout << "|====================================|" << endl;
    cout << endl;
}

//List no kamar sebelum sorting
void pilNoKamar2() {
    cout << "Pilihan kamar yang tersedia" << endl;
    cout << endl;
	cout << " [ ";
	for (int i = 0; i < 10; i++){
	    cout << noKamar[i] <<"  ";
    } cout << "]" << endl;
    cout << endl;
}

//List no kamar sesudah sorting
void pilNoKamar3() {
    InsertionSort(noKamar, 10);
    cout << "Pilihan kamar yang tersedia" << endl;
    cout << endl;
	cout << " [ ";
	for (int i = 0; i < 10; i++){
		cout << noKamar[i] <<"  ";
	} cout << "]" << endl;
    cout << endl;
}

//Menu Kamar
void kamar() {
	system("CLS");
    pilKamar();
    cout << "Silahkan Pilih tipe kamar : "; cin >> tipe;
        if (tipe > 4) {
            cout << "Tipe Kamar tersebut tidak ada.";
        while (tipe > 4) {
            system("CLS");
            pilKamar();
		    cout << "Silahkan Pilih tipe kamar  : "; cin >> tipe;
	        }
        }

    system("CLS");
    pilKasur();
    cout << "Silahkan Pilih tipe kasur : "; cin >> kasur;
        if (kasur > 4) {
            cout << "Tipe kasur tersebut tidak ada.";
        while (kasur > 4) {
            system("CLS");
            pilKasur();
    	    cout << "Silahkan Pilih tipe kasur : "; cin >> kasur;
	        }
        }
    
    system("CLS");
    pilNoKamar();
    pilNoKamar2();
    cout << "1. Urutkan nomor kamar "; cout << endl;
    cout << "2. Pilih kamar "; cout << endl;
    cout << "Masukkan pilihan anda : "; cin >> menupilihan;

        if (menupilihan == 1) {
        system("CLS");
        pilNoKamar();
        pilNoKamar3();
        cout << "Silahkan pilih nomor kamar : "; cin >> pilihanNoKamar;
        } else {
        cout << "Silahkan pilih nomor kamar : "; cin >> pilihanNoKamar;
        }
}

//History pemesanan
void history() {
    system("CLS");
    cout << "|===================================|" << endl;
	cout << "|          History Booking          |" << endl;
	cout << "|===================================|" << endl;
    cout << endl;
    if (tipe == 1 && kasur == 1) {
        cout << "Anda memilih kamar bertipe Standard Room dan kasur bertipe Single bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;

    } else if (tipe == 1 && kasur == 2) {
        cout << "Anda memilih kamar bertipe Standard Room dan kasur bertipe Double bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else if (tipe == 1 && kasur == 3) {
        cout << "Anda memilih kamar bertipe Standard Room dan kasur bertipe Twin bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else if (tipe == 1 && kasur == 4) {
        cout << "Anda memilih kamar bertipe Standard Room dan kasur bertipe King bed \n";
        cout << "dengan identitas pembookingan : "<< endl; cout << endl;
    } else if (tipe == 2 && kasur == 1) {
        cout << "Anda memilih kamar bertipe Twin Room dan kasur bertipe Single bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else if (tipe == 2 && kasur == 2) {
        cout << "Anda memilih kamar bertipe Twin Room dan kasur bertipe Double bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else if (tipe == 2 && kasur == 3) {
        cout << "Anda memilih kamar bertipe Twin Room dan kasur bertipe Twin bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else if (tipe == 2 && kasur == 4) {
        cout << "Anda memilih kamar bertipe Twin Room dan kasur bertipe King bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else if (tipe == 3 && kasur == 1) {
        cout << "Anda memilih kamar bertipe Family Room dan kasur bertipe Single bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else if (tipe == 3 && kasur == 2) {
        cout << "Anda memilih kamar bertipe Family Room dan kasur bertipe Double bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else if (tipe == 3 && kasur == 3) {
        cout << "Anda memilih kamar bertipe Family Room dan kasur bertipe Twin bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else if (tipe == 3 && kasur == 4) {
        cout << "Anda memilih kamar bertipe Family Room dan kasur bertipe King bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else if (tipe == 4 && kasur == 1) {
        cout << "Anda memilih kamar bertipe Presidential Suite dan kasur bertipe Single bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else  if (tipe == 4 && kasur == 2) {
        cout << "Anda memilih kamar bertipe Presidential Suite dan kasur bertipe Double bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else if (tipe == 4 && kasur == 3) {
        cout << "Anda memilih kamar bertipe Presidential Suite dan kasur bertipe twin bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    } else if (tipe == 4 && kasur == 4) {
        cout << "Anda memilih kamar bertipe Presidential Suite dan kasur bertipe King bed \n";
        cout << "dengan identitas pembookingan : " << endl; cout << endl;
    }
}

//History pemesanan2
void history2(data_identitas orang[], int nId) {
for (int i=0; i < nId; i++) {
    cout << "Identitas orang ke " << i + 1 << endl;
    cout << "Nama               : " << orang[i].id_nama << endl;
    cout << "Umur               : " << orang[i].id_umur << " ( " << konvertUmur(orang[i].id_umur) << " tahun ) " << endl;
    cout << "No. KTP            : " << orang[i].id_ktp << endl;
    cout << "No. HP             : " << orang[i].id_hp << endl;
    cout << "E-mail             : " << orang[i].id_email << endl;
    cout << "Jenis Kelamin      : " << orang[i].id_kelamin << endl;
    cout << "Alamat             : " << orang[i].id_alamat << endl;
    cout << "Waktu Check-in     : " << tanggalsatu << "-" << bulansatu << "-2024" << endl;
    cout << "Waktu Check-out    : " << tanggaldua << "-" << bulandua << "-2024" << endl;
	cout << "Lama menginap      : " << lama_inap << " hari" << endl;
    cout << "Nomor Kamar        : " << pilihanNoKamar << endl;
    cout << endl;
                    }
}

//Durasi menginap
void durasi() {
    system("CLS");
 	cout << "|===================================|" << endl;
	cout << "|          Durasi Menginap          |" << endl;
	cout << "|===================================|" << endl;
    cout << endl;
    cout << "Masukkan tanggal Check-in  : "; cin >> tanggalsatu;
    if (tanggalsatu > 30) {
        cout << "Tanggal tersebut tidak ada.";
        while (tanggalsatu > 30) {
            system("CLS");
		    cout << "Masukkan tanggal Check-in  : "; cin >> tanggalsatu;
	    }
    }
    if (tanggalsatu <= 0) {
        cout << "Tanggal tersebut tidak ada.";
    }
    cout << "Masukkan bulan Check-in  : "; cin >> bulansatu;
    if (bulansatu > 12) {
        cout << "Bulan tersebut tidak ada.";
        while (bulansatu > 12) {
            system("CLS");
		    cout << "Masukkan bulan Check-in  : "; cin >> bulansatu;
	    }
    }
    if (bulansatu <= 0) {
        cout << "Bulan tersebut tidak ada.";
    }
    cout << "Masukkan tanggal Check-out : "; cin >> tanggaldua;
    if (tanggaldua > 30) {
        cout << "Tanggal tersebut tidak ada.";
        while (tanggaldua > 30) {
            system("CLS");
		    cout << "Masukkan tanggal Check-out  : "; cin >> tanggaldua;
	    }
    }
    if (tanggaldua <= 0) {
        cout << "Tanggal tersebut tidak ada.";
    }
    cout << "Masukkan bulan Check-out  : "; cin >> bulandua;
    if (bulandua > 12) {
        cout << "Bulan tersebut tidak ada.";
        while (bulandua > 12) {
            system("CLS");
		    cout << "Masukkan bulan Check-out  : "; cin >> bulandua;
	    }
    }
    if (bulandua <= 0) {
        cout << "Bulan tersebut tidak ada.";
    }
    
    if (bulansatu > bulandua) {
        bulandua = bulandua + 12;
    }
    if (tanggalsatu > tanggaldua) {
        bulandua = bulandua - 1;
        tanggaldua = tanggaldua + 30;
    }
    sel1 = bulandua - bulansatu;
    sel2 = tanggaldua - tanggalsatu;
    lama_inap = (sel1*30) + sel2;
    system("CLS");
	cout << "|===================================|" << endl;
	cout << "|          Durasi Menginap          |" << endl;
	cout << "|===================================|" << endl;
    cout << endl;
}

//Menu pembayaran
void pembayaran() {
	system("CLS");
	cout << "|==============================|" << endl;
	cout << "|          Pembayaran          |" << endl;
	cout << "|==============================|" << endl;
    cout << endl;
	switch (tipe) {
		case 1 :
			total = 500000*lama_inap;
			break;
		case 2 :
			total = 600000*lama_inap;
			break;
		case 3 :
			total = 1000000*lama_inap;
			break;
		case 4 :
			total = 1500000*lama_inap;
			break;
	}
	cout << "Total biaya    : Rp." << total << endl;
	cout << "Nominal bayar  : Rp."; cin >> bayar;
	
	if (total > bayar) {
		hasil_akhir = total-bayar;
		cout << endl;
		cout << "Pembayaran tersisa Rp." << hasil_akhir << " , silahkan melunasi pembayaran pada saat check-in." << endl;
		cout << "Detail pembookingan telah dikirim ke alamat email Anda, atau anda dapat melihatnya pada history booking di halaman awal." << endl;
		cout << endl; cout << endl; cout << endl; cout << "				*** Terima kasih! ***" << endl;
		status = "Belum lunas";
	} else if (bayar > total) {
		hasil_akhir = bayar-total;
		cout <<  endl;
		cout << "Pembayaran selesai! Kembalian sebesar Rp." << hasil_akhir << " dapat anda ambil pada saat check-in." << endl;
		cout << "Detail pembookingan telah dikirim ke alamat email Anda, atau anda dapat melihatnya pada history booking di halaman awal." << endl;
		cout <<  endl; cout <<  endl; cout <<  endl; cout << "				*** Terima kasih! ***" << endl;
		status = "Lunas";
	} else {
		cout << endl;
		cout << "Pembayaran selesai!" << endl;
		cout << "Detail pembookingan telah dikirim ke alamat email Anda, atau anda dapat melihatnya pada history booking di halaman awal." << endl;
		cout << endl; cout << endl; cout << endl; cout << "				*** Terima kasih! ***" << endl;
		status = "Lunas";
	}
}

//List Fasilitas
void fasilitas() {
	system("CLS");
	cout << "|===================================|" << endl;
	cout << "|          Fasilitas Hotel          |" << endl;
	cout << "|===================================|" << endl;
	cout << "| 1  | Cafe & Bar                   |" << endl;
	cout << "| 2  | Restaurant                   |" << endl;
	cout << "| 3  | Laundry                      |" << endl;
	cout << "| 4  | Security 24 Jam              |" << endl;
	cout << "| 5  | Receptionist 24 Jam          |" << endl;
	cout << "| 6  | Aula                         |" << endl;
	cout << "| 7  | Swimming Pool                |" << endl;
	cout << "| 8  | TV Cable                     |" << endl;
	cout << "| 9  | ATM                          |" << endl;
	cout << "| 10 | Mini market                  |" << endl;
	cout << "| 11 | Meeting Room                 |" << endl;
	cout << "| 12 | Flower garden                |" << endl;
	cout << "| 13 | Gym                          |" << endl;
	cout << "| 14 | Kids Club                    |" << endl;
	cout << "| 15 | Golf                         |" << endl;
	cout << "|===================================|" << endl;
}

//List Promo
void promo() {
	system("CLS");
    cout << "|==================================================================================================|" << endl;
	cout << "|                                          Promo Menarik                                           |" << endl;
	cout << "|==================================================================================================|" << endl;
	cout << "| 1 | Total booking mencapai Rp.50.000.000 : Free 1 unit IPhone X                                  |" << endl;
	cout << "| 2 | Total booking mencapai Rp.40.000.000 : Free 1 Ticket Garuda first class Jakarta-Amsterdam PP |" << endl;
	cout << "| 3 | Total booking mencapai Rp.30.000.000 : Free 1 unit IPhone 6s                                 |" << endl;
	cout << "| 4 | Total booking mencapai Rp.20.000.000 : Free 1 pair Adidas Predator 20.4                      |" << endl;
	cout << "| 5 | Total booking mencapai Rp.10.000.000 : Free 1 Voucher McDonalds Rp.1.000.000                 |" << endl;
    cout << "|==================================================================================================|" << endl;
}

//List Hadiah
void hadiah(data_identitas orang[], int nId) {
	cout << endl;
	if (total >= 50000000) {
		cout << "*** Selamat " << orang[0].id_nama << "!, anda berhak mendapatkan 1 unit IPhone X dalam rangka promo booking hotel karena total transaksi anda mencapai Rp." << total << " ***" << endl;
	} else if (total >= 40000000) {
		cout << "*** Selamat " << orang[0].id_nama << "!, anda berhak mendapatkan 1 ticket Garuda first class Jakarta-Amsterdam PP dalam rangka promo booking hotel karena total transaksi anda mencapai Rp." << total << " ***" << endl;
	} else if (total >= 30000000) {
		cout << "*** Selamat " << orang[0].id_nama << "!, anda berhak mendapatkan 1 unit IPhone 6s dalam rangka promo booking hotel karena total transaksi anda mencapai Rp." << total << " ***" << endl;
	} else if (total >= 20000000) {
		cout << "*** Selamat " << orang[0].id_nama << "!, anda berhak mendapatkan 1 pair Adidas Predator 20.4 dalam rangka promo booking hotel karena total transaksi anda mencapai Rp." << total << " ***" << endl;
	} else if (total >= 10000000) {
		cout << "*** Selamat " << orang[0].id_nama << "!, anda berhak mendapatkan 1 voucher McDonalds Rp.1.000.000 dalam rangka promo booking hotel karena total transaksi anda mencapai Rp." << total << " ***" << endl;
	} else {
		cout << " ";
	}
}

//SequentialSearch
void seqSch(data_identitas orang[], int nId) {
    int lokasi;
    string kataNama;
    char cocok;
    cout << "Masukkan nama yang ingin dicari : "; cin >> kataNama;
    for (int i = 0; i <= nId; i++){
        if (kataNama == orang[i].id_nama) {
            cocok = 'a';
            lokasi = i + 1;
        }

    } if (cocok == 'a') {
        cout << kataNama << " ditemukan pada identitas ke " << lokasi << endl;
    } else {
        cout << "Maaf, nama " << kataNama << " tidak ditemukan! " << endl;
    }
}

//Operasi File
void opFile(data_identitas orang[], int nId) {
    ofstream filebooking;
    filebooking.open("history_booking.txt");
        for(int i = 0; i < nId; i++) {
            filebooking << "Identitas orang ke " << i + 1 << endl;
            filebooking << "Nama               : " << orang[i].id_nama << endl;
            filebooking << "Umur               : " << orang[i].id_umur << " ( " << konvertUmur(orang[i].id_umur) << " tahun ) " << endl;
            filebooking << "No. KTP            : " << orang[i].id_ktp << endl;
            filebooking << "No. HP             : " << orang[i].id_hp << endl;
            filebooking << "E-mail             : " << orang[i].id_email << endl;
            filebooking << "Jenis Kelamin      : " << orang[i].id_kelamin << endl;
            filebooking << "Alamat             : " << orang[i].id_alamat << endl;
            filebooking << "Waktu Check-in     : " << tanggalsatu << "-" << bulansatu << "-2024" << endl;
            filebooking << "Waktu Check-out    : " << tanggaldua << "-" << bulandua << "-2024" << endl;
	        filebooking << "Lama menginap      : " << lama_inap << " hari" << endl;
            filebooking << "==========================================================" << endl;
        }
    filebooking.close();
}

//Program utama	
int main() {
    data_identitas orang[4];
	int menu = 100;
	while (menu != 7) {
		proses();
		cout << endl;
		cout << "Masukkan pilihan anda : "; cin >> menu;
			while (menu > 7) {
				cout << "Inputan salah! silahkan masukkan ulang pilihan ";
				getch();
				system("CLS");
				proses();
				cout << endl;
				cout << "Masukkan pilihan anda : "; cin >> menu;
			}
		switch (menu) {
			case 1 :
				val_umur();getch();
				identitas();
                formIdentitas(orang, nId);
				kamar();
				durasi(); 
                cout << orang[0].id_nama << ", anda akan menginap selama " << lama_inap << " hari.\n";
                getch();
				pembayaran();getch();
				break;
			case 2 :
				history();
                history2(orang, nId);
				hadiah(orang, nId);
                //Sequential Search
                cout << "Ingin mencari nama ? (y/n) : "; cin >> cariNama;
                if (cariNama == 'y'){
                    seqSch(orang, nId);
                }
				getch();
				break;
			case 3 :
				fasilitas();getch();
				break;
			case 4 :
				promo();getch();
				break;
            case 5 :
			    exit (0);
            case 6 :
                opFile(orang, nId);
                break; 
		}
	}
	return 0;
}