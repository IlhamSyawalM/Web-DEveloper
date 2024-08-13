//! Callback

// // Synchronous function
function halo(nama) {
  alert(`Halo, ${nama}`);
}

function pesan(callback) {
  const nama = prompt("Masukan Nama :");
  callback(nama);
}

pesan(halo);

// atau seperti ini

function tampil(name) {
  const isi = prompt("Masukkan nama :");
  name(isi);
}

tampil((isi) => alert(`Halo semuanya, ${isi}`));

//! Asynchronous Function

const mhs = [
  {
    nama: "Ilham Syawal Mustaqim",
    nim: "24040117140041",
    email: "ilhamsyawal87@gmail.com",
    jurusan: "Fisika",
    idDosenWali: 1,
  },
  {
    nama: "Jihan Febrizki",
    nim: "24040117140042",
    email: "jihanfebrizkii@gmail.com",
    jurusan: "Biologi",
    idDosenWali: 2,
  },
  {
    nama: "Shanum Ainun Azzahra",
    nim: "24040117140043",
    email: "Shanumaa@gmail.com",
    jurusan: "Anak",
    idDosenWali: 2,
  },
];

console.log("Mulai 1");
mhs.forEach((m) => {
  for (let c = 0; c < 1000000; c++) {
    let date = new Date();
    // console.log(date);  
  }
  console.log(m.nama);
});
console.log("selesai");
console.log("1------");
console.log("-------");
console.log("-------");

// ! Asynchronous Callback
// dengan vanilla Javascript

function getDataMahasiswa(url, success, error) {
  let xhr = new XMLHttpRequest();

  xhr.onreadystatechange = function () {
    if (xhr.readyState === 4) {
      if (xhr.status === 200) {
        success(xhr.response);
      } else if (xhr.status === 404) {
        error();
      }
    }
  };
  xhr.open("get", url);
  xhr.send();
}

function success(result) {
  const isi = JSON.parse(result);
  isi.forEach((m) => console.log(m.nim));
}

function error() {
  console.log("filenya ga ada");
}

console.log("Mulai 2");
getDataMahasiswa("mahasiswa.json", success, error);
console.log("Selesai");
console.log("2------");
console.log("-------");
console.log("-------");

// dengan jQuery (Ajax)

console.log("Mulai 3");
$.ajax({
  url: "mahasiswa.json",
  success: (isian) => {
    isian.forEach((x) => console.log(x.nama));
  },
  error: (e) => {
    console.log(e.responseText);
  },
});
console.log("selesai");
