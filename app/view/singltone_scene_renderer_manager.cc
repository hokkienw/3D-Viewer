#include "singltone_scene_renderer_manager.h"

namespace s21 {

SceneRendererManager* SceneRendererManager::instance_ = nullptr;

SceneRendererManager::SceneRendererManager() { renderer_ = nullptr; }

SceneRendererManager::~SceneRendererManager() { delete instance_; }

SceneRendererManager* SceneRendererManager::getInstance() {
  if (!instance_) {
    instance_ = new SceneRendererManager();
  }
  return instance_;
}

}  // namespace s21
