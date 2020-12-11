# PrettyTerminal

A small Arduino library for pretty terminal prints. Because everyone likes pretty terminals :)

## How to use it

Create a new instance for the prettyTerminal and define the `width` and the `indent`.

```cpp
#include <prettyTerminal.h>

PrettyTerminal pTerm(100,2);
```

After that you have the following methods available:

```cpp
    void printHorizontalLine(char c);
    void printHorizontalLineDouble(void);
    void printHorizontalLineUnder(void);
    void printHorizontalLineMiddle(void);
    void printHorizontalLineBold(void);

    void indent(uint8_t amount, const char *value);
    void empty();
    void empty(uint8_t count);

    void printKeyValue(const char *key, uint8_t keyWidth, const char *value);
    void printKeyValue(const char *key, uint8_t keyWidth, const char *value, bool newLine);

    void printHeader(const char *title);
    void printHeaderSmall(const char *title);

    void printCentered(const char *value);
    void printCentered(const char *value, int len);

    void printCenteredDecorated(const char *value, char decorator);
    void printCenteredDecorated(const char *value, char decorator, int len);

    void printRight(const char *value);
    void printRight(const char *value, uint8_t currentPos);
    void printList(uint8_t ident, size_t order, const char* value);
```

## Horizonal lines

It repeatedly prints a character. Amount is defined in the constructor as `width`. 
```cpp
pTerm.printHorionalLine('+')
// Output => +++++++++++++++++++++++++++++++++++++++++++++++++

pTerm.printHorionalLineDoube()
// Output => =================================================

pTerm.printHorionalLineMiddle()
// Output => -------------------------------------------------

pTerm.printHorionalLineBold()
// Output => #################################################

pTerm.printHorionalLineUnder()
// Output => _________________________________________________
```

## Indent

It prints the value indented. The ident width is specified in the constructor as `indentWidth`.
```cpp

pTerm.indent(1, "This is indented 1 time");
pTerm.indent(2, "This is indented 2 times");
pTerm.indent(2, "This is indented 3 times");
pTerm.indent(2, "This is indented 4 times");
// Output =>   This is indented 1 time
// Output =>     This is indented 2 times
// Output =>       This is indented 3 times
// Output =>         This is indented 4 times
```

## Empty lines

Prints empty lines. Same as `Serial.println()` but in addition you can specify the amount of empty lines.

```cpp
pTerm.empty(10); // will print 10 empty lines
```

## Key Value

```cpp
pTerm.printKeyValue("Key 1", 11, "This is the first value");
pTerm.printKeyValue("Key 2", 11, "This is the second value");
pTerm.printKeyValue("Longer key", 11, "This is the third value");

// Output => Key 1      : This is the first value
// Output => Key 1      : This is the second value
// Output => Longer key : This is the third value
```

## Header

```cpp
pTerm.printHeader("This is the header");

// Output => ===================================================
// Output =>                  This is the header
// Output => ===================================================
```

## Centered


```cpp
pTerm.printCentered("#");
pTerm.printCentered("###");
pTerm.printCentered("#####");
pTerm.printCentered("#######");
pTerm.printCentered("#########");
pTerm.printCentered("###########");
pTerm.printCentered("#############");
pTerm.printCentered("##");
pTerm.printCentered("##");
pTerm.empty();
pTerm.printCenteredDecorated(" Its a Tree! ", '_');

// Output =>                  #
// Output =>                 ###
// Output =>                #####
// Output =>               #######
// Output =>              #########
// Output =>             ###########
// Output =>            #############
// Output =>                 ##
// Output =>                 ##
// Output =>
// Output => ___________ Its a Tree! ___________
```

## Right

```cpp
pTerm.printRight("[RIGHT]")
Serial.print("You can also write on the left and the right")
pTerm.printRight("[RIGHT]", 44);

// Output =>                                                      [RIGHT]
// Output => You can also write on the left and the right         [RIGHT]
```