#ifndef _3DVIEWER_V2_SRC_APP_VIEW_RENDERER_H_
#define _3DVIEWER_V2_SRC_APP_VIEW_RENDERER_H_

class Scene3D;  // это объявление класса, перед его фактическим
                // определением
namespace s21 {

class Renderer {
 public:
  Renderer() = default;
  virtual ~Renderer() = default;
  virtual void drawLines(Scene3D& scene) = 0;
  virtual void drawPoints(Scene3D& scene) = 0;
};

}  // namespace s21

#endif  // _3DVIEWER_V2_SRC_APP_VIEW_RENDERER_H_
