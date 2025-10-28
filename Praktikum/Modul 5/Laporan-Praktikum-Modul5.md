# Laporan Praktikum Struktur Data Modul 5

## 1. Nama, NIM, Kelas
- **Nama** : Fakhri Naabil Prasetyo
- **NIM**  : 103112400274
- **Kelas**: 12-IF-05

## 2. Motivasi Belajar Struktur Data
Saya memiliki dorongan kuat untuk mempelajari struktur data karena menyadari bahwa konsep ini adalah dasar utama dalam pemrograman. Seperti halnya bangunan yang membutuhkan fondasi kokoh, program yang kita buat juga membutuhkan struktur data agar dapat berjalan dengan baik.

## 3. Dasar Teori
Struktur data merupakan cara atau metode untuk menyimpan dan mengatur data di dalam komputer agar dapat diakses serta diolah secara efisien. Dalam mata kuliah Struktur Data, salah satu bentuk penyimpanan yang banyak digunakan adalah Linked List, khususnya Double Linked List (DLL). Struktur ini bermanfaat ketika program memerlukan pengelolaan data yang dinamis — artinya data bisa dengan mudah ditambahkan, dihapus, atau diubah tanpa harus menggeser elemen seperti pada array.

### Berikut adalah Dasar Teori nya  :

- **1. Konsep Double Linked List (DLL)**
Double Linked List adalah versi lanjutan dari Single Linked List. Bedanya, setiap elemen atau node di DLL punya dua arah pointer:
prev untuk menunjuk ke node sebelumnya, dan
next untuk menunjuk ke node berikutnya.
Dengan dua arah ini, kita bisa menelusuri data dari depan ke belakang maupun dari belakang ke depan. Selain itu, penambahan dan penghapusan data juga jadi lebih mudah dilakukan, terutama di bagian tengah list, tanpa harus menggeser posisi data lain.

- **2. Peran Pointer dalam Linked List**
Pointer merupakan variabel khusus yang menyimpan alamat memori dari suatu data lain. Dalam DLL, pointer digunakan sebagai penghubung antar-node agar list tetap saling terhubung.
Contohnya:
P->next menunjukkan node setelah P,
P->prev menunjukkan node sebelum P.
Kalau pointer tidak diatur dengan benar, list bisa terputus dan menyebabkan error seperti kehilangan data atau program berhenti secara tiba-tiba. Karena itu, pengaturan pointer jadi hal penting dalam pembuatan linked list.

- **3. Konsep Fungsi smartInsert**
Fungsi smartInsert digunakan untuk menambahkan data baru dengan aturan atau kondisi tertentu, tidak hanya di awal atau di akhir list. Misalnya, data baru hanya dimasukkan jika nilainya ganjil, atau ditempatkan di antara dua nilai tertentu.
Fungsi ini biasanya menggunakan struktur if–else yang cukup banyak untuk menentukan posisi yang tepat. Selain itu, fungsi juga harus bisa menangani berbagai keadaan, seperti ketika list masih kosong atau saat data yang dimasukkan berada di tengah list.

- **4. Konsep Fungsi conditionalDelete**
Fungsi conditionalDelete dipakai untuk menghapus node yang memenuhi kondisi tertentu, misalnya menghapus semua angka genap atau semua angka yang lebih kecil dari nilai tertentu.
Prosesnya dilakukan dengan cara menelusuri list satu per satu, lalu memeriksa apakah data tersebut memenuhi syarat untuk dihapus. Jika iya, node akan dihapus dan pointer diatur ulang supaya hubungan antar-node tidak rusak. Ini menunjukkan bagaimana konsep traversing dan pengelolaan memori digunakan dalam DLL.

- **5. Konsep Traversal (Penelusuran Data)**
Traversal berarti proses menelusuri seluruh isi linked list, baik untuk menampilkan data, mencari nilai tertentu, atau melakukan perubahan. Dalam DLL, traversal bisa dilakukan dua arah, yaitu dari depan ke belakang (forward) dan dari belakang ke depan (backward).
Contohnya:
Forward: 3 5 7 8 6 4
Backward: 4 6 8 7 5 3
Fleksibilitas dua arah ini membuat DLL lebih unggul dibandingkan dengan Single Linked List.

- **6. Konsep Fungsi dan Modularisasi Program**
Dalam pembuatan program berbasis DLL, setiap operasi biasanya dibuat menjadi fungsi terpisah seperti insertFirst, insertLast, smartInsert, dan conditionalDelete. Tujuannya agar program lebih terstruktur, mudah dibaca, dan bisa digunakan kembali di bagian lain program.
Dengan pemisahan fungsi seperti ini, program menjadi lebih mudah untuk dikelola, diuji, dan dikembangkan. Prinsip ini disebut modularisasi, yang juga mendukung konsep abstraksi, yaitu setiap fungsi memiliki tanggung jawabnya masing-masing.

## 4. Guided
### 4.1 Guided 1 (dll_insert.cpp)
![alt text](Screenshot/Guided1-(dll_insert.cpp).png)

- **Penjelasan  :**
Program ini merupakan implementasi Double Linked List (DLL) dalam bahasa C++. Pada awalnya, dibuat struktur elmlist yang merepresentasikan satu node dengan tiga bagian utama: info untuk menyimpan data, next untuk menunjuk ke node berikutnya, dan prev untuk menunjuk ke node sebelumnya. Struktur List digunakan untuk menyimpan pointer ke elemen pertama (first) dan terakhir (last) dalam list.
Fungsi insertFirst menambahkan node di awal list, insertLast menambahkan di akhir, dan insertAfter menyisipkan node baru setelah node tertentu. Semua fungsi ini mengatur pointer next dan prev agar hubungan antar-node tetap konsisten. Fungsi alokasi digunakan untuk membuat node baru secara dinamis, sedangkan printInfo menelusuri list dari awal dan menampilkan semua datanya ke layar.
Dalam fungsi main, program membuat tiga node dengan nilai 1, 2, dan 3. Node pertama dimasukkan di awal, node kedua di akhir, dan node ketiga disisipkan di tengah setelah node pertama. Hasil akhirnya, data dalam list akan tampil sebagai 1 3 2.

- **Output  :**
![alt text](Screenshot/Output-Guided1-(dll_insert.cpp).png)

### 4.2 Guided 2 (dll_hapus.cpp)
![alt text](Screenshot/Guided2-(dll_hapus.cpp).png)

- **Penjelasan  :**
Program di atas merupakan implementasi Double Linked List (DLL) dalam bahasa C++ dengan operasi dasar insert dan delete pada berbagai posisi.
Struktur elmlist digunakan untuk menyimpan satu node yang berisi info (data), serta dua pointer next dan prev yang menunjuk ke elemen berikutnya dan sebelumnya. Struktur List menyimpan dua pointer utama, yaitu first (elemen awal) dan last (elemen akhir).
Fungsi alokasi berfungsi untuk membuat node baru secara dinamis dan mengisi nilainya, sedangkan dealokasi digunakan untuk menghapus node dari memori.
Fungsi insertFirst menambahkan elemen baru di bagian awal list. Fungsi printInfo menampilkan seluruh isi list dari awal ke akhir.
Fungsi deleteFirst menghapus elemen pertama, dan deleteLast menghapus elemen terakhir dalam list. Sementara itu, deleteAfter digunakan untuk menghapus elemen setelah node tertentu.
Pada bagian main(), program membuat list kosong, lalu menambahkan tiga elemen (1, 2, dan 3) ke dalam list menggunakan insertFirst, sehingga urutan data menjadi 3 2 1. Setelah itu, program menghapus elemen pertama dan elemen setelah elemen pertama, lalu mencetak hasil akhirnya. Dengan demikian, program ini memperlihatkan bagaimana elemen pada Double Linked List dapat ditambahkan dan dihapus secara dinamis sambil menjaga keterhubungan antar-node tetap konsisten.

- **Output  :**
![alt text](Screenshot/Output-Guided2-(dll_hapus.cpp).png)



## 5. Unguided
### 5.1 Unguided 1
![alt text](Screenshot/Unguided1.png)

- **Penjelasan  :**
Program ini merupakan implementasi Double Linked List (DLL) menggunakan bahasa C++. Struktur ini memungkinkan penyimpanan data yang saling terhubung dua arah — ke depan dan ke belakang — melalui dua pointer, yaitu next dan prev.
Struktur elmlist berisi data (info) dan dua pointer penghubung antar-node. Fungsi alokasi digunakan untuk membuat node baru di memori, sementara fungsi insertFirst, insertLast, insertAfter, dan insertBefore digunakan untuk menambahkan data pada posisi tertentu di dalam list, baik di awal, akhir, maupun di antara dua node.
Selain itu, fungsi printForward dan printReverse berfungsi untuk menelusuri dan menampilkan isi list dari depan ke belakang dan sebaliknya.
Pada fungsi main, program memulai dengan list kosong, kemudian melakukan beberapa proses penambahan data, dan akhirnya menampilkan hasilnya sebelum dan sesudah dilakukan penyisipan.
Secara keseluruhan, program ini menggambarkan bagaimana Double Linked List bekerja secara dinamis dalam pengelolaan data — mulai dari pembuatan, penyisipan di berbagai posisi, hingga penelusuran dua arah dengan efisien.

- **Output  :**
![alt text](Screenshot/Output-Unguided1.png)

### 5.2 Unguided 2
![alt text](Screenshot/Unguided2.png)

- **Penjelasan  :**
Program ini merupakan implementasi Double Linked List (DLL) dalam C++ yang berfokus pada operasi penghapusan data.
Struktur elmlist menyimpan data (info) serta pointer next dan prev, sedangkan List memiliki pointer first dan last untuk menunjuk elemen pertama dan terakhir.
Fungsi alokasi digunakan untuk membuat node baru, dan dealokasi untuk menghapus node agar memori tidak bocor.
Program juga memiliki fungsi untuk menambah elemen di awal (insertFirst), menghapus elemen di berbagai posisi (deleteFirst, deleteLast, deleteAfter), mencari data (findElm), menghapus berdasarkan nilai (deleteByValue), serta menghapus semua elemen (deleteAll).
Pada bagian main, program menambahkan beberapa data ke dalam list, menampilkan isi list, lalu melakukan penghapusan data tertentu (misalnya nilai 2 dan 5). Setelah itu, program menambah data baru kembali, mencetak hasilnya, dan akhirnya menghapus semua elemen sambil menampilkan jumlah data yang dihapus.
Secara singkat, program ini menunjukkan cara mengelola dan menghapus data dinamis dalam struktur Double Linked List dengan aman dan efisien.

- **Output  :**
![alt text](Screenshot/Output-Unguided2.png)

### 5.3 Unguided 3
![alt text](Screenshot/Unguided3.png)

- **Penjelasan  :**
Program ini merupakan implementasi Double Linked List (DLL) dalam bahasa C++ yang berfungsi untuk mengelola data secara dinamis, baik dari arah depan maupun belakang. Struktur Node menyimpan nilai serta pointer next dan prev, sedangkan DoubleList memiliki head dan tail untuk menandai elemen pertama dan terakhir.
Program ini menyediakan berbagai operasi seperti menambah data (insertFront, insertBack, insertAfter), menampilkan data (displayForward, displayBackward), dan menghapus data (removeFront, removeBack, removeNode, deleteByValue, deleteAll).
Selain itu, terdapat fitur smartInsert, yaitu fungsi yang otomatis menempatkan data baru di posisi yang tepat (awal, tengah, atau akhir) berdasarkan nilai tertentu.
Pada bagian main, program menguji seluruh fungsi tersebut — mulai dari penambahan, penghapusan, hingga pengosongan list — untuk menunjukkan cara kerja lengkap dari struktur Double Linked List secara efisien dan fleksibel.

- **Output  :**
![alt text](Screenshot/Output-Unguided3.png)

## 6. Kesimpulan
Kesimpulannya, Berdasarkan seluruh hasil pengerjaan dan penjelasan dari program-program di atas, dapat disimpulkan bahwa tujuan pembelajaran mengenai penerapan struktur data Double Linked List (DLL) telah tercapai dengan baik. Melalui berbagai latihan seperti insert, delete, insertBefore, insertAfter, deleteByValue, dan deleteAll, saya memahami bagaimana cara mengelola data secara dinamis menggunakan konsep pointer.
Struktur Double Linked List memungkinkan akses dan manipulasi data dari dua arah (maju dan mundur), sehingga proses penyisipan maupun penghapusan elemen menjadi lebih efisien dan fleksibel dibandingkan dengan Single Linked List. Selain itu, penggunaan fungsi-fungsi terpisah seperti alokasi, dealokasi, insertFirst, deleteLast, hingga printInfo membantu membuat program lebih terstruktur, mudah dibaca, dan modular.
Secara keseluruhan, praktikum ini memberikan pemahaman mendalam tentang cara kerja dan penerapan nyata Double Linked List dalam bahasa C++, serta melatih kemampuan berpikir logis dalam merancang dan mengimplementasikan algoritma pengelolaan data dinamis.

## 7. Referensi
1. GeeksforGeeks. “Doubly Linked List | Set 1 (Introduction and Insertion).” https://www.geeksforgeeks.org/doubly-linked-list/
2. Sjafari, A. N., & Mulyani, A. (2018). IMPLEMENTASI DOUBLE LINKED LIST PADA APLIKASI ANTRIAN KLINIK. Jurnal Ilmiah Informatika, 3(01).
3. TutorialsTeacher. “C++ Pointers.” https://www.tutorialsteacher.com/cpp/cpp-pointers
4. Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson. 