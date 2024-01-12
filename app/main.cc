#include <GLUT/glut.h>

#include <QApplication>

#include "view/viewer.h"

int main(int argc, char *argv[]) {
  s21::Facade model;
  s21::Controller controller(&model);
  QApplication a(argc, argv);
  s21::WiredRenderer wiredRenderer;
  s21::SceneRendererManager* manager = s21::SceneRendererManager::getInstance();
  manager->setRenderer(&wiredRenderer);
  Viewer w(&controller, manager);
  w.show();
  w.setWindowTitle("3DViewer_v2.0");
  w.setFixedSize(881, 720);
  return a.exec();
}
