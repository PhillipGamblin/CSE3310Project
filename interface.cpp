#include "interface.hpp"
#include <cstdio>
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstring>

Interface::Interface() {
    // Seed so we get a random sequence of values
    srand ( time(NULL) );


    title.push_back("       _         __     __      ________        _________    ________         ___          __     __              _           _______________");
    title.push_back("     _____       __     __      __      __      ________     __     __      __   __        __     __             _ _           _____________ ");
    title.push_back("   ___   ___     __     __      __       __     __           __     __    ___     ___      __     __            _ _ _               ___      ");
    title.push_back("   ___           __     __      __       __     __           __    __     ___              __     __           __   __              ___      ");
    title.push_back("     ___         __     __      __      __      _____        __  _        ___              _________          __ ___ __             ___      ");
    title.push_back("       ___       __     __      __   __         _____        __  __       ___              _________         __ _____ __            ___      ");
    title.push_back("         ___     __     __      __   __         __           __   __      ___              __     __        __         __           ___      ");
    title.push_back("   ___   ___     __     __      __   __         __           __    __     ___     ___      __     __       __           __          ___      ");
    title.push_back("     _____        __   __       __   __         _______      __     __      __   __        __     __      __             __         ___      ");
    title.push_back("       _            ___         _______         _________    __      __       ___          __     __     ___             ___        ___      ");
    title.push_back("                                                                                                                                             ");
    title.push_back("                                                                                                                                             ");
    title.push_back("                               By: Phillip Gamblin, Gaurav Ganthapodi, Misbah Gilani, Endrit Memeti, Jorgi Rajan                             ");

    login.push_back("[   Enter   ]");
    login.push_back("[   Exit   ]");

    choices.push_back("Lobby");
    choices.push_back("Chatroom 1");
    choices.push_back("Chatroom 2");
    choices.push_back("Chatroom 3");
    choices.push_back("Chatroom 4");
    choices.push_back("Log Out");

    all_messages.push_back("<USER 1>: Hey guys!");
    all_messages.push_back("<USER 2>: Dude why did you invite me?");
    all_messages.push_back("<USER 2>: Anyways, yo whats up USER 3?");
    all_messages.push_back("<USER 3>: We bullying USER 1 now? lolol but im good bro, wbu?");
    all_messages.push_back("<USER 2>: Just trying to finish this ncurses thing...");
    all_messages.push_back("<USER 1>: Ik it's off topic but Lebron is the goat");
    all_messages.push_back("<USER 3>: Shut the fuck up.");
    all_messages.push_back("<USER 2>: Yeah dude just quit trying.");

    options.push_back("Join");
    options.push_back("Create");
    options.push_back("Leave");

    n_title = title.size();
    n_choices = choices.size(); //sizeof(choices) / sizeof(choices[0]);
    n_messages = all_messages.size(); //sizeof(all_messages) / sizeof(all_messages[0]);
    n_options = options.size(); //sizeof(options) / sizeof(options[0]);
    n_login = login.size(); //sizeof(login) / sizeof(login[0]);
}

void Interface::print_highlight(WINDOW *inp_win, int highlight, int cur_y, int cur_x) {
    int i = 0;

    for(; i < n_login; i++)
	{
		char cstr[login.at(i).size() + 1];
		strcpy(cstr, login.at(i).c_str());
		if(highlight == i + 1) { // High light the present choice
		    wattron(inp_win, A_REVERSE);
		    mvwprintw(inp_win,cur_y, cur_x, "%s", cstr);
	            wattroff(inp_win, A_REVERSE);
		}
		else
		    mvwprintw(inp_win, cur_y, cur_x, "%s", cstr);
		cur_x+=45;
	}
	wrefresh(inp_win);
}

void Interface::print_title(WINDOW*start, int index, char* part) {
    int num_color = ( rand() % 7 ) + 1;
    int j = 0;

    for(; j < strlen(part); j++ ) {
        wattron(start, COLOR_PAIR(num_color));
        mvwprintw( start, index, 1, part );
        wattroff(start, COLOR_PAIR(num_color));
        doupdate();
        usleep( 400 );
        wrefresh( start );
    }
}

int Interface::login_Page(WINDOW*start, WINDOW*input) {
    int org_x, org_y, new_x, new_y;
    int highlight = 1;
    int choice = 0;
    int c;

    char username[9];
    char ip_addr[11];

    initscr();
    clear();
    start_color();
    //noecho();
    cbreak();	// Line buffering disabled. pass on everything
    curs_set(0);

    // Defines all the colors used for the text
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);

    getmaxyx(stdscr,org_y,org_x);

    start = newwin( org_y, org_x, 5, 30 );
    input = newwin( org_y, org_x, 20, 30 );
    keypad(input, TRUE);

    while(1) {
        getmaxyx(stdscr, new_y, new_x);

        if (new_y != org_y || new_x != org_x) {
            org_x = new_x;
            org_y = new_y;

            wresize( start, new_y-57, new_x );
            wresize( input, new_y, new_x );
            mvwin( input, new_y-57, 30 );

            wclear(start);
            wclear(input);
            wclear(stdscr);
        }

	int num_color;
        int i = 0;
        for(;i<title.size();i++)
	{
	    char cstr[title.at(i).size() + 1];
	    strcpy(cstr, title.at(i).c_str());
            print_title( start, i, cstr );
	}

        // The user can see the cursor again
        curs_set(1);

        mvwprintw( input, new_y-52, 58, "  Username:" );
        mvwgetnstr( input, new_y-52, 71, username, 8 );
        mvwprintw( input, new_y-47, 58, "IP Address:" );
        mvwgetnstr( input, new_y-47, 71, ip_addr, 10 );
	char cstr[login.at(0).size() + 1];
	strcpy(cstr, login.at(0).c_str());
        mvwprintw( input, new_y-40, 41, cstr );
	char cstr1[login.at(1).size() + 1];
	strcpy(cstr1, login.at(1).c_str());
        mvwprintw( input, new_y-40, 86, cstr1 );

        // Cursor is now invisible
        curs_set(0);

        while(1) {
            c = wgetch(input);
	    switch(c){
                case KEY_LEFT:
		    if(highlight == 1)
		        highlight = n_login;
		    else
		        --highlight;
		    break;
		case KEY_RIGHT:
		    if(highlight == n_login)
			highlight = 1;
		    else
			++highlight;
		    break;
                case 10:
                    break;
                default:
		    mvwprintw(input, new_y-30, 1 , "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
		    wrefresh(input);
		    break;
            }
            if(c == 10)
            {
                int next_step;
                if( highlight == 1 )
                    next_step = 1;
                else if( highlight == 2 )
                    next_step = 0;

                delwin(start);
                delwin(input);

                usleep(750);

                clear();
                refresh();
                endwin();
                return next_step;
            }

            else
                print_highlight(input, highlight, new_y-40, 41);
        }

        wrefresh(start);
        wrefresh(input);
        refresh();
    }
}

void Interface::print_option_menu(WINDOW *new_win ) {
    return;
}

void Interface::chatroom_Page( WINDOW*log, WINDOW*message, WINDOW*recc, WINDOW*rooms, WINDOW*chat_ops, WINDOW*curr) {
    int x,y;

    //noecho();
    cbreak();	// Line buffering disabled. pass on everything
    curs_set(0);

    getmaxyx(stdscr,y,x);

    curr = newwin( 3, 140, 0, 46 );
    log = newwin( 40, 140, 3, 46 );
    chat_ops = newwin( 10, 30, 3, 15 );
    rooms = newwin( 30, 30, 13, 15 );
    recc = newwin( 3, 140, 43, 46 );
    message = newwin( 10, 140, 46, 46 );

    box(curr, 0, 0);
    box(log, 0, 0);
    box(chat_ops, 0, 0);
    box(rooms, 0, 0);
    box(recc, 0, 0);
    box(message, 0, 0);

    char cstr[choices.at(0).size() + 1];
    strcpy(cstr, choices.at(0).c_str());
    mvwprintw(curr, 0, 70, "%s", cstr);
    int i =0;
    for(;i<n_messages;i++) {
        char cstr1[all_messages.at(i).size() + 1];
        strcpy(cstr1, all_messages.at(i).c_str());
        mvwprintw(log, (i+1), 2, "%s", cstr1 );
    }

    wrefresh(curr);
    wrefresh(rooms);
    wrefresh(log);
    wrefresh(chat_ops);
    wrefresh(recc);
    wrefresh(message);

    //sleep(10);
    getch();
    clrtoeol();
    refresh();
    endwin();

}
