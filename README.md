
![screenshot](https://github.com/MBurdziej/Pentago_game/assets/108184079/98695ef1-9567-43c5-8fa9-c1605690a0fc)


Project PENTAGO is a console implementation of the popular logic game. Players compete against each other, aiming to align five of their tokens in a row, column, or diagonal on a rotating board.

Features:
1. Tic-Tac-Toe Game: The program also allows playing traditional Tic-Tac-Toe on a 6x6 board.
2. Pentago Game: Similar to Tic-Tac-Toe but the board consists of 4 quadrants that can be rotated.
3. Win Condition Detection: Automatic detection of victory and informing the winner.
4. Move Validation: The program checks whether a player can make a specific move.
5. Interactivity: Keyboard support following the game rules, the ability to undo moves, choose tokens at the beginning of the game, and a pause option.
6. Gameplay Review: After finishing the game, players can review its progress backward and forward.
7. Board Framing: Aesthetic board framing is used with graphical characters.
8. Time Limit: Optionally, a time limit can be set for the entire game. Players' time is counted during their moves.

Program Control:
- q,w,a,s – selection of the board part respectively: top left, top right, bottom left, bottom right.
- 1..9 – selection of a field on the part of the board as on the numeric keyboard, e.g., 1 is the bottom-left field.
- z,x – rotation respectively: clockwise, counterclockwise.
- p – pause.
- u – undo.
- o – loading a predefined board.
- m – entering options.
- h – entering program description.

A move consists of first selecting a board part and field (e.g., q5), then selecting a board part and rotation (e.g., az). Exit from options: p, m, h with any chosen command.
