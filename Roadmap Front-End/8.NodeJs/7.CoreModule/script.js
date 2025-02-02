const fs = require("fs");
const readLine = require("readline");

const rl = readLine.Interface({
  input: process.stdin,
  output: process.stdout,
});

//! 1. Membuat question untuk mengambil data yg dibutuhkan
rl.question("Masukan Nama anda : ", (nama) => {
  rl.question("Masukan no Telepon anda : ", (no) => {
    //Memasukan data yg didapatkan menjadi array
    const contact = { nama, no };

    //! 2. Ambil data dari jsonnya pake readFile
    const readFile = fs.readFileSync("data/contact.json", "utf-8");
    if (readFile.length != 0) {
      //merubah data menjadi array
      const contacts = JSON.parse(readFile);
      //Memasukan data ke array
      contacts.push(contact);

      //! 3. Timpa data lama pake data baru.
      //Memasukan data array ke file json, tetapi harus dijadikan string
      fs.writeFileSync("data/contact.json", JSON.stringify(contacts));
      console.log(contacts);
    }
    rl.close();
  });
});
