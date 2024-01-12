#ifndef _3DVIEWER_V2_SRC_APP_VIEW_WIRED_RENDERER_H
#define _3DVIEWER_V2_SRC_APP_VIEW_WIRED_RENDERER_H

#include <QopenGLWidget>

#include "scene3d.h"
#include "strategy_renderer.h"

namespace s21 {

class WiredRenderer : public Renderer {
 public:
  void drawLines(Scene3D& scene) override;
  void drawPoints(Scene3D& scene) override;
};

}  // namespace s21

#endif  // _3DVIEWER_V2_SRC_APP_VIEW_WIRED_RENDERER_H_
