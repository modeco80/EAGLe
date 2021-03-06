#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QThread>

#include <ssxtools/Core.h>
#define INQT
#include <ssxtools/shps/ShpsReader.h>
#include <ssxtools/shps/ShpsConverter.h>
#undef INQT

#include "ui_MainWindow.h"
#include "ShapeWidget.h"

namespace ssxtools::ui {

		//using namespace ssxtools::shps;

		class MainWindow : public QMainWindow {
			Q_OBJECT

		   public:
			MainWindow(QWidget* parent = nullptr);

			~MainWindow();

			void EnableNag();
			void DisableNag();

		   private slots:
			void OnOpenSSH();

			//public slots:
			void OnSSHItemSelection(const QItemSelection& /*newSelection*/, const QItemSelection& /*oldSelection*/);

		   private:
			Ui::MainWindow ui;
			QStandardItemModel* item_model;

			// TODO: Refactor!!!!
			std::vector<shps::Image> images;
			shps::ShpsConverter writer;

			// It feels really nasty writing this out like this, but I suppose it's fine?
			ShapeWidget* shape_widget_{nullptr};

			bool nag_enabled = true;
		};

	} // namespace ssxtools