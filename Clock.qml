import QtQuick 2.7

ClockForm {

    //var str=(new Date).toLocaleDateString();
  date:  clock.now.toLocaleDateString(Qt.locale(), "d MMM yyyy")

  time: clock.now.toLocaleTimeString(Qt.locale(), "HH:mm")
  day: clock.now.toLocaleDateString(Qt.locale(), "dddd")

  //timeText.text = Qt.formatTime(new Date(),"hh:mm")

  /*
  date: clock.now.toLocaleDateString(Qt.LocalDate, "d MMM yyyy")
  time: clock.now.toLocaleTimeString(Qt.LocalTime, "HH:mm")
  day: clock.now.toLocaleDateString(Qt.LocaleDate, "dddd")
  */
}
