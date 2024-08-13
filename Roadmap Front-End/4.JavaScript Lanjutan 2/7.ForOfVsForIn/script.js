// For of untuk array //

const mhs = ["ilham", "jihan", "shanum"];
const garis = "----------------------";

// ! Untuk array
// for biasa
for (let i = 0; i < mhs.length; i++) {
  console.log(`for biasa = ${mhs[i]}`);
}
console.log(garis);
console.log(garis);
console.log(garis);

// forEach
mhs.forEach((x, i) => console.log(`forEach = ${x}, dengan indeks ke ${i}`));
console.log(garis);
console.log(garis);
console.log(garis);

// Map
const hasil = mhs.map((x) => console.log(`Map = ${x}`));
console.log(garis);
console.log(garis);
console.log(garis);

// For of
for (const x of mhs) {
  console.log(`for of ${x}`);
}
console.log(garis);
console.log(garis);
console.log(garis);

for (const [i, m] of mhs.entries()) {
  console.log(`For of ${m}, dengan index ${i}`);
}
console.log(garis);
console.log(garis);
console.log(garis);

//! Untuk String
const namaIlham = "ilham";
for (const x of namaIlham) {
  console.log(x);
}
console.log(garis);
console.log(garis);
console.log(garis);

//! Untuk Nodelist
const liNama = document.querySelectorAll(".nama");

liNama.forEach((x) => {
  console.log(x.innerHTML);
});
console.log(garis);
console.log(garis);
console.log(garis);

for (const n of liNama) {
  console.log(n.innerHTML);
}
console.log(garis);
console.log(garis);
console.log(garis);

//! Untuk Argument
function sumAngka() {
  let jumlah = 0;
  for (x of arguments) {
    jumlah += x;
  }
  return jumlah;
}

console.log(sumAngka(1, 2, 3, 4, 5));
console.log(garis);
console.log(garis);
console.log(garis);

// For in Untuk object //
const maha = {
  nama: "ilham Syawal M",
  nim: 24040117140041,
  email: "ilhamsyawal87@gmail.com",
};

for (const x in maha) {
  console.log(x); //Nama variable
  console.log(maha[x]); //Isi vairable
}
