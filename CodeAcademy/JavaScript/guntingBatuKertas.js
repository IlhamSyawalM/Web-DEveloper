const getUserChoice = (userInput) => {
  userInput = userInput.toLowerCase();

  if (
    userInput === "rock" ||
    userInput === "scissors" ||
    userInput === "paper" ||
    userInput === "bomb"
  ) {
    return userInput;
  } else {
    console.log("Input doesn't correct");
  }
};
// console.log(getUserChoice("Rock"));
// console.log(getUserChoice("stone"));

const getComputerChoice = () => {
  var pc = Math.floor(Math.random() * 3);
  if (pc == 0) {
    return "rock";
  } else if (pc == 1) {
    return "paper";
  } else if (pc == 2) {
    return "scissors";
  }
};
// console.log(getComputerChoice());

const determineWinner = (userChoice, computerChoice) => {
  if (userChoice == computerChoice) {
    return "The game was a tie";
  } else if (userChoice == "rock") {
    if (computerChoice == "paper") {
      return "computer won";
    } else {
      return "user won";
    }
  } else if (userChoice == "paper") {
    if (computerChoice == "scissors") {
      return "computer won";
    } else if (computerChoice == "rock") {
      return "user won";
    }
  } else if (userChoice == "scissors") {
    if (computerChoice == "rock") {
      return "computer won";
    } else {
      return "user won";
    }
  } else if (userChoice == "bomb") {
    return "User always Won !!!";
  }
};
// console.log(determineWinner("scissors", "paper"));

const playGame = () => {
  let userChoice = getUserChoice("bomb");
  let computerChoice = getComputerChoice();
  console.log(userChoice);
  console.log(computerChoice);
  console.log(determineWinner(userChoice, computerChoice));
};

playGame();
