#include <ncurses.h>
#include <string>

enum TypeStyle {
    Body,
    Title
};

class CursedEngine {
public:
    CursedEngine();
    ~CursedEngine();

    bool initialize();
    void print(std::string, TypeStyle);
    void wait();

private:
    // TODO: unique_ptr
    WINDOW* m_window { nullptr };

    int m_screenWidth { COLS };
    int m_screenHeight { LINES };

    void cleanup();
};
