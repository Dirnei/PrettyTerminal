#include <Arduino.h>
#include <prettyTerminal.h>

PrettyTerminal pTerm(100,2);

void setup()
{
    Serial.begin(115200);

    pTerm.empty();
    pTerm.empty();
    pTerm.printHorizontalLineMiddle();
    pTerm.indent(1, "Hello World");
    pTerm.indent(2, "Hello World");
    pTerm.indent(3, "Hello World");
    pTerm.indent(2, "Hello World");
    pTerm.indent(1, "Hello World");
    pTerm.printHorizontalLineMiddle();
    pTerm.empty();
    pTerm.empty();
    pTerm.printHeader("LEBERKAS");
    pTerm.printList(0, 1, "Menu");
    pTerm.printList(1, 1, "Open");
    pTerm.printList(1, 2, "Close");
    pTerm.printList(0, 1, "Language");
    pTerm.printList(1, 1, "German");
    pTerm.printList(1, 2, "Bavarian");
    pTerm.printHorizontalLineMiddle();
    pTerm.empty();
    pTerm.empty();
    pTerm.printHeaderSmall("Key Value list");
    pTerm.printKeyValue("Entry1", 15, "This is the value");
    pTerm.printKeyValue("Entry2", 15, "This is another value");
    pTerm.printKeyValue("ThisIsAPrettyLongKey", 15, "This is another value");
}

void loop()
{
    // put your main code here, to run repeatedly:
}