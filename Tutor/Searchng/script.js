let array = ["tea", "eat", "ate", "ant", "nat", "not"];
let result = [];

//! First
// for (let i = 0; i < array.length; i++) {
//   const element = array[i].split("").sort().join("");
//   result.push(element);
// }
// console.log(result);

//! Final
let groups = new Map();

for (let i = 0; i < array.length; i++) {
  const element = array[i].split("").sort().join("");

  if (!groups.has(element)) {
    groups.set(element, []);
  }
  groups.get(element).push(array[i]);
}
result = Array.from(groups.values());

console.log(result);
