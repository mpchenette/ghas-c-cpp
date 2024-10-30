#include "Record.h"

Record::Record(int value) : value(value) {}

int Record::getValue() const {
    return value;
}