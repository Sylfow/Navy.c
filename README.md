# Navy.c

Epitech Navy projects, an exercice who works with signit between 2 terminals.
A naval battle on a same computer with 2 players.

### USAGE

Made on Linux
With your Termina, built the program using the Makefile with "make" command.
And then
```
     ./navy [first_player_pid] navy_positions
```
### DESCRIPTION
     first_player_pid:  only for the 2nd player.  pid of the first player.
     navy_positions:  file representing the positions of the ships.
     navy_pisition is file.txt with positions.
#### Exemple:
    2:C1:C2
    3:D4:F4
    4:B5:B8
    5:D7:H7

First number-> size of the ship.
Second letter + Number -> position 1 to
Thirds letter + Number -> position 2

When the first player launch the game, this will give him his PID.
The Second player witl use the first player's PID on a second termial and this will connect both player.

### Authors

* **Axel Dannion** - *Initial work* - [Sylfow](https://github.com/Sylfow)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

### License

This project is licensed under the GNU3 License - see the [LICENSE](LICENSE) file for details
