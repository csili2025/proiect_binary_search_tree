# proiect_binary_search_tree
Hangman is a classic word-guessing game. 

   The computer generates a word that players must guess. The chosen word is represented by underscores, where each underscore indicates the position of a letter. Players take turns guessing letters, and if a guessed letter is correct, it appears in the appropriate position. If the guess is incorrect, a part of the hanging figure is drawn. The figure typically consists of six lives, meaning the player has six or seven lives. The goal is to guess the word before the full figure is completed. If the players correctly guess the word, they win. If the figure is fully drawn before the word is guessed, they lose. At the end of the game, if the player wishes, they can view the dictionary using Pre-order or In-order traversal.
   At the beginning of the game, the player can choose a difficulty level by pressing the 1, 2, or 3 key. The first level is easy and contains words with 4-5 letters, the second is medium with words of 6-7 letters, and the third is hard.

Once the player selects the difficulty level, the game control panel appears, where various functions are available:

 - Pressing the 1 key starts the game.
 - The 2 key displays the game rules if the player needs clarification on the gameplay.
 - The 3 key allows the player to delete a word, while the 4 key enables adding new words to the game.
 - If the player wants to change the difficulty level, they can do so by pressing the 5 key.
 - To exit the game, the 0 key can be used.
 - 
During each round, the player must guess a letter. If the guess is correct, the letter appears in the word in its correct position. If the guess is incorrect, the player's remaining lives decrease.

 - The "help" command allows the player to reveal the first letter of the word, but it costs one life.
 - The "guess" command lets the player guess the entire word. If the guess is correct, they win and gain one extra life. If the guessed word exists in the dictionary but is not the correct word, they lose one life.

New words are inserted into a binary search tree (BST) while maintaining alphabetical order. The insertion process compares the new word with the current node’s word to determine whether to continue in the left or right subtree. If the appropriate subtree is empty, a new node is created for the word. Otherwise, the insertion continues recursively in the correct direction. This ensures that the tree remains sorted and efficiently organized at all times.
