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

void PrettyTerminal::empty(uint8_t count)
{
    for (uint8_t i = 0; i < count; i++)
    {
        Serial.println();
    }
}

void PrettyTerminal::printKeyValue(const char *key, uint8_t keyWidth, const char *value)
{
    printKeyValue(key, keyWidth, value, true);
}

void PrettyTerminal::printKeyValue(const char *key, uint8_t keyWidth, const char *value, bool newLine)
{
    uint8_t keyLen = strlen(key);
    if ((keyLen + 1) > keyWidth)
    {
        keyWidth = keyLen + 1;
    }

    Serial.print(" ");
    Serial.print(key);

    uint8_t spacing = keyWidth - keyLen;
    printRepeat(' ', spacing);
    Serial.print(": ");
    if (newLine)
    {
        Serial.println(value);
    }
    else
    {
        Serial.print(value);
    }
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
    printCenteredDecorated(value, ' ', len);
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

void PrettyTerminal::printRight(const char *value)
{
    printRight(value, 0);
}

void PrettyTerminal::printRight(const char *value, uint8_t currentPos)
{
    uint8_t empty = _width - currentPos - strlen(value);
    printRepeat(' ', empty);
    Serial.println(value);
}

void PrettyTerminal::printHorizontalLine(char c)
{
    printlnRepeat(c, _width);
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