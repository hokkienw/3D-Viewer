#include "transform.h"

namespace s21 {

void Transform::RotateX(double x, s21::Data &object) {
  for (auto i = 0; i < object.get_vertixes().size(); i += 3) {
    double buffer = cos(x * M_PI / 180) * object.get_vertixes()[i + 1] -
                    sin(x * M_PI / 180) * object.get_vertixes()[i + 2];
    object.set_vertixes(i + 2,
                        sin(x * M_PI / 180) * object.get_vertixes()[i + 1] +
                            cos(x * M_PI / 180) * object.get_vertixes()[i + 2]);
    object.set_vertixes(i + 1, buffer);
  }
}

void Transform::RotateY(double y, s21::Data &object) {
  for (auto i = 0; i < object.get_vertixes().size(); i += 3) {
    double buffer = cos(y * M_PI / 180) * object.get_vertixes()[i] +
                    sin(y * M_PI / 180) * object.get_vertixes()[i + 2];
    object.set_vertixes(i + 2,
                        -sin(y * M_PI / 180) * object.get_vertixes()[i] +
                            cos(y * M_PI / 180) * object.get_vertixes()[i + 2]);
    object.set_vertixes(i, buffer);
  }
}

void Transform::RotateZ(double z, s21::Data &object) {
  for (auto i = 0; i < object.get_vertixes().size(); i += 3) {
    double buffer = cos(z * M_PI / 180) * object.get_vertixes()[i] -
                    sin(z * M_PI / 180) * object.get_vertixes()[i + 1];
    object.set_vertixes(i + 1,
                        sin(z * M_PI / 180) * object.get_vertixes()[i] +
                            cos(z * M_PI / 180) * object.get_vertixes()[i + 1]);
    object.set_vertixes(i, buffer);
  }
}

void Transform::Scale(double scale, s21::Data &object) {
  for (auto i = 0; i < object.get_vertixes().size(); ++i) {
    object.set_vertixes(i, object.get_vertixes()[i] * scale);
  }
}

void Transform::TranslateX(double x, s21::Data &object) {
  for (auto i = 0; i < object.get_vertixes().size(); i += 3) {
    object.set_vertixes(i, object.get_vertixes()[i] + x);
  }
}

void Transform::TranslateY(double y, s21::Data &object) {
  for (auto i = 0; i < object.get_vertixes().size(); i += 3) {
    object.set_vertixes(i + 1, object.get_vertixes()[i + 1] + y);
  }
}

void Transform::TranslateZ(double z, s21::Data &object) {
  for (auto i = 0; i < object.get_vertixes().size(); i += 3) {
    object.set_vertixes(i + 2, object.get_vertixes()[i + 2] + z);
  }
}

}  // namespace s21
