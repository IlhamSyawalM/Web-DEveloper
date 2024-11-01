 // ! Tanpa menggunakan object.create() !

// const methodMahasiswa = {
//   makan: function (porsi) {
//     this.energi += porsi;
//     let hasil = console.log(
//       `Halo ${this.nama}, Selamat Makan !. Energi anda sekarang ${this.energi}.`
//     );
//     return hasil;
//   },

//   main: function (lama) {
//     this.energi -= lama;
//     let hasil = console.log(
//       `Halo ${this.nama}, Selamat bermain !. Energi anda sekarang ${this.energi}.`
//     );
//     return hasil;
//   },

//   tidur: function (jam) {
//     this.energi += jam * 2;
//     let hasil = console.log(
//       `Halo ${this.nama}, Selamat tidur !. Energi anda sekarang ${this.energi}.`
//     );
//     return hasil;
//   },
// };

// function mahasiswa(nama, energi) {
//   let maha = {};
//   maha.nama = nama;
//   maha.energi = energi;

//   maha.makan = methodMahasiswa.makan;
//   maha.main = methodMahasiswa.main;
//   maha.tidur = methodMahasiswa.tidur;

//   return maha;
// }

// let ilham = mahasiswa("Ilham Syawal Mustaqim", 20);
// let jihan = mahasiswa("Jihan Febrizki", 20);


// ! Menggunakan object.create() !

const methodMahasiswa = {
  makan: function (porsi) {
    this.energi += porsi;
    let hasil = console.log(
      `Halo ${this.nama}, Selamat Makan !. Energi anda sekarang ${this.energi}.`
    );
    return hasil;
  },

  main: function (lama) {
    this.energi -= lama;
    let hasil = console.log(
      `Halo ${this.nama}, Selamat bermain !. Energi anda sekarang ${this.energi}.`
    );
    return hasil;
  },

  tidur: function (jam) {
    this.energi += jam * 2;
    let hasil = console.log(
      `Halo ${this.nama}, Selamat tidur !. Energi anda sekarang ${this.energi}.`
    );
    return hasil;
  },
};

function mahasiswa(nama, energi) {
  let maha = Object.create(methodMahasiswa);
  maha.nama = nama;
  maha.energi = energi;

  return maha;
}

let ilham = mahasiswa("Ilham Syawal Mustaqim", 20);
let jihan = mahasiswa("Jihan Febrizki", 20);

delete ilham.energi;
console.log(ilham)