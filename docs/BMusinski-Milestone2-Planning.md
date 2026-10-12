> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**
→   The Fallen Kingdom
  
**What does your program currently do? (1–3 sentences)**   
→ The Fallen Kingdom currently has a working main menu where players can start a new game, view credits, or quit. Players can also create their character by choosing a name and selecting a class. The game also features a custom engine with actor management, deferred destruction, input validation.

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   The main menu, credits screen, character creation, and class selection are all working. The custom game engine also handles actor management, deferred destruction, dialogue, and input validation.
  
**What is NOT working or incomplete?**   
→   The battle sequence is still incomplete, along with enemy creation, combat mechanics, inventory, and the player store. These are the main features I plan to work on next to make the game fully playable.
  
**What feels confusing or messy in your code?**   
→ The character creator feels a bit messy because it handles multiple things, like character naming, class selection, and assigning stats. I want to reorganize it to make the code cleaner, easier to read, and easier to expand in the future.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
→   Battle sequence
  
**What does this feature do?**   
→   Allows players to fight enemies using attacks, spells, and other combat actions in a turn-based battle system.
  
**Why is this feature important?**   
→   This is one of the core gameplay mechanics. Implementing it will make the game playable and bring me closer to having a working prototype.
  
---
### Feature 2  
**Name:**   
→   Inventory System
  
**What does this feature do?**   
→   Allows players to collect, store, and manage items such as weapons, armor, and potions.
  
**Why is this feature important?**   
→   Gives players the ability to manage their equipment and resources throughout their adventure.
  
---
  
### Feature 3 (optional)  
**Name:**   
→   Store System
  
**What does this feature do?**   
→  Allows players to buy and sell items such as weapons, armor, and potions using in-game currency.
  
**Why is this feature important?**   
→   Gives players a way to spend earned currency, upgrade their equipment, and prepare for future battles.
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   Yes, I plan to create new classes for the Battle System, Inventory, Items, and Store. I may also need an Enemy class to handle enemy stats and combat behavior. Along with the save system namespace.
  
**Will you modify any existing classes? How?**   
→   Yes, I plan to modify the Player class to support inventory, equipment, and combat mechanics. I will also update the GameSession class to handle battles, stores, and saving/loading progress.
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   I plan to use vectors to store enemies, inventory items, and store items. I may also use structs to organize item data, character stats, and save/load information.
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   Displays the main menu with New Game, Load Game, Credits, and Quit.
2. User chooses →   Starts a new game, creates a character, selects a class, and enters the game.
3. Program responds →   Displays dialogue and allows the player to fight enemies, manage inventory, and visit stores.
4. Loop/next step →   The player continues exploring, fighting enemies, and managing items until they save or quit the game.
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   Make instructions easier to understand so players know what actions they can take.
  
- Better error handling:   
→   Improve input validation to prevent crashes and handle invalid inputs without interrupting gameplay.
  
- Improved menu/navigation:   
→   Make it easier for players to navigate between menus, return to previous screens, and access inventory, stores, and combat options.
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   Implementing the battle sequence and making sure the different systems work together without causing bugs.
  
**What is your plan if you get stuck?**   
→   Break the problem into smaller parts, use debugging tools, research possible solutions, and review my code to find what's causing the issue.
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   Class design and object-oriented programming (OOP).
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   Practice organizing classes, reducing unnecessary dependencies, and debugging issues as I implement new gameplay systems.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ ]   Implement the turn-based battle sequence.
- [ ]   Create and implement the save/load system.
- [ ]   Develop the inventory and item management system.
- [ ]   Implement the player store for buying and selling items.
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [ ] Do I know what I’m building this week?   
- [ ] Do I know where to start?   
- [ ] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.