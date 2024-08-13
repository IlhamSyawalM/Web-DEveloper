//! Contoh asynchronous callback
// Asynchronous ngelompatin function yg lama, biar code dijalanin sampe akhir (kaya ada 2 jalan, tapi engga)

console.log("satu");
setTimeout(() => {
  console.log("dua");
}, 5000);
console.log("tiga");
console.log("empat");
console.log("lima");
console.log("enam");
