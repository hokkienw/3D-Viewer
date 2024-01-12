#include "controller.h"

#include "../model/facade.h"

namespace s21 {

void Controller::ParceFile(std::string& filename, s21::Data& object,
                           int& error) {
  model_->ParceFileFacade(filename, object, error);
}
void Controller::Scale(s21::Data& object, double scale) {
  model_->ScaleFacade(scale, object);
}
void Controller::Rotate(s21::Data& object, double x, double y, double z) {
  model_->RotateFacade(x, y, z, object);
}
void Controller::Translate(s21::Data& object, double x, double y, double z) {
  model_->TranslateFacade(x, y, z, object);
}

}  // namespace s21
