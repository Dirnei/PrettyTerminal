#include <HardwareSerial.h>
#include "prettyTerminal.h"

PrettyTerminal::PrettyTerminal(uint8_t width, uint8_t indentWidth)
{
    _cBold = '#';
    _cDouble = '=';
    _cMiddle = '-';
    _cUnder = '_';

    _width = width;
    _indentWidth = indentWidth;
}

void PrettyTerminal::printlnRepeat(char c, uint8_t len)
{
    char buf[len + 1];
    for (uint8_t i = 0; i < len; i++)
    {
        buf[i] = c;
    }

    buf[len] = 0x0;
    Serial.println(buf);
}

void PrettyTerminal::printRepeat(char c, uint8_t len)
{
    char buf[len + 1];
    for (uint8_t i = 0; i < len; i++)
    {
        buf[i] = c;
    }

    buf[len] = 0x0;
    Serial.print(buf);
}

void PrettyTerminal::indent(uint8_t amount, const char *message)
{
    if (amount > 0)
    {
        printRepeat(' ', amount * _indentWidth);
    }

    Serial.println(message);
}

void PrettyTerminal::empty()
{
    Serial.println();
}

void PrettyTerminal::printHeader(const char *title)
{
    printHorizontalLineDouble();
    printCentered(title);
    printHorizontalLineDouble();
    empty();
}

void PrettyTerminal::printHeaderSmall(const char *title)
{
    printCenteredDecorated(title, '-');
    empty();
}

void PrettyTerminal::printCentered(const char *value)
{
    printCenteredDecorated(value, ' ', strlen(value));
}

void PrettyTerminal::printCentered(const char *value, int len)
{
    printCenteredDecorated(value, ' ', strlen(value));
}

void PrettyTerminal::printCenteredDecorated(const char *value, char decorator)
{
    printCenteredDecorated(value, decorator, strlen(value));
}

void PrettyTerminal::printCenteredDecorated(const char *value, char decorator, int len)
{
    if (len < _width - 1)
    {
        len = (_width - len) / 2;
        printRepeat(decorator, len);
    }

    if (decorator != ' ')
    {
        Serial.print(value);
        printRepeat(decorator, len);
    }
    else
    {
        Serial.println(value);
    }
}

void PrettyTerminal::printList(uint8_t indent, size_t order, const char *value)
{
    size_t len = strlen(value) + 16;
    char buf[len];
    snprintf(buf, len - 1, "%d. %s", order, value);
    this->indent(indent, buf);
}

void PrettyTerminal::printHorizontalLineDouble()
{
    printlnRepeat(_cDouble, _width);
}
void PrettyTerminal::printHorizontalLineMiddle()
{
    printlnRepeat(_cMiddle, _width);
}
void PrettyTerminal::printHorizontalLineUnder()
{
    printlnRepeat(_cUnder, _width);
}
void PrettyTerminal::printHorizontalLineBold()
{
    printlnRepeat(_cBold, _width);
}