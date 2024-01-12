#ifndef _3DVIEWER_V2_SRC_APP_CONTROLLER_CONTROLLER_H_
#define _3DVIEWER_V2_SRC_APP_CONTROLLER_CONTROLLER_H_

#include "../model/data.h"
#include "../model/facade.h"

namespace s21 {

class Controller {
 public:
  explicit Controller(Facade *m) : model_(m) {}
  void ParceFile(std::string &filename, s21::Data &object, int &error);
  void Scale(s21::Data &object, double scale);
  void Rotate(s21::Data &object, double x, double y, double z);
  void Translate(s21::Data &object, double x, double y, double z);

 private:
  s21::Facade *model_;
};

}  // namespace s21

#endif  // _3DVIEWER_V2_SRC_APP_CONTROLLER_CONTROLLER_H_
