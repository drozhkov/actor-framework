#include "main_window.hpp"

MainWindow::MainWindow(QWidget *parent) : super(parent) {
  std::cout<<"MainWindow constructor"<<std::endl;
}

void MainWindow::init(caf::actor_system& system) {
  // Initialize actor mix-in
  super::init(system);

  // Set message handler
  set_message_handler([=](caf::actor_companion* self) -> caf::message_handler {
    return {
      [=](caf::get_atom) {
        std::cout<<"Hello world"<<std::endl;
      },
      [=](set_name_atom) {
        std::cout<<"Broken if caf_main isn't perfect"<<std::endl;
      }
    };
  });
}