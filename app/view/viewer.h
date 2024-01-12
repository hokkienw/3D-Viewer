#ifndef _3DVIEWER_V2_SRC_APP_VIEW_MAINWINDOW_H_
#define _3DVIEWER_V2_SRC_APP_VIEW_MAINWINDOW_H_

#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QGlobalStatic>
#include <QMainWindow>
#include <QSettings>
#include <QTimer>

#include "../controller/controller.h"
#include "qgifimage.h"
#include "scene3d.h"
#include "singltone_scene_renderer_manager.h"
#include "strategy_renderer.h"
#include "strategy_wired_renderer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Viewer;
}
QT_END_NAMESPACE

class Viewer : public QMainWindow {
  Q_OBJECT

 public:
  Viewer(s21::Controller *controller, s21::SceneRendererManager *manager,
         QWidget *parent = nullptr);
  ~Viewer();

 public slots:
  auto SaveFrame() -> void;

  auto SaveGif() -> void;

  auto on_pushButton_4_released() -> void;

 private slots:
  void on_pushButton_2_clicked();
  void on_scale_valueChanged(double arg1);
  void on_x_position_valueChanged(double arg1);
  void on_y_position_valueChanged(double arg1);
  void on_z_position_valueChanged(double arg1);
  void on_x_angle_valueChanged(double arg1);
  void on_y_angle_valueChanged(double arg1);
  void on_z_angle_valueChanged(double arg1);

  void saveSettings();
  void loadSettings();
  void ParseData();

  void on_line_width_valueChanged(double arg1);
  void on_scale_3_valueChanged(double arg1);
  void on_pushButton_3_released();

  void on_lines_color_clicked();
  void on_vertex_color_clicked();
  void on_background_color_clicked();
  void on_projection_type_activated(int index);
  void on_line_type_activated(int index);
  void on_vertex_type_activated(int index);

 private:
  Ui::Viewer *ui_;
  QSettings *settings_;
  s21::Controller *controller_;
  QGifImage *gif_ = nullptr;
  QTimer *timer_ = nullptr;
  unsigned int frame_counter_ = 0;
  int error_ = 0;
};

#endif  // _3DVIEWER_V2_SRC_APP_VIEW_MAINWINDOW_H_
