# SZE-MOSZE-2020-MarGit

A program 3 json fájlból olvassa be a karakterek tulajdonságait a json_parser osztály metódusainak segítségével, majd egy output.txt-be tölti be az eredményt.
A hozzáadott workflow gondoskodik arról, hogy a program upgrade/update-je csak akkor kerülhessek GH-ra, ha az lefordul és az output-ja megegyezik az előre kiszámolt result-tal.
A json_parser osztályhoz készült 3 metódus, ezekhez 1-1-1 unit test. A parser függvények lehetséges bemenetei: fájl név, fájl tartalom (string), istream. 2xParse() (overloadolva), 1x ParseContent()
A unit teste googletest segítségével készültek.

A Source.cpp megvizsgálja, hogy a json fileok megnyitásakor történik-e hiba, majd ha megfelelő fileokat kap, létrehoz két Character objektumot és átadja az auto_combat függvénynek, különben pedig -99 hibakódot dob vissza.
A program addig fut, míg az auto_combat-nak adott két karakter közül az egyik élete el nem éri a 0-t
