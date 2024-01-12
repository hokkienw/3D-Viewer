#ifndef _3DVIEWER_V2_SRC_APP_MODEL_TRANSFORMER_H_
#define _3DVIEWER_V2_SRC_APP_MODEL_TRANSFORMER_H_

#include <cmath>
#include <vector>

#include "data.h"

namespace s21 {

class Transform {
 public:
  Transform() = default;
  ~Transform() = default;
  void RotateX(double x, s21::Data &object);
  void RotateY(double y, s21::Data &object);
  void RotateZ(double z, s21::Data &object);
  void Scale(double scale, s21::Data &object);
  void TranslateX(double x, s21::Data &object);
  void TranslateY(double y, s21::Data &object);
  void TranslateZ(double z, s21::Data &object);
};

}  // namespace s21

#endif  // _3DVIEWER_V2_SRC_APP_MODEL_TRANSFORMER_H_
