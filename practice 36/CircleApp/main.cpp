#include <iostream>
#include <QApplication>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>

class ColorfulCircle : public QWidget
{
Q_OBJECT
public:
	explicit ColorfulCircle(QWidget* parent = nullptr) : QWidget(parent)
	{
		_label = new QLabel(this);
		setGeometry(0, 0, 1000, 1000);
		_label->setFixedSize(1000, 1000);
		_label->setAlignment(Qt::AlignCenter);
		updateColor(0);
	}

	~ColorfulCircle() override
	{
		delete _label;
	}

	QSize minimumSizeHint() const override
	{
		return {100, 100};
	}

public slots:

	void updateColor(int value)
	{
		if (value < 33)
		{
			_label->setPixmap(_green);
		} else if (value < 66)
		{
			_label->setPixmap(_yellow);
		} else
		{
			_label->setPixmap(_red);
		}
		update();
	}

private:
	QPixmap _yellow = QPixmap(":/resources/yellow.png");
	QPixmap _green = QPixmap(":/resources/green.png");
	QPixmap _red = QPixmap(":/resources/red.png");
	QLabel* _label;
};

class MainWindow : public QWidget
{
Q_OBJECT
public:
	explicit MainWindow(QWidget* parent = nullptr) : QWidget(parent)
	{
		setFixedSize(1040, 1040);
		move(1000, 500);
		_layout = new QVBoxLayout(this);
		_circle = new ColorfulCircle(this);
		_slider = new QSlider(Qt::Horizontal, this);

		_slider->setMinimum(0);
		_slider->setMaximum(100);

		_layout->addWidget(_circle);
		_layout->addWidget(_slider);

		connect(_slider, &QSlider::valueChanged, _circle, &ColorfulCircle::updateColor);

		_circle->updateColor(_slider->value());
	}

	~MainWindow() override
	{
		delete _circle;
		delete _layout;
		delete _slider;
	}

private:
	QLayout* _layout;
	ColorfulCircle* _circle;
	QSlider* _slider;
};


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	MainWindow mainWindow;

	mainWindow.show();
	QApplication::exec();

	return 0;
}

#include <main.moc>

