// Core Module

//! File system
const fs = require("fs");

//! Menuliskan string ke dalam file dgn Synchronous
try {
  fs.writeFileSync("data/test.txt", `Hello World secara Synchronous!`);
} catch (error) {
  console.log(error);
}

//! Menuliskan string ke dalam file dgn Asynchronous
// fs.writeFile("data/test.txt", `Hello world scara Asynchronous2`, (e) => {
//   console.log(e);
// });

//! Membaca string dari dalam file dgn Synchronous
// const x = fs.readFileSync("data/test.txt");
// console.log(x.toString());

// const x = fs.readFileSync("data/test.txt", 'utf-8');
// console.log(x);

//! Membaca string dari dalam file dgn Asynchronous
// fs.readFile("data/test.txt", "utf-8", (err, data) => {
//   if (err) throw err;                                     //? throw = langsung return data
//   console.log(data);
// });

//! Read Line
const readLine = require("readline");

const rl = readLine.Interface({
  input: process.stdin,
  output: process.stdout,
});

// rl.question("Masukan nama anda : ", (nama) => {
//   console.log(`Terima Kasih ${nama}`);
//   rl.close();
// });

// rl.question("Masukan nama anda : ", (nama) => {             //? Membuat pertanyaan lebih dari 1
//   rl.question("Masukan No Telepon anda : ", (no) => {
//     console.log(`Nama anda : ${nama} dgn no telepon anda : ${no}`);
//     rl.close();
//   });
// });
