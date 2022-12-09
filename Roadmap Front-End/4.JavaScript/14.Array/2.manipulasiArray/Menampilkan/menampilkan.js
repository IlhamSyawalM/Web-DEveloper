var satu = ["Ilham", "Syawal", "Mustaqim", "Jihan", "Febrizki"];
var angka = [1, 2, 3, 4, 5, 6, 7, 8];
var x = [3, 5, 1, 2, 6, 8, 9, 7];

// !Loop
for (var i = 0; i < satu.length; i++) {
  console.log(satu[i]);
}

console.log(" ");
console.log(" ");
console.log(" ");

// Yg kerennya gini
for (var i = 0; i < satu.length; i++) {
  console.log("Nama Mahasiswa ke " + (i + 1) + " adalah " + satu[i]);
}

console.log(" ");
console.log(" ");
console.log(" ");

//! Method Join
console.log(satu.join(" "));

console.log(" ");
console.log(" ");
console.log(" ");

//! Method forEach
satu.forEach(function (e) {
  console.log(e);
});

console.log(" ");
console.log(" ");
console.log(" ");

// Kerennya gini
satu.forEach(function (e, i) {
  console.log("Mahasiswa ke " + (i + 1) + " adalah " + e);
});

console.log(" ");
console.log(" ");
console.log(" ");

//!Method Map
var angka2 = angka.map(function (e) {
  return e * 2;
});
console.log(angka2);

console.log(" ");
console.log(" ");
console.log(" ");

// !Method sort
x.sort();
console.log(x);
