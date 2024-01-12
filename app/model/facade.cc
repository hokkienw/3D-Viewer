#include "facade.h"

namespace s21 {

void Facade::ParceFileFacade(std::string& filename, s21::Data& object,
                             int& error) {
  error = 0;
  try {
    parce_->ReadData(filename, object);
  } catch (const std::exception& e) {
    error = 1;
  }
}

void Facade::RotateFacade(double x, double y, double z, s21::Data& object) {
  if (x != 0) {
    transform_->RotateX(x, object);
  } else if (y != 0) {
    transform_->RotateY(y, object);
  } else if (z != 0) {
    transform_->RotateZ(z, object);
  }
}

void Facade::ScaleFacade(double scale, s21::Data& object) {
  transform_->Scale(scale, object);
}

void Facade::TranslateFacade(double x, double y, double z, s21::Data& object) {
  if (x != 0) {
    transform_->TranslateX(x, object);
  } else if (y != 0) {
    transform_->TranslateY(y, object);
  } else if (z != 0) {
    transform_->TranslateZ(z, object);
  }
}

}  // namespace s21
