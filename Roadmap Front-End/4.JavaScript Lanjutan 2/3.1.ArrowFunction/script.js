//! Function Declaration !//
function cobaan(siapa) {
  console.log(`Halo, ${siapa}`);
}

cobaan("kuda");

//! Function Expression !//
let hasil = function (nama) {
  return `Halo, ${nama}`;
};

console.log(hasil("ilham"));

//! Arrow Function !//
// Tanpa argument
let enol = () => `Hello World !`;

// Satu argument
let satu = (kita) => `Halo, ${kita}`;

// Banyak argument
let baru = (parameter, waktu) => {
  return `Hai, ${parameter}. Sekarang jam ${waktu}`;
};

console.log(enol());
console.log(satu("shanum"));
console.log(baru("jihan", "sepuluh"));

// Contoh lain
let mahasiswa = ["Ilham Syawal M", "Jihan Febrizki", "Shanum"];

// Cara lama
// let totalHuruf = mahasiswa.map(function (nama) {
//   return nama.length;
// });
// console.log(totalHuruf);

// Dengan Arrow Function
let totalHuruf = mahasiswa.map((nama) => nama.length);

console.log(totalHuruf);
console.table(totalHuruf);

// return object

let informasi = mahasiswa.map((nama) => ({ nama, jumlahHuruf: nama.length }));

console.table(informasi);
