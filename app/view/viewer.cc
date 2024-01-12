#include "viewer.h"

#include "ui_viewer.h"

static const QString pathToApplicationLocation = QDir::homePath();

Viewer::Viewer(s21::Controller *controller, s21::SceneRendererManager *manager,
               QWidget *parent)
    : QMainWindow(parent),
      timer_(new QTimer(0)),
      ui_(new Ui::Viewer),
      controller_(controller) {
  ui_->setupUi(this);

  settings_ = new QSettings("s21", "3DViewer_hokkienw", this);
  loadSettings();
  ui_->openGLWidget->setRenderer(manager->getRenderer());
}

Viewer::~Viewer() {
  saveSettings();
  if (gif_) {
    delete gif_;
  }
  delete timer_;
  delete settings_;
  delete ui_;
}

void Viewer::on_pushButton_2_clicked() {
  ParseData();
  if (ui_->openGLWidget->file_open == 1 && !error_) {
    ui_->label_5->setText(
        "Кол-во вершин: " +
        QString::number(ui_->openGLWidget->object.get_vertex_count()));
    ui_->label_15->setText(
        "Кол-во граней: " +
        QString::number((ui_->openGLWidget->object.get_indices().size() / 2)));
    ui_->openGLWidget->initializeGL();
    ui_->openGLWidget->update();
  }
}

void Viewer::on_scale_valueChanged(double arg1) {
  if (ui_->openGLWidget->file_open == 1) {
    controller_->Scale(ui_->openGLWidget->object, arg1);
    ui_->openGLWidget->update();
  }
}

void Viewer::on_x_position_valueChanged(double arg1) {
  if (ui_->openGLWidget->file_open == 1) {
    controller_->Translate(ui_->openGLWidget->object, arg1, 0, 0);
    ui_->openGLWidget->update();
  }
}

void Viewer::on_y_position_valueChanged(double arg1) {
  if (ui_->openGLWidget->file_open == 1) {
    controller_->Translate(ui_->openGLWidget->object, 0, arg1, 0);
    ui_->openGLWidget->update();
  }
}

void Viewer::on_z_position_valueChanged(double arg1) {
  if (ui_->openGLWidget->file_open == 1) {
    controller_->Translate(ui_->openGLWidget->object, 0, 0, arg1);
    ui_->openGLWidget->update();
  }
}

void Viewer::on_x_angle_valueChanged(double arg1) {
  if (ui_->openGLWidget->file_open == 1) {
    controller_->Rotate(ui_->openGLWidget->object, arg1, 0, 0);
    ui_->openGLWidget->update();
  }
}

void Viewer::on_y_angle_valueChanged(double arg1) {
  if (ui_->openGLWidget->file_open == 1) {
    controller_->Rotate(ui_->openGLWidget->object, 0, arg1, 0);
    ui_->openGLWidget->update();
  }
}

void Viewer::on_z_angle_valueChanged(double arg1) {
  if (ui_->openGLWidget->file_open == 1) {
    controller_->Rotate(ui_->openGLWidget->object, 0, 0, arg1);
    ui_->openGLWidget->update();
  }
}

void Viewer::saveSettings() {
  settings_->setValue("projection_type", ui_->openGLWidget->projection_type);
  settings_->setValue("line_red", ui_->openGLWidget->color_line1);
  settings_->setValue("line_green", ui_->openGLWidget->color_line2);
  settings_->setValue("line_blue", ui_->openGLWidget->color_line3);
  settings_->setValue("line_type", ui_->openGLWidget->line_type);
  settings_->setValue("line_width", ui_->openGLWidget->size_line);
  settings_->setValue("point_size", ui_->openGLWidget->size_point);
  settings_->setValue("point_red", ui_->openGLWidget->color_point1);
  settings_->setValue("point_green", ui_->openGLWidget->color_point2);
  settings_->setValue("point_blue", ui_->openGLWidget->color_point3);
  settings_->setValue("background_red", ui_->openGLWidget->color_background1);
  settings_->setValue("background_green", ui_->openGLWidget->color_background2);
  settings_->setValue("background_blue", ui_->openGLWidget->color_background3);
  settings_->setValue("vertex_type", ui_->openGLWidget->vertex_type);
}

void Viewer::loadSettings() {
  ui_->openGLWidget->projection_type =
      settings_->value("projection_type", 0).toInt();
  ui_->projection_type->setCurrentIndex(ui_->openGLWidget->projection_type);
  ui_->openGLWidget->color_line1 = settings_->value("line_red", 1).toInt();
  ui_->openGLWidget->color_line2 = settings_->value("line_green", 1).toInt();
  ui_->openGLWidget->color_line3 = settings_->value("line_blue", 1).toInt();
  ui_->openGLWidget->line_type = settings_->value("line_type", 0).toInt();
  ui_->line_type->setCurrentIndex(ui_->openGLWidget->line_type);
  ui_->openGLWidget->size_point = settings_->value("point_size", 0).toDouble();
  ui_->openGLWidget->size_line = settings_->value("line_width", 0).toDouble();
  ui_->scale_3->setValue(settings_->value("point_size", 0).toDouble());
  ui_->line_width->setValue(settings_->value("line_width", 0).toDouble());
  ui_->openGLWidget->color_point1 = settings_->value("point_red", 1).toInt();
  ui_->openGLWidget->color_point2 = settings_->value("point_green", 1).toInt();
  ui_->openGLWidget->color_point3 = settings_->value("point_blue", 1).toInt();
  ui_->openGLWidget->color_background1 =
      settings_->value("background_red", 1).toInt();
  ui_->openGLWidget->color_background2 =
      settings_->value("background_green", 1).toInt();
  ui_->openGLWidget->color_background3 =
      settings_->value("background_blue", 1).toInt();
  ui_->openGLWidget->vertex_type = settings_->value("vertex_type", 0).toInt();
  ui_->vertex_type->setCurrentIndex(ui_->openGLWidget->vertex_type);
}

void Viewer::on_line_width_valueChanged(double arg1) {
  if (ui_->openGLWidget->file_open == 1) {
    ui_->openGLWidget->size_line = arg1;
    ui_->openGLWidget->update();
  }
}

void Viewer::on_scale_3_valueChanged(double arg1) {
  if (ui_->openGLWidget->file_open == 1) {
    ui_->openGLWidget->size_point = arg1;
    ui_->openGLWidget->update();
  }
}

void Viewer::on_pushButton_3_released() {
  QString file = QFileDialog::getSaveFileName(this, "Save as...", "name.bmp",
                                              "BMP (*.bmp);; JPEG (*.jpeg)");
  ui_->openGLWidget->grabFramebuffer().save(file, NULL, 100);
}

auto Viewer::on_pushButton_4_released() -> void {
  if (gif_) {
    delete gif_;
  }
  gif_ = new QGifImage;
  gif_->setDefaultDelay(100);
  frame_counter_ = 0;
  connect(timer_, &QTimer::timeout, this, &Viewer::SaveFrame);
  timer_->start(100);
}

void Viewer::SaveFrame() {
  if (frame_counter_ < 50) {
    QImage frame = ui_->openGLWidget->grabFramebuffer().scaled(
        640, 480, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    gif_->addFrame(frame);
    ++frame_counter_;
  } else {
    timer_->stop();
    disconnect(timer_, &QTimer::timeout, this, &Viewer::SaveFrame);
    SaveGif();
  }
}
auto Viewer::SaveGif() -> void {
  QString save_path = QFileDialog::getSaveFileName(
      this, NULL, pathToApplicationLocation, "GIF (*.gif)", 0,
      QFileDialog::DontUseNativeDialog);
  if (!save_path.isEmpty()) {
    gif_->save(save_path);
  }
}

void Viewer::ParseData() {
  QString filestr = QFileDialog::getOpenFileName(
      this, nullptr, pathToApplicationLocation, "OBJ (*.obj)", 0,
      QFileDialog::DontUseNativeDialog);
  if (!(filestr.isEmpty())) {
    ui_->openGLWidget->file_open = 1;
    ui_->label->setText(filestr);
    std::string filename_str = filestr.toStdString();
    controller_->ParceFile(filename_str, ui_->openGLWidget->object, error_);
  }
}

void Viewer::on_lines_color_clicked() {
  if (ui_->openGLWidget->file_open == 1) {
    QColor color_value =
        QColorDialog::getColor(Qt::white, this, tr("Select Color"));
    ui_->openGLWidget->color_line1 = color_value.red() / 255.0f;
    ui_->openGLWidget->color_line2 = color_value.green() / 255.0f;
    ui_->openGLWidget->color_line3 = color_value.blue() / 255.0f;
    ui_->openGLWidget->update();
  }
}

void Viewer::on_vertex_color_clicked() {
  if (ui_->openGLWidget->file_open == 1) {
    QColor color_value =
        QColorDialog::getColor(Qt::white, this, tr("Select Color"));
    ui_->openGLWidget->color_point1 = color_value.red() / 255.0f;
    ui_->openGLWidget->color_point2 = color_value.green() / 255.0f;
    ui_->openGLWidget->color_point3 = color_value.blue() / 255.0f;
    ui_->openGLWidget->update();
  }
}

void Viewer::on_background_color_clicked() {
  if (ui_->openGLWidget->file_open == 1) {
    QColor color_value =
        QColorDialog::getColor(Qt::white, this, tr("Select Color"));
    ui_->openGLWidget->color_background1 = color_value.red() / 255.0f;
    ui_->openGLWidget->color_background2 = color_value.green() / 255.0f;
    ui_->openGLWidget->color_background3 = color_value.blue() / 255.0f;
    ui_->openGLWidget->update();
  }
}

void Viewer::on_projection_type_activated(int index) {
  if (ui_->openGLWidget->file_open == 1) {
    ui_->openGLWidget->projection_type = index;
    ui_->openGLWidget->update();
  }
}

void Viewer::on_line_type_activated(int index) {
  if (ui_->openGLWidget->file_open == 1) {
    ui_->openGLWidget->line_type = index;
    ui_->openGLWidget->update();
  }
}

void Viewer::on_vertex_type_activated(int index) {
  if (ui_->openGLWidget->file_open == 1) {
    ui_->openGLWidget->vertex_type = index;
    ui_->openGLWidget->update();
  }
}
