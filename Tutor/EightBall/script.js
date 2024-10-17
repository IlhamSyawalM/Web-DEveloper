alert("Selamat datang");
let lagi = true;

while (lagi === true) {
  var userName = prompt("Isi nama terlebih dahulu");
  if (userName.length != 0) {
    alert(`Hallo, ${userName}`);
  } else {
    alert(`Hallo siapapun disana`);
  }
  const userQuestion = prompt("Want to play Magic Eight Ball ?");
  if (userQuestion == "Yes" || userQuestion == "yes") {
    let randomNumber = Math.floor(Math.random() * 8);
    let eightBall = "";
    switch (randomNumber) {
      case 0:
        eightBall = "It is certain";
        break;
      case 1:
        eightBall = "It is decidedly so";
        break;
      case 2:
        eightBall = "Reply hazy try again";
        break;
      case 3:
        eightBall = "Cannot predict now";
        break;
      case 4:
        eightBall = "Do not count on it";
        break;
      case 5:
        eightBall = "My sources say no";
        break;
      case 6:
        eightBall = "Outlook not so good";
        break;
      case 7:
        eightBall = "Signs point to yes";
        break;
    }

    alert(eightBall);
  } else {
    alert("oke");
  }

  lagi = confirm("Mau coba lagi ?");
}
alert("Dadah");
