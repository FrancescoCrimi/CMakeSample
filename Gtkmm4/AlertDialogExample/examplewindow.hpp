#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  ~ExampleWindow() override;

protected:
  //Signal handlers:
  void on_button_info_clicked();
  void on_button_question_clicked();
  void on_question_dialog_finish(const Glib::RefPtr<Gio::AsyncResult>& result);

  //Child widgets:
  Gtk::Box m_ButtonBox;
  Gtk::Button m_Button_Info;
  Gtk::Button m_Button_Question;

  Glib::RefPtr<Gtk::AlertDialog> m_pDialog;
};

#endif //GTKMM_EXAMPLEWINDOW_H