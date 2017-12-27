#include <Arduino.h>
#include <AlarmLib.h>

const char DOW[][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};

String DayOfWeek(DateTime date)
{
  return DOW[date.dayOfTheWeek()];
}

String Norm2Str(int value)
{
  String work = (String)value;
  while (work.length()<2) work ="0"+work;
  return work;
}

String Date2Str(DateTime date)
{
  return (String)date.year()+"."+(String)date.month()+"."+(String)date.day(); 
}

String Date2StrFull(DateTime date)
{
  return Date2Str(date)+" "+DayOfWeek(date)+" "+Time2Str(date); 
}



String Time2StrDDMM(DateTime _time,boolean colon)
{
  return Norm2Str(_time.hour())+(colon?":":" ")+Norm2Str(_time.minute());
}

String Time2Str(DateTime _time)
{  
  return Norm2Str(_time.hour())+":"+Norm2Str(_time.minute())+":"+Norm2Str(_time.second());
}

Alarm::Alarm (uint16_t minutes)
{
    _minutes =  minutes;
    mm =  minutes % 60;
    hh =  minutes / 60;
}

Alarm::Alarm (String mm_hh) 
{
   hh = (mm_hh.substring(0,2)).toInt();
   mm = (mm_hh.substring(3,5)).toInt();
   _minutes =  hh*60+mm;    
}

String Alarm::ToStr () 
{
   return Norm2Str(hh)+":"+Norm2Str(mm);
}