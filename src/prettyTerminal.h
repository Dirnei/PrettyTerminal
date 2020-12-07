#ifndef PRETTY_TERMINAL
#define PRETTY_TERMINAL

#include <stdint.h>
#include <stddef.h>

class PrettyTerminal
{
  public:
    PrettyTerminal(uint8_t width, uint8_t indentWidth);

    void printHorizontalLineDouble(void);
    void printHorizontalLineUnder(void);
    void printHorizontalLineMiddle(void);
    void printHorizontalLineBold(void);

    void indent(uint8_t amount, const char *value);
    void empty();

    void printHeader(const char *title);
    void printHeaderSmall(const char *title);

    void printCentered(const char *value);
    void printCentered(const char *value, int len);

    void printCenteredDecorated(const char *value, char decorator);
    void printCenteredDecorated(const char *value, char decorator, int len);

    void printRight(const char *value);
    void printRight(const char *value, uint8_t currentPos);
    void printList(uint8_t ident, size_t order, const char* value);

  protected:
    char _cBold;
    char _cUnder;
    char _cMiddle;
    char _cDouble;

    uint8_t _width;
    uint8_t _indentWidth;

    void printRepeat(char c, uint8_t len);
    void printlnRepeat(char c, uint8_t len);
};

#endif