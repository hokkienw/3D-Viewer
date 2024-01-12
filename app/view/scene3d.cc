#include "scene3d.h"

Scene3D::Scene3D(QWidget* parent) : QOpenGLWidget(parent) { preSettings(); }

Scene3D::~Scene3D() {}

void Scene3D::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glLoadIdentity();
}

void Scene3D::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void Scene3D::paintGL() {
  setProjection();
  glClearColor(color_background1, color_background2, color_background3, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glRotatef(x_rot, 1, 0, 0);
  glRotatef(y_rot, 0, 1, 0);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0, object.get_data());
  if (renderer_) {
    if (line_type != 2) {
      renderer_->drawLines(*this);
    }
    if (vertex_type != 2) {
      renderer_->drawPoints(*this);
    }
  }
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Scene3D::clearRender() {
  if (object.get_vertex_count()) {
    object = s21::Data();
    update();
  }
}

void Scene3D::mousePressEvent(QMouseEvent* mo) { mouse_pos = mo->pos(); }

void Scene3D::mouseMoveEvent(QMouseEvent* mo) {
  x_rot = 1 / M_PI * (mo->pos().y() - mouse_pos.y());
  y_rot = 1 / M_PI * (mo->pos().x() - mouse_pos.x());
  update();
}

void Scene3D::setProjection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  double drawRange = object.get_max() * 2;
  if (projection_type == 0) {
    glOrtho(-drawRange, drawRange, -drawRange, drawRange, -drawRange,
            drawRange * 5);
  } else {
    float fov = 60.0 * M_PI / 180;
    float heapHeight = drawRange / (2 * tan(fov / 2));
    glFrustum(-drawRange, drawRange, -drawRange, drawRange, heapHeight,
              drawRange * 5);
    glTranslated(0, 0, -heapHeight * 3);
  }
}

void Scene3D::preSettings() {
  x_rot = 0;
  y_rot = 0;
  z_rot = 0;
  color_background1 = 0.2;
  color_background2 = 0.2;
  color_background3 = 0.2;
  color_line1 = 1.0;
  color_line2 = 0;
  color_line3 = 0;
  color_point1 = 0.5;
  color_point2 = 0;
  color_point3 = 0.5;
  line_type = 0;
  vertex_type = 0;
  projection_type = 0;
  size_line = 1;
  size_point = 1;
  file_open = 0;
}