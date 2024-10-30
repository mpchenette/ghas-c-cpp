#ifndef RECORD_H
#define RECORD_H

class Record {
public:
    Record(int value);
    int getValue() const;

private:
    int value;
};

#endif // RECORD_H