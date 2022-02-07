#pragma once

#include <iostream>

#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include "caf/mixin/actor_widget.hpp"

CAF_PUSH_WARNINGS
#include <QMainWindow>
CAF_POP_WARNINGS

CAF_BEGIN_TYPE_ID_BLOCK(qtsupport, first_custom_type_id)

  CAF_ADD_ATOM(qtsupport, set_name_atom)
  CAF_ADD_ATOM(qtsupport, quit_atom)

CAF_END_TYPE_ID_BLOCK(qtsupport)

class MainWindow : public caf::mixin::actor_widget<QMainWindow> {
  Q_OBJECT
 public:
  using super = caf::mixin::actor_widget<QMainWindow>;

  explicit MainWindow(QWidget *parent = nullptr);

  void init(caf::actor_system& system);
};
