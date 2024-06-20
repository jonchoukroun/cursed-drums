#include "cursed_engine.h"
#include "color_consts.h"
#include <iostream>
#include <ncurses.h>

CursedEngine::CursedEngine()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    raw();
    curs_set(FALSE);

    m_window = newwin(m_screenHeight, m_screenWidth, 0, 0);
}

CursedEngine::~CursedEngine()
{
    cleanup();
}

bool CursedEngine::initialize()
{
    if (has_colors() == FALSE) {
        std::cout << "Warning! Terminal does not support colors\n";
        endwin();
        return false;
    }

    return true;
}

void CursedEngine::print(std::string s, TypeStyle t)
{
    if (t == TypeStyle::Title) {
        attron(A_UNDERLINE);
        printw(s.c_str());
        attroff(A_UNDERLINE);
    } else {
        printw(s.c_str());
    }
    refresh();
}

void CursedEngine::wait()
{
    getch();
}

void CursedEngine::cleanup()
{
    delwin(m_window);
    m_window = nullptr;
    endwin();
}
