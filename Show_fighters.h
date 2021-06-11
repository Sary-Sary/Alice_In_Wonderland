#pragma once
#include "rang.hpp"

/*

****************;++;****************

SPRITES WERE CREATED BY: 
Joan Stark (https://www.asciiart.eu/books/alice-in-wonderland) - CHESHIRE CAT
Lorrie (https://www.asciiart.eu/clothing-and-accessories/crowns) - QUEEN OF HEARTS
Sebastian Stoecker (https://www.asciiart.eu/books/alice-in-wonderland) - MAD HATTER
Blazej Kozlowski (Blazej Kozlowski) - WHITE RABBIT

****************;++;****************

*/

class Show_fighters
{
public:

	void cheshire_cat() {

		std::cout << rang::fg::black << rang::bg::black <<
			"	   " << rang::bg::blue << ".'\\   /`.\n" << rang::bg::black <<
			"         " << rang::bg::blue << ".'.-.`-'.-.`.\n" << rang::bg::black <<
			"    " << rang::bg::blue << "..._:   .-. .-.   :_...\n" << rang::bg::black <<
			"  " << rang::bg::blue << ".'    '-.(o ) (o ).-'    `.\n" << rang::bg::black <<
			" " << rang::bg::blue << ":  _    _ _`~(_)~`_ _    _  :\n" << rang::bg::black
			<< rang::bg::blue << ":  /:   ' .-=_   _=-. `   ;\\  :\n" << rang::bg::black <<
			" " << rang::bg::blue << ":   :|-.._  '     `  _..-|:   :\n" << rang::bg::black <<
			" " << rang::bg::blue << ":   `:| |`:-:-.-:-:'| |:'   :\n" << rang::bg::black <<
			"  " << rang::bg::blue << "`.   `.| | | | | | |.'   .'\n" << rang::bg::black <<
			"    " << rang::bg::blue << "`.   `-:_| | |_:-'   .'\n" << rang::bg::black <<
			"      " << rang::bg::blue << "`-._   ````    _.-'\n" << rang::bg::black <<
			"          " << rang::bg::blue << "``-------''\n" << rang::bg::black;

		return;
	}

	void mad_hatter() {

		std::cout << rang::fg::black << rang::bg::black <<

			"                               " << rang::bg::green << ",.--""-._\n" << rang::bg::black <<
			"                            " << rang::bg::green << "__/         `.\n" << rang::bg::black <<
			"                       " << rang::bg::green << "_,**"   "*-.       `.\n" << rang::bg::black <<
			"                     " << rang::bg::green << ",'            `.       \\\n" << rang::bg::black <<
			"                    " << rang::bg::green << ";    _,.---._    \  ,'\\  \\\n" << rang::bg::black <<
			"                   " << rang::bg::green << ":   ,'   ,-.. `.   \'   \\ :\n" << rang::bg::black <<
			"                   " << rang::bg::green << "|  ;_\\  (___)`  `-..__  : |\n" << rang::bg::black <<
			"                   " << rang::bg::green << ";-'`*''  `*'    `--._ ` | ;\n" << rang::bg::black <<
			"                  " << rang::bg::green << "/,-'/  -.        `---.`  |\n" << rang::bg::black <<
			"                  " << rang::bg::green << "/_,'`--='.       `-.._,-' _\n" << rang::bg::black <<
			"                   " << rang::bg::green << "(/\\\\,--. \\    ___-.`:   //'___\n" << rang::bg::black <<
			"                      " << rang::bg::green << "/\\'''\\ '  |   |-`|  ( -__,'\n" << rang::bg::black <<
			"                     " << rang::bg::green << "'. `--'    ;   ;  ; ;/_/\n" << rang::bg::black <<
			"                       " << rang::bg::green << "`. `.__,/   /_,' /`.~;\n" << rang::bg::black <<
			"                       " << rang::bg::green << "_.-._|_/_,'.____/   /\n" << rang::bg::black <<
			"                  " << rang::bg::green << "..--' /  =/  \\=  \\      /\n" << rang::bg::black <<
			"                 " << rang::bg::green << "/  ;._.\\_.-`--'-._/ ____/\n" << rang::bg::black <<
			"                 " << rang::bg::green << "\ /   /._/|.\     .\n" << rang::bg::black <<
			"                  " << rang::bg::green << "`*--'._ '-.:     :\n" << rang::bg::black <<
			"                       " << rang::bg::green << ":/'.A` \\    |\n" << rang::bg::black <<
			"                       " << rang::bg::green << "|   |.  `.  :\n" << rang::bg::black <<
			"                       " << rang::bg::green << ";   |.    `. \\\n" << rang::bg::black;

		return;

	}

	void queen_of_heart() {

		std::cout << rang::fg::black << rang::bg::black <<
			"	     " << rang::bg::red << "*"
			"     " << rang::bg::red << "* * | * *" << rang::bg::black <<
			"      " << rang::bg::red << "\ \|/ /" << rang::bg::black <<
			"      " << rang::bg::red << "(<><>)" << rang::bg::black <<
			"      " << rang::bg::red << "=======" << rang::bg::black <<
			"      " << rang::bg::red << "**   **" << rang::bg::black <<
			"     " << rang::bg::red << "*   *   *" << rang::bg::black <<
			"      " << rang::bg::red << "*     *" << rang::bg::black <<
			"        " << rang::bg::red << "* *" << rang::bg::black <<
			"         " << rang::bg::red << "*" << rang::bg::black;

		return;

	}

	void white_rabbit() {

		std::cout << rang::fg::black << rang::bg::black <<
			"	                 " << rang::bg::gray << "/\\    .-' /" << rang::bg::black <<
			"                    " << rang::bg::gray << "/  ; .'  .'" << rang::bg::black <<
			"                   " << rang::bg::gray << ":   :/  .'" << rang::bg::black <<
			"                    " << rang::bg::gray << "\\  ;-.'" << rang::bg::black <<
			"       " << rang::bg::gray << ".--\"\"\"\"--..__/  `." << rang::bg::black <<
			"     " << rang::bg::gray << ".'           .'    `o  \\" << rang::bg::black <<
			"    " << rang::bg::gray << "/                    `   ;" << rang::bg::black <<
			"   " << rang::bg::gray << ":                  \      :" << rang::bg::black <<
			" " << rang::bg::gray << ".-;        -.         `.__.-'" << rang::bg::black <<
			"" << rang::bg::gray << ":  ;          \     ,   ;" << rang::bg::black <<
			"" << rang::bg::gray << "'._:           ;   :   (" << rang::bg::black <<
			"    " << rang::bg::gray << "\\/  .__    ;    \   `-." << rang::bg::black <<
			"     " << rang::bg::gray << ";     '-,/_..--'`-..__)" << rang::bg::black <<
			"     " << rang::bg::gray << "'\"\"--.._:" << rang::bg::black;

		return;

	}

};

