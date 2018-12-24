/*
 * fight.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: tyrone8980
 */
#include <ncurses.h>
#include <iostream>
#include "game.h"
//ALL ascii art created by darren rion hall and Christopher Johnson!!! on their free website
//listed below... I did not!! create this art
//link is http://chris.com/ascii/index.php?art=creatures/dragons
void dragon()
{

 printw("                                     ,o""""o \n");
 printw("                                  ,o$\"     o\n");
 printw("                               ,o$$$\n");
 printw("                             ,o$$$'\n");
 printw("                           ,o$\"o$'\n");
 printw("                         ,o$$\"$\"'   \n");
 printw("                      ,o$\"$o\"$\"'    \n");
 printw("                   ,oo$\"$\"$\"$\"$$`                      ,oooo$$$$$$$$oooooo.  \n");
 printw("                ,o$$$\"$\"$\"$\"$\"$\"o$`..             ,$o$\"$$\"$\"'            `oo.o\n");
 printw("             ,oo$$$o\"$\"$\"$\"$  $\"$$$\"$`o        ,o$$\"o$$$o$'                 `o\n");
 printw("          ,o$\"$\"$o$\"$\"$\"$  $\"$$o$$o $$o`o   ,$$$$$o$\"$$o'                    $\n");
printw("        ,o\"$$\"'  `$\"$o$\" o$o$o\"  $$$o$o$oo\"$$$o$\"$$\"$o\"'                     $\n");
printw("     ,o$\"'        `\"$ \"$$o$$\" $\"$o$o$$\"$o$$o$o$o\"$\"$\"`\"\"o                   ' \n");
printw("   ,o$'          o$ `\"$\"$o \"$o$$o$$$\"$$$o\"$o$$o\"$$$    `$$  \n");
printw("  ,o'           (     `\" o$\"$o\"$o$$$\"$o$\"$\"$o$\"$$\"$ooo|  `` \n");
printw(" $\"$             `    (   `\"o$$\"$o$o$$ \"o$o\"   $o$o\"$\"$    )\n");
printw("(  `                   `    `o$\"$$o$\" \"o$$     \"o /|\"$o\"\n");
 printw(" `                           `$o$$$$\"\" o$      \"o$/|\"$o'\n");
 printw("                              `$o\"$\"$ $ \"       `\"$\"$o$\n");
 printw("                               \"$$\"$$ \"oo         ,$\"\"$ \n");
 printw("                               $\"$o$$\"\"o\"          ,o$\"$\n");
 printw("                               $$\"$$\"$ \"o           `,\",\n");
 printw("                     ,oo$oo$$$$$$\"$o$$$ \"\"o           \n");
 printw("                  ,o$$\"o\"o$o$$o$$$\"$o$$oo\"oo\n");
 printw("                ,$\"oo\"$$$$o$$$$\"$$$o\"o$o\"o\"$o o\n");
 printw("               ,$$$\"\"$$o$,      `$$$$\"$$$o\"\"$o $o \n");
 printw("               $o$o$\"$,          `$o$\"$o$o\"$$o$ $$o  \n");
 printw("              $$$o\"o$$           ,$$$$o$$o\"$\"$$ $o$$oo      ,\n");
 printw("              \"$o$$$ $`.        ,\"$$o$\"o$\"\"$$$$ `\"$o$$oo    `o\n");
 printw("             `$o$o$\"$o$o`.  ,.$$\"$o$$\"$$\"o$$$$   `$o$$ooo    $$ooooooo\n");
 printw("               `$o$\"$o\"$\"$$\"$$\"$\"$$o$$o\"$$o\"        `\"$o$o            `\"o\n");
 printw("                   `$$\"$\"$o$$o$\"$$\"$ $$$  $ \"           `$\"$o            `o\n");
 printw("                      `$$\"o$o\"$o\"$o$ \"  o $$$o            `$$\"o          ,$\n");
 printw("                         (\" \"\"$\"\"\"     o\"\" \"o$o             `$$ooo     ,o$$\n");
 printw("                             $$\"\"\"o   (   \"$o$$$\"o            `$o$$$o$\"$'\n");
printw("                                   ) ) )           )  ) )            ` \"'\n");
//ALL ascii art created by darren rion hall and Christopher Johnson!!! on their free website
//listed below... I did not!! create this art
//link is http://chris.com/ascii/index.php?art=creatures/dragons

}
void kitten()
{
	 attron(COLOR_PAIR(1));
	 attron(A_BOLD);
	 printw("Princess Purrr-tricia: ");
	  printw("    .       .         \n");
      printw("     \\`-\"'\"-'/            \n");
      printw("      } 6 6 {       MEOW \n");
      printw("     =.  Y  ,=       MEOWWW  \n");
      printw("   (\"\"-'***`-\"\")      MMEE--OWWW BABY \n");
      printw("    `-/     \\-'            \n");
      printw("     (  )-(  )==='        \n");
      printw("      \"\"   \"\"              \n");

}

void hero()
{
	   attron(COLOR_PAIR(4));
	   printw("\n");
	   printw("            |'.             ,\n");
       printw("            |  '-._        / )\n");
       printw("          .'  .._  ',     /_'-,\n");
       printw("         '   /  _'.'_\\   /._)')\n");
       printw("        :   /  '_' '_'  /  _.'\n");
       printw("        |E |   |Q| |Q| /   /\n");
       printw("       .'  _\\  '-' '-'    /\n");
       printw("     .'--.(S     ,__` )  /\n");
       printw("           '-.     _.'  /\n");
       printw("         __.--'----(   /\n");
       printw("     _.-'     :   __\\ /\n");
       printw("    (      __.' :'  :Y\n");
       printw("     '.   '._,  :   :|\n");
       printw("       '.     ) :.__:|\n");
       printw("         \\    \\______/\n");
       printw("          '._L/______]\n");
       printw("           /_        /\n");
       printw("          /  '-.__.-')\n");
       printw("         :      /   /\n");
       printw("         :     /   /\n");
       printw("       ,/_____/----;\n");
       printw("       '._____)----'\n");
       printw("       /     /   /\n");
       printw("      /     /   /\n");
       printw("    .'     /    \\\n");
       printw("   (______(-.____)\n");

}

void castle()
{
	attron(COLOR_PAIR(4));

printw("	                             o    \n");
printw("                             .-\"\"|     \n");
printw("                             |-\"\"|\n");
printw("                                 |   ._--+. \n");
printw("                                .|-\"\"      '.\n");
printw("                               +:'           '.\n");
printw("                               | '.        _.-'|\n");
printw("                               |   +    .-\"   J\n");
printw("            _.+        .....'.'|    '.-\"      |\n");
printw("       _.-\"\"   '.   ..'88888888|     +       J''..\n");
printw("    +:\"          '.'88888888888;-+.  |    _+.|8888:\n");
printw("    | \\         _.-+888888888_.\" _.F F +:'   '.8888'....\n");
printw("     L \\   _.-\"\"   |8888_.-\"  _.\" J J J  '.    +88888888:\n");
printw("     |  '+\"        |_.-\"  _.-\"    | | |    +    '.888888'._''.\n");
printw("   .'8L  L         J  _.-\"        | | |     '.    '.88_.-\"    '.\n");
printw("  :888|  |         J-\"            F F F       '.  _.-\"          '.\n");
printw(" :88888L  L     _+  L            J J J          '|.               ';\n");
printw(":888888J  |  +-\"  \\ L          _.+.|.+.          F '.          _.-\" F\n");
printw(":8888888|  L L\\    \\|      _.-\"    '   '.       J    '.     .-\"    |\n");
printw(":8888888.L | | \\    ', _.-\"              '.     |      \"..-\"      J'.\n");
printw(":888888: |  L L '.    \\     _.-+.          '.   :+-.     |        F88'.\n");
printw(":888888:  L | |   \\    ;.-\"\"     '.          :-\"    \":+ J        |88888:\n");
printw(":888888:  |  L L   +:\"\"            '.    _.-\"     .-\" | |       J:888888:\n");
printw(":888888:   L | |   J \\               '.-'     _.-'   J J        F :888888:\n");
printw(" :88888:    \\ L L   L \\             _.-+  _.-'       | |       |   :888888:\n");
printw(" :888888:    \\| |   |  '.       _.-\"   |-\"          J J       J     :888888:\n");
printw(" :888888'.    +'\\   J    \\  _.-\"       F    ,-T\"\\  | |     .-'      :888888:\n");
printw("  :888888 '.     \\   L    +\"          J    /  | J  J J  .-'        .'888888:\n");
printw("   :8888888 :     \\  |    |           |    F  '.|.-'+|-'         .' 8888888:\n");
printw("    :8888888 :     \\ J    |           F   J     '...           .' 888888888:\n");
printw("     :8888888 :     \\ L   |          J    |      \\88'.''.''''.' 8888888888:\n");
printw("      :8888888 :     \\|   |          |  .-'\\      \\8888888888888888888888:\n");
printw("       :8888888 '.    J   |          F-'  .'\\      \\8888888888888888888.'\n");
printw("        :88888888 :    L  |         J     : 8\\      \\8888888888888888.'\n");
printw("         :88888888 :   |  |        .+  ...' 88\\      \\8888888888.''.'\n");
printw("          :88888888 :  J  |     .-'  .'    8888\\      \\'.'''.'.'\n");
printw("           :88888888 :  \\ |  .-'   .' 888888888.\\    _-'\n");
printw("           :888888888 :  \\|-'     .' 888888888.' \\_-\"\n");
printw("            '.88888888'..         : 8888888.'\n");
printw("              :88888888  ''''.''.' 88888888:  hs\n");
printw("              :8888888888888888888888888888:\n");
printw("               :88888888888888888888888888:\n");
printw("                :888888888888888888888888:\n");
printw("                 ''.8888888888888...'.'''\n");
printw("                    '''''......''\n");


}

void princess()
{

printw("                                      /|                                      \n ");
printw("                                      ||                                             \n ");
printw("                                      ||\n ");
printw("                                      ||\n ");
printw("                                      ||\n ");
printw("       .--._                          ||\n ");
printw("  _.-\"\" (   /                         ||                        .-.\n ");
printw(" (_.-(   `. \\                         ||                        )  `-._\n ");
printw("(  (   __.   \\                        ||                   __.-' ` .)._)\n ");
printw("(  (  _.-'  `.`-._                    ||               _.-\"    )  )     )\n ");
printw(" (  (   (         `.                  ||            .-'   .'  `.   )` - .)\n ");
printw(" ((  .-'   .-'  `.  `-.               ||          .'   .'     )  ) - . )  )\n ");
printw("  (  ( .-'       `-.   \\            __/\\__       / .'     `-.   `. )     )\n ");
printw("   `. ( _.-'         `. `.          _(  |       :     `-.       )   `-.  )\n ");
printw("    (   (   .'.-'         `.       /  ) /     .'  .'`.     `-.     ) _.-'\n ");
printw("    (.-' (      .-'    `.   `.    | ,'| |   .' .'                )  )\n ");
printw("     (     (     .'        `. `.,' /  |  \\.'  : `-._`-.  `-.  `.)`.)\n ");
printw("      `-._  (       .'  .     ,'  /    \\  \\ .'               )`.  )\n ");
printw("          (      (       .'  /   ,-\"\"-./\\  \\ `.  `-.  )   )`-._.-'\n ");
printw("           `-.      .'       |  / __.. `|  /               .-'\n ");
printw("              \\   .'     .'  | | /_  _\\/  / `-. `.    ) .-'\n ");
printw("               `-._.'        | \\ )    (|  |            /\n ");
printw("                   `-._   ,; |.' \\    /   |   ` .  _.-'\n ");
printw("                       \"\"-._ /   )`--'|   |  `._.-'\n ");
printw("                            /   /`-..-'  /_..-'\n ");
printw("                           ;  _/        |\n ");
printw("                            ,'          `.\n ");
printw("                            |            |\n ");
printw("                            `.__.-' '.__.'\n ");
printw("                               `.       |\n ");
printw("                                 \\       `.\n ");
printw("                                  |         .\n ");
printw("                                  |          \\\n ");
printw("                                  |           .\n ");
printw("                                 ,'           |\n ");
printw("                                .'            |\n ");
printw("                               ,'             |\n ");
printw("                              .'             /\n ");
printw("                              |              /\n ");
printw("                              |             |\n ");
printw("                              |             /\n ");
printw("                             |             |\n ");
printw("                             |             |\n ");
printw("                            /               \\\n ");
printw("                           /    /            |\n ");
printw("                          /           .:     |\n ");
printw("                         /    .      .:      |\n ");
printw("                        /    .:      .:     ,'\n ");
printw("                      ,'    .:      .::__.-|\n ");
printw("                     -..__   : __,,..-' \\  |\n ");
printw("                       /  |''''         /  (\n ");
printw("                     .'  ,'             \\_  `.\n ");
printw("                     `..'                 `.__;\n ");

}

