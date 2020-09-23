# SZE-MOSZE-2020-MarGit

A program parancssorból futtatható, megadandó parancssori argumentumok rendre: 1. játékos: neve, élete, sebzése, 2. játékos: neve, élete, sebzése

A Character.cpp fájlban található az Character osztály. 
    Attribútumok: name, hp, damage.
    Metódusok: konstruktor, getterek, attack, stat_out, isDead.

A Source.cpp megvizsgálja, hogy 7 (6+ fájlnév) paramétert kapott-e, majd ha megfelelő számú paraméter van, létrehoz két Character objektumot és átadja az auto_combat függvénynek
A program addig fut, míg az auto_combat-nak adott két karakter közül az egyik élete el nem éri a 0-t
