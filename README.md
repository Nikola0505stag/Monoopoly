
<img src="readmePic.png" alt="MonOOPoly Logo" width="400" padding = "50"/>

# MonOOPoly 🎲💼

## 📌 Project Description

**MonOOPoly** is a fully console-based C++ implementation of the classic **Monopoly** board game, developed as part of the **Object-Oriented Programming (OOP) Lab** course at **Faculty of Mathematics and Informatics, Sofia University**.

The game aims to replicate the strategic elements of Monopoly, such as:
- Buying, selling, and managing properties
- Drawing event cards
- Dealing with jail, taxes, and chance
- Trading between players
- Building houses and hotels (castles)

## 🕹️ Game Rules (Brief Overview)

- **2 to 6 players** take turns rolling two dice and moving around the board.
- Players can buy properties, collect rent, draw cards, and go to jail.
- If a player lands on an owned property, they must pay rent.
- The last remaining player with money is the **winner**.

## ⚙️ Key Features

- ✅ Dynamic game board with properties and special tiles
- ✅ Deck of cards with random effects (teleport, gain/lose money, etc.)
- ✅ Jail mechanics, parking, start bonus, bank
- ✅ Full player money management
- ✅ Property trading and mortgaging
- ✅ OOP design using classes like `Card`, `Player`, `Deck`, `Game`
- ✅ Cloning cards using polymorphism
- ✅ Random shuffle of the deck using Fisher-Yates

## 🧠 OOP Concepts Used

- Abstraction via abstract base classes (`Card`)
- Inheritance and virtual methods for card types
- Polymorphism in card drawing and actions
- Encapsulation of player state and actions
- Rule of 5 – managing dynamic memory in `Deck`, `Game`, `Player`
