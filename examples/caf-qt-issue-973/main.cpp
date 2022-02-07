#include "caf/all.hpp"
#include "caf/io/all.hpp"

CAF_PUSH_WARNINGS
#include <QApplication>
CAF_POP_WARNINGS

#include "main_window.hpp"

int caf_main(caf::actor_system& sys, const caf::actor_system_config& cfg) {
  auto [argc, argv] = cfg.c_args_remainder();
  QApplication app{argc, argv};
  app.setQuitOnLastWindowClosed(true);
  MainWindow mw;
  mw.init(sys);
  mw.show();

  caf::scoped_actor self(sys);
  self->delayed_send(mw.as_actor(), std::chrono::milliseconds(1000), caf::get_atom_v);
  // Issue 973 (seems to be Ok)
  self->delayed_send(mw.as_actor(), std::chrono::milliseconds(1000), caf::timeout_atom_v);
  // 
  self->delayed_send(mw.as_actor(), std::chrono::milliseconds(1000), set_name_atom_v);

  return app.exec();
}

// Required
//CAF_MAIN(caf::id_block::qtsupport, caf::io::middleman)

// Broken without both arguments
CAF_MAIN(caf::io::middleman)
