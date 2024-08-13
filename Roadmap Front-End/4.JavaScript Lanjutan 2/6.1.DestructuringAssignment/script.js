//! Array
// // (cara lama)
// const kenal = ["halo", "nama", "saya", "ilham"];

// const salam = kenal[0];
// const nama = kenal[2];

// console.log(salam);
// console.log(nama);

// console.log("------------");
// console.log("------------");
// console.log("------------");

// // Destructuring array
// const [a, b, c, d] = kenal;

// const [e, , , f] = kenal; //Di skip indeks 1 dan 2

// console.log(a);
// console.log(b);
// console.log(c);
// console.log(d);

// console.log("------------");
// console.log("------------");
// console.log("------------");

// // penerapan

// // Penukaran nilai
// let awal = 1;
// let akhir = 2;

// [awal, akhir] = [akhir, awal];

// console.log(awal);
// console.log("------------");
// console.log("------------");
// console.log("------------");

// // return value pada function
// function coba() {
//   return [24, 30];
// }

// [ilham, syawal] = coba();

// console.log(ilham);
// console.log("------------");
// console.log("------------");
// console.log("------------");

// // variabel tidak diketahui banyaknya

// const [v, ...values] = [1, 2, 3, 4, 5];
// const [q,w,o,r] = values;

// console.log(v);
// console.log(values);
// console.log(o);
// console.log("------------");
// console.log("------------");
// console.log("------------");

//! Object

const mhs = {
  id: 123,
  nama: "Ilham Syawal M",
  umur: 24,
};

// cara lama
const umurku = mhs.umur;

// Cara baru
const { nama, umur } = mhs;

console.log(nama);
console.log("------------");
console.log("------------");
console.log("------------");

// cara baru
({ namakuh, umurkuh } = { namakuh: "Shanum Ainun Azzahra", umurkuh: 4 });
console.log(namakuh);
console.log("------------");
console.log("------------");
console.log("------------");

// Mengganti nama panggilan
const { nama: a, umur: b } = mhs;

console.log(a);
console.log("------------");
console.log("------------");
console.log("------------");

// Memberikan default value
const { id: i, nama: c, umur: d, email: e = `${c}@gmail.com` } = mhs;

console.log(i);
console.log(e);
console.log("------------");
console.log("------------");
console.log("------------");

// dengan function
function ambilNilai({ id, nama }) {
  return console.log(id), console.log(nama);
}

ambilNilai(mhs);
