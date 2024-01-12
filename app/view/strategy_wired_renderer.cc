#include "strategy_wired_renderer.h"

namespace s21 {

void WiredRenderer::drawLines(Scene3D& scene) {
  glColor3d(scene.color_line1, scene.color_line2, scene.color_line3);
  glLineWidth(scene.size_line);
  if (scene.line_type == 1) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00ff);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  glDrawElements(GL_LINES, scene.object.get_indices().size(), GL_UNSIGNED_INT,
                 scene.object.get_indices().data());
}

void WiredRenderer::drawPoints(Scene3D& scene) {
  glPointSize(scene.size_point);
  glColor3d(scene.color_point1, scene.color_point2, scene.color_point3);
  if (scene.vertex_type == 1) {
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  } else {
    glDisable(GL_POINT_SMOOTH);
    glDisable(GL_BLEND);
  }
  glDrawArrays(GL_POINTS, 0, scene.object.get_vertex_count());
}

}  // namespace s21
