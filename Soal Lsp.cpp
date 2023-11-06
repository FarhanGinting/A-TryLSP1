#include <stdio.h>
#include <string.h>

// Data login untuk walas dan siswa
const char walas_username[] = "walas";
const char walas_password[] = "12345";

const char siswa1_username[] = "siswa";
const char siswa1_password[] = "pass";

// Fungsi untuk memeriksa login
int checkLogin(const char* username, const char* password) {
    if (strcmp(username, walas_username) == 0 && strcmp(password, walas_password) == 0) {
        return 1; // Walas berhasil login
    } else if (strcmp(username, siswa1_username) == 0 && strcmp(password, siswa1_password) == 0) {
        return 2; // Siswa 1 berhasil login
    } 
    return 0; // Username atau password salah
}

int main() {
    char username[20];
    char password[20];
    int dataSiswaDiisi = 0;
    int role = 0;

    while (role == 0) {
    	printf("+--------------------------------------------+\n");
        printf("|                SELAMAT DATANG              |\n");
        printf("+--------------------------------------------+\n\n");
        printf("Masukkan username\t: ");
        scanf("%s", username);
        printf("Masukkan password\t: ");
        scanf("%s", password);

        role = checkLogin(username, password);

        if (role == 0) {
            printf("Login gagal. Username atau password salah.\n");
        }
    }

    char no;

    while (1) {
    	printf("\n------------------------------------------------\n");
        printf("=========== Selamat datang, Walas! =============\n");
        printf("------------------------------------------------\n");
        printf("\n*** Menu Walas (•_•) ***\n 1. Memasukan Data Nilai Siswa \n 2. Menghitung Nilai Rata-rata Siswa \n 3. Menampilkan Data Siswa \n 4. Mengurutkan Data Nilai Siswa (Terendah & Tertinggi)");
        printf("\n #  Jika Ingin Keluar Ketik ""E"" Terima Kasih ! :D");
		printf("\n\nPilih Menu =  ");
        scanf(" %c", &no);

        switch (no) {
            case '1':
                char mata_pelajaran[5][40];
                strcpy(mata_pelajaran[0], "Nilai Siswa Adli");
                strcpy(mata_pelajaran[1], "Nilai Siswa Asghar");
                strcpy(mata_pelajaran[2], "Nilai Siswa Bagus");
                strcpy(mata_pelajaran[3], "Nilai Siswa Daffa");
                strcpy(mata_pelajaran[4], "Nilai Siswa Elang");

                double nilai[5]; // Array untuk menyimpan nilai setiap mata pelajaran

                printf("\nMasukkan nilai untuk setiap siswa:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d. %s\t: ", i + 1, mata_pelajaran[i]);
                    scanf("%lf", &nilai[i]);
                }

                dataSiswaDiisi = 1; // Menandakan bahwa data siswa sudah diisi
                printf("\nTerima kasih sudah menginput data!\n");
                break;

            case '2':
                if (!dataSiswaDiisi) {
                    printf("Data siswa belum diisi. Silakan isi data terlebih dahulu.\n");
                } else {
                    // Menghitung dan menampilkan nilai rata-rata
                    double total_nilai = 0.0; // Total nilai dari semua mata pelajaran
                    for (int i = 0; i < 5; i++) {
                        total_nilai += nilai[i];
                    }
                    double rata_rata = total_nilai / 5;
                    printf("+------------------------------+\n");
        			printf("|    Rata-Rata Nilai = %.2lf   |\n", rata_rata);
        			printf("+------------------------------+\n");
        			
                }
                break;
            case '3':
               if (!dataSiswaDiisi) {
    				printf("Data siswa belum diisi. Silakan isi data terlebih dahulu.\n");
			   } else {
    				printf("+---------------------------------------+\n");
    				printf("| No. |  Mata Pelajaran     |   Nilai   |\n");
    				printf("+---------------------------------------+\n");

			    for (int i = 0; i < 5; i++) {
        			printf("| %d.  |  %-18s |  %.2lf\t|\n", i + 1, mata_pelajaran[i], nilai[i]);
    			}

    			printf("+---------------------------------------+\n");
				}

                break;
                case '4':
    				if (!dataSiswaDiisi) {
        				printf("Data siswa belum diisi. Silakan isi data terlebih dahulu.\n");
    				} else {
        				char pilihan;
        				printf("Pilih urutan pengurutan (T)ertinggi ke Terendah atau T(E)rendah ke Tertinggi: ");
        				scanf(" %c", &pilihan);

        				if (pilihan == 'Tertinggi' || pilihan == 'T') {
            				// Mengurutkan data siswa berdasarkan nilai dari tertinggi ke terendah
            				for (int i = 0; i < 4; i++) {
                				for (int j = i + 1; j < 5; j++) {
                    				if (nilai[i] < nilai[j]) {
                        				// Menukar nilai dan nama siswa
                        				double tempNilai = nilai[i];
                        				char tempNama[40];
                        				strcpy(tempNama, mata_pelajaran[i]);
	
				                        nilai[i] = nilai[j];
				                        strcpy(mata_pelajaran[i], mata_pelajaran[j]);

				                        nilai[j] = tempNilai;
                				        strcpy(mata_pelajaran[j], tempNama);
                    				}
                			}
            			}
        				} else if (pilihan == 'Terendah' || pilihan == 'E') {
            			// Mengurutkan data siswa berdasarkan nilai dari terendah ke tertinggi
	            		for (int i = 0; i < 4; i++) {
                			for (int j = i + 1; j < 5; j++) {
                    			if (nilai[i] > nilai[j]) {
                        			// Menukar nilai dan nama siswa
                        			double tempNilai = nilai[i];
                        			char tempNama[40];
                        			strcpy(tempNama, mata_pelajaran[i]);

			                        nilai[i] = nilai[j];
            			            strcpy(mata_pelajaran[i], mata_pelajaran[j]);

                        			nilai[j] = tempNilai;
                        			strcpy(mata_pelajaran[j], tempNama);
                    			}
                			}
            			}
        				} else {
            				printf("Pilihan tidak valid.\n");
            			break;
        }

        				// Menampilkan data siswa yang sudah diurutkan berdasarkan nilai
        				printf("+-------------------------------------------+\n");
        				printf("|  Nilai Siswa Berdasarkan Nilai            |\n");
        				printf("+-------------------------------------------+\n");
        					for (int i = 0; i < 5; i++) {
            					printf("| %d. %s\t: %.2lf\n", i + 1, mata_pelajaran[i], nilai[i]);
        					}
        					printf("+-------------------------------------------+\n");
    }
    		break;

            // ...

            case 'E': // Untuk keluar dari loop menu
                printf("Selamat tinggal, Walas!\n");
                return 0;

            default:
                printf("Menu tidak valid. Silakan pilih menu yang sesuai.\n");
        }
    }

    return 0;
}

