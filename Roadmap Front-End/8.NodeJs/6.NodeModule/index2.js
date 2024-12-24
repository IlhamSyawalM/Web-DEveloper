const PI = 3.14;
const again = (x) => {
  return `Halo, nama saya ${x}`;
};
const mahasiswa = {
  nama: "Ilham Syawal M",
  umur: 25,
  cetak() {
    return `Nama saya ${this.nama} & berumur ${this.umur}`;
  },
};

//! Cara awal
// module.exports.PI = PI;
// module.exports.again = again;
// module.exports.mahasiswa = mahasiswa;

//! Dipermudah
// module.exports = {
//   PI: PI,
//   again: again,
//   mahasiswa: mahasiswa,
// };

//! Dipermudah (nyamain nama)
module.exports = { PI, again, mahasiswa };
