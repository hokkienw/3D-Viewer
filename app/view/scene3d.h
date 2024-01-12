#ifndef _3DVIEWER_V2_SRC_APP_VIEW_OPENGL_H_
#define _3DVIEWER_V2_SRC_APP_VIEW_OPENGL_H_

#include <QMouseEvent>
#include <QOpenGLWidget>

#include "model/data.h"
#include "strategy_renderer.h"

class Scene3D : public QOpenGLWidget {
  Q_OBJECT

 public:
  Scene3D(QWidget *parent = nullptr);
  ~Scene3D();

  s21::Data object{};
  float x_rot{}, y_rot{}, z_rot{};
  int file_open{};
  QPoint mouse_pos{};
  float x_pos{}, y_pos{}, z_pos{};
  float scale{};
  double color_point1{}, color_point2{}, color_point3{};
  double color_line1{}, color_line2{}, color_line3{};
  double size_line{}, size_point{};
  double color_background1{}, color_background2{}, color_background3{};
  int projection_type{}, line_type{}, vertex_type{};

  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void clearRender();
  void setRenderer(s21::Renderer *r) { renderer_ = r; }

 protected:
  void mousePressEvent(QMouseEvent *mo) override;
  void mouseMoveEvent(QMouseEvent *mo) override;

 private:
  s21::Renderer *renderer_;
  void setProjection();
  void preSettings();
};

#endif  // _3DVIEWER_V2_SRC_APP_VIEW_OPENGL_H_
