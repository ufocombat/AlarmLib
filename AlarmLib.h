#ifndef _AlarmLib_H_
#define _AlarmLib_H_

#include <Arduino.h>
#include <RTClib.h>

String DayOfWeek(DateTime date);
String Norm2Str(int value);

String Date2Str(DateTime date);
String Date2StrWeek(DateTime date);
String Date2StrFull(DateTime date);

uint16_t Date_minutes(DateTime date);
uint16_t Date_seconds(DateTime date);

String Time2Str(DateTime _time);
String Time2StrHHMM(DateTime _time,boolean colon);

String TimeSpan2hMM(TimeSpan span);

String Min2HHMM(uint16_t minutes);
String Min2hMM(uint16_t minutes);

class Alarm {
public:
    Alarm (uint16_t minutes=0);
    Alarm (String  mm_hh);
    uint8_t hour() const        { return hh; }
    uint8_t minute() const      { return mm; }
    uint16_t minutes() const      { return _minutes; }
    String ToStr();

protected:
    uint16_t _minutes;
    uint8_t hh, mm;
};

#endif // _Alarm_H_
