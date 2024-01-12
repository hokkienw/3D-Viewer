#ifndef _3DVIEWER_V2_SRC_APP_MODEL_FACADE_H_
#define _3DVIEWER_V2_SRC_APP_MODEL_FACADE_H_

#include "data.h"
#include "parcer.h"
#include "transform.h"

namespace s21 {

class Facade {
 public:
  Facade() : parce_(new Parcer()), transform_(new Transform()) {}
  ~Facade() {
    delete parce_;
    delete transform_;
  }
  void ParceFileFacade(std::string &filename, s21::Data &object, int &error);
  void RotateFacade(double x, double y, double z, s21::Data &object);
  void ScaleFacade(double scale, s21::Data &object);
  void TranslateFacade(double x, double y, double z, s21::Data &object);

 private:
  Parcer *parce_;
  Transform *transform_;
};

}  // namespace s21

#endif  // _3DVIEWER_V2_SRC_APP_MODEL_FACADE_H_
