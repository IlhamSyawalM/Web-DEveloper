//! Syncronous
// const getUser = (id) => {
//   let name = "";

//   if (id === 1) {
//     name = "Ilham";
//   } else if (id === 2) {
//     name = "Syawal";
//   }
//   return id, name;
// };

// const Satu = getUser(1);
// console.log(Satu);

// const Dua = getUser(2);
// console.log(Dua);

// console.log("Mustaqim");

//! Asyncronous
const getUser = (id, cb) => {
  const time = id === 1 ? 3000 : 2000;

  setTimeout(() => {
    let name = "";
    if (id === 1) {
      name = "Ilham";
    } else if (id === 2) {
      name = "Syawal";
    }
    cb(id, name);
  }, time);
};

const Satu = getUser(1, console.log);

const Dua = getUser(2, console.log);

console.log("Mustaqim");
