#ifndef _3DVIEWER_V2_SRC_APP_VIEW_SINGLTONE_H_
#define _3DVIEWER_V2_SRC_APP_VIEW_SINGLTONE_H_

#include "strategy_renderer.h"

class Scene3D;

namespace s21 {

class SceneRendererManager {
 public:
  static SceneRendererManager* getInstance();
  void setRenderer(Renderer* renderer) { renderer_ = renderer; }
  Renderer* getRenderer() { return renderer_; }

 protected:
  SceneRendererManager();
  ~SceneRendererManager();

 private:
  static SceneRendererManager* instance_;
  Renderer* renderer_;
};

}  // namespace s21

#endif  // _3DVIEWER_V2_SRC_APP_VIEW_SINGLTONE_H_
