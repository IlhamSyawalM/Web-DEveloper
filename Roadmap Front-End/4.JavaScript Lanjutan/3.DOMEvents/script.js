// Percobaan 1

const p3 = document.querySelector(".p3");

function ubahWarnaP3() {
  p3.style.backgroundColor = "lightblue";
}

// Percobaan 2

const p2 = document.querySelector(".p2");

function ubahWarnaP2() {
  // p2.style.backgroundColor = "lightblue";
  //! optional
  p2.classList.toggle('birumuda');
}

p2.onclick = ubahWarnaP2;

// Percobaan 3
const p4 = document.querySelector("section#b p");
p4.addEventListener("click", function () {
  const ul = document.querySelector("section#b ul");
  const li = document.createElement("li");
  const isi = document.createTextNode("Item baru");
  li.appendChild(isi);
  ul.appendChild(li);
});
