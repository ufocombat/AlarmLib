#ifndef _AlarmLib_H_
#define _AlarmLib_H_

#include <Arduino.h>
#include <RTClib.h>

String DayOfWeek(DateTime date);
String Norm2Str(int value);
String Date2Str(DateTime date);
String Time2Str(DateTime _time);

class Alarm {
public:
    Alarm (uint16_t minutes=0);
    uint8_t hour() const        { return hh; }
    uint8_t minute() const      { return mm; }
    uint16_t minutes() const      { return _minutes; }
    String ToStr();

protected:
    uint16_t _minutes;
    uint8_t hh, mm;
};

#endif // _Alarm_H_
