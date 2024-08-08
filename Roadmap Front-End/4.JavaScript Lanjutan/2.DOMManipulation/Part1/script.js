// DOM Manipulation Part1

// Element.innerHTML
var judul = document.getElementById("judul");
judul.innerHTML = " <em> Yanqeu cantik </em> ";

// Element.style
const sectionA = document.querySelector("section#a");
sectionA.style.backgroundColor = "lightblue";
sectionA.style.color = "salmon";

// element.setAttribute()
const Judul = document.getElementsByTagName("h1")[0];
Judul.setAttribute("class", "Ilham");

const a = document.querySelector("#a a");
a.setAttribute("id", "link");

// Element.classList
const p2 = document.querySelector(".p2");

// classList.add
p2.classList.add("kanjut");

// classList.remove
p2.classList.remove("kanjut");

// classList.toggle
p2.classList.toggle("kanjut");

document.body.classList.toggle("biru-muda");

// classList.item
p2.classList.add("satu");
p2.classList.add("dua");
p2.classList.add("tiga");

p2.classList.item(2);

// classList.contains
p2.classList.contains("empat");

// classList.replace
p2.classList.replace("dua", "lima");
